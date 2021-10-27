/*********************************/
/* Author   :   Spectrum         */
/* Date     :   17 Oct 2021      */
/* Version  :   V01              */
/*********************************/

#include "Ultrasonic.h"
#include "../06-ICU/ICU.h"
#include "../GPIO/GPIO.h"
#include "../LCD/LCD.h"
#include "avr/delay.h"

static u8 edge = 0, time= 0;
static u16 distance;

/*The CallBack function*/
static void Ultrasonic_edgeProcessing(void)
{
	++edge;
	if(edge == 1)
	{
		ICU_clearTimer();
		ICU_setEdgeDetection(FALLING);
	}
	else if(edge == 2)
	{
		time = ICU_getInputCapture();
		ICU_setEdgeDetection(RISING);
	}

}

/*Function that triggers pin*/
static void Ultrasonic_Trigger(void)
{
	/*Set trigger pin to high and wait 10 us then set it to low*/
	GPIO_writePin(Trigger_Port, Trigger_Pin, High);
	_delay_us(10);
	GPIO_writePin(Trigger_Port, Trigger_Pin, Low);
}

/*Init the Ultrasonic by initializing the ICU*/
void Ultrasonic_Init(void)
{
	/*Init the ICU by Setting Clock to FCPU/8 and set edge detection to be rising*/
	ICU_Config config = {F_CPU_8, RISING};

	/*Set Trigger pin as output*/
	GPIO_setPinDirection(Trigger_Port, Trigger_Pin, OUTPUT);

	/*Init the ICU*/
	ICU_Init(&config);

	/*Set the CallBack function */
	ICU_setCallBack(Ultrasonic_edgeProcessing);
}

/*Function that continously read distance which
 * it measures time then calculate distance*/
u16 Ultrasonic_readDistance(void)
{
	/*Clear all variables in order not to affect measurements from previous values*/
	distance = 0;
	edge = 0;
	time= 0;

	/*Clear ICU Timer value*/
	ICU_clearTimer();
	/*Trigger a pulse to let ultrasonic make echo*/
	Ultrasonic_Trigger();

	/*Wait for measuring time from a rising edge*/
	while(edge != NO_EDGES);

	/*Calculating distance and return the value*/
	distance = time/58;
	return distance;
}
