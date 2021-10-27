/*********************************/
/* Author   :   Spectrum         */
/* Date     :   17 Oct 2021      */
/* Version  :   V03              */
/*********************************/

#include "Ultrasonic/Ultrasonic.h"
#include "LCD/LCD.h"
#include "avr/interrupt.h"


int main()
{
	/*Define Variable that will contain the value returned by the
	 * Ultrasonic_readDistance function*/
	u16 dist;

	/*Set the global Interrupt*/
	SREG |= (1<<7);

	/*Initialize the LCD to power on */
	LCD_init();

	/*Initialize the Ultrasonic to read distance*/
	Ultrasonic_Init();

	/*Display string*/
	LCD_Displaystring("Distance= ");

	/*Function the reads the distance and return the value to the distance variable*/
	dist = Ultrasonic_readDistance();

	/*Display the value on the LCD*/
	LCD_MoveCursor(0,10);
	LCD_Int_to_Str(dist);

	while(1)
	{

	}

	return 0;
}
