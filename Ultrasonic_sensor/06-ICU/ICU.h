/*********************************/
/* Author   :   Spectrum         */
/* Date     :   20 Sep 2021      */
/* Version  :   V01              */
/*********************************/

#ifndef ICU_H_
#define ICU_H_

#include "../Common/STD_Types.h"
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_1,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_Clock;

typedef enum
{
	FALLING,RISING
}ICU_Edge;

typedef struct
{
	ICU_Clock clock;
	ICU_Edge edge;
}ICU_Config;



 /*  initialize the ICU driver
 * Set the required clock.
 * Set the required edge detection.
 * Enable the Input Capture Interrupt.
 * Initialize Timer1 Registers	*/

void ICU_Init(const ICU_Config * Config_Ptr);

/* set the Call Back function address.*/
void ICU_setCallBack(void(*PtrToFunction)(void));

/* set the required edge detection.*/
void ICU_setEdgeDetection(const ICU_Edge edgeType);

/*Get the Timer1 Value when the input is captured and store value in ICR1*/
u16 ICU_getInputCapture(void);

/* Description: Function to clear the Timer1 Value to start count from ZERO*/
void ICU_clearTimer(void);

/* Description: Function to disable the Timer1 to stop the ICU Driver*/
void ICU_DeInit(void);


#endif /* ICU_H_ */
