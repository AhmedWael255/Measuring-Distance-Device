/*********************************/
/* Author   :   Spectrum         */
/* Date     :   20 Sep 2021      */
/* Version  :   V01              */
/*********************************/

#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

//#include <avr/io.h>

#define TCCR1A		*((volatile unsigned char* const) 0x4F)
#define TCCR1B		*((volatile unsigned char* const) 0x4E)
#define TCNT1H		*((volatile unsigned char* const) 0x4D)
#define TCNT1L		*((volatile unsigned char* const) 0x4C)
#define OCR1AH		*((volatile unsigned char* const) 0x4B)
#define OCR1AL		*((volatile unsigned char* const) 0x4A)
#define OCRLBH		*((volatile unsigned char* const) 0x49)
#define OCR1BL		*((volatile unsigned char* const) 0x48)
#define ICR1H		*((volatile unsigned char* const) 0x47)
#define ICR1L		*((volatile unsigned char* const) 0x46)
#define TIMSK		*((volatile unsigned char* const) 0x59)
#define TIFR		*((volatile unsigned char* const) 0x58)

#define TCNT1   _SFR_IO16(0x2C)
#define ICR1    _SFR_IO16(0x26)


/*TCCR1A PINS*/
#define WGM10		0
#define WGM11		1
#define FOC1B		2
#define	FOC1A		3
#define COM1B0		4
#define COM1B1		5
#define COM1A0		6
#define COM1A1		7

/*TCCR1B PINS*/
#define CS10		0
#define CS11		1
#define CS12		2
#define	WGM12		3
#define WGM13		4
#define ICES1		6
#define ICNC		7

/*TIMSK PINS*/
#define TOIE1		2
#define	OCIE1B		3
#define OCIE1A		4
#define TICIE1		5


/*TIFR PINS*/
#define TOV1		2
#define	OOCF1B		3
#define OOCF1A		4
#define ICF1		5

#endif /* 03_HAL_ICU_ICU_PRIVATE_H_ */
