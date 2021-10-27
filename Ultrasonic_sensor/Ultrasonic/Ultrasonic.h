/*********************************/
/* Author   :   Spectrum         */
/* Date     :   17 Oct 2021      */
/* Version  :   V01              */
/*********************************/

#ifndef ULTRASONIC_ULTRASONIC_H_
#define ULTRASONIC_ULTRASONIC_H_

#include "../Common/STD_Types.h"

/*Macros that define The Trigger Pin and Trigger Port and the number of edges*/
#define NO_EDGES		2
#define Trigger_Port	B
#define Trigger_Pin		5

/*Functions*/
void Ultrasonic_Init(void);
u16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_ULTRASONIC_H_ */
