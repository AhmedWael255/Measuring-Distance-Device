/*********************************/
/* Author   :   Spectrum         */
/* Date     :   20 Sep 2021      */
/* Version  :   V01              */
/*********************************/

#include "../06-ICU/ICU.h"
#include <avr/interrupt.h>
#include "../GPIO/GPIO.h"
#include "../Common/BIT_Math.h"
#include "../Common/STD_Types.h"
#include "../06-ICU/ICU_private.h"


/*ICU_CallBack*/
static volatile void (*ICU_CallBack)(void) = NULL;

/*ISR Function*/
ISR(TIMER1_CAPT_vect)
{
	if(ICU_CallBack != NULL)
	{
		/* if the call back function is not NULL then Call it*/
		(*ICU_CallBack)();
	}
}



void ICU_Init(const ICU_Config * Config_Ptr)
{
	/* Set ICP1/PD6 as Input */
	GPIO_setPinDirection(D, PIN6, INPUT);

	/* Operating in normal mode */
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);

	/*Set the CLock*/
	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->clock);

	/*Set the required edge either RISING of FALLING*/
	TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->edge)<<6);

	/*Set timer to zero*/
	TCNT1 = 0;

	/*Set capture unit to zero*/
	ICR1 = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	SET_Bit(TIMSK, TICIE1);
}

void ICU_setCallBack(void(*PtrToFunction)(void))
{
	/*Set address of the call back function*/
	ICU_CallBack = PtrToFunction;
}

void ICU_setEdgeDetection(const ICU_Edge edgeType)
{
	/*Set the edge required to be captured*/
	TCCR1B = (TCCR1B & 0xBF) | (edgeType<<6);
}

u16 ICU_getInputCapture(void)
{
	return ICR1;
}

void ICU_clearTimer(void)
{
	TCNT1 = 0;
}

void ICU_DeInit(void)
{
	/* Clear All Timer1 Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	/* Disable the Input Capture interrupt */
	CLR_Bit(TIMSK, TICIE1);
}
