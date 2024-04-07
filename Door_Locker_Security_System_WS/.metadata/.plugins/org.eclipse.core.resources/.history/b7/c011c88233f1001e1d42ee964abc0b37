/*******************************************************************************
 * [   Module  ]: ICU Register Modules
 *
 * [ File Name ]: icu_private.h
 *
 * [Description]: Header File for ATmega32 ICU Register.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_ICU_ICU_PRIVATE_H_
#define SRC_MCAL_ICU_ICU_PRIVATE_H_

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* Timer 1 */

/* Definition for TCCR1A (Timer/Counter1 Control Register A) */
#define TCCR1A_REG   	(*(volatile uint8 *)0x4F)
/* Definition for TCCR1B (Timer/Counter1 Control Register B) */
#define TCCR1B_REG   	(*(volatile uint8 *)0x4E)
/* Definition for TCNT1 (Timer/Counter1) */
#define TCNT1_REG    	(*(volatile uint16 *)0x4C)
/* Definition for TCNT1L (Timer/Counter1 Low) */
#define TCNT1L_REG   	(*(volatile uint8 *)0x4C)
/* Definition for TCNT1H (Timer/Counter1 High) */
#define TCNT1H_REG   	(*(volatile uint8 *)0x4D)
/* Definition for OCR1A (Output Compare Register 1 A) */
#define OCR1A_REG   	(*(volatile uint16 *)0x4A)
/* Definition for OCR1AL (Output Compare Register 1 A Low) */
#define OCR1AL_REG   	(*(volatile uint8 *)0x4A)
/* Definition for OCR1AH (Output Compare Register 1 A High) */
#define OCR1AH_REG   	(*(volatile uint8 *)0x4B)
/* Definition for OCR1B (Output Compare Register 1 B) */
#define OCR1B_REG   	(*(volatile uint16 *)0x48)
/* Definition for OCR1BL (Output Compare Register 1 B Low) */
#define OCR1BL_REG   	(*(volatile uint8 *)0x48)
/* Definition for OCR1BH (Output Compare Register 1 B High) */
#define OCR1BH_REG   	(*(volatile uint8 *)0x49)
/* Definition for ICR1 (Input Capture Register) */
#define ICR1_REG   		(*(volatile uint16 *)0x46)
/* Definition for ICR1L (Input Capture Register Low) */
#define ICR1L_REG   	(*(volatile uint8 *)0x46)
/* Definition for ICR1H (Input Capture Register High) */
#define ICR1H_REG   	(*(volatile uint8 *)0x47)
/* Definition for TIMSK (Timer/Counter Interrupt Mask Register) */
#define TIMSK_REG   	(*(volatile uint8 *)0x59)
/* Definition for TIFR (Timer/Counter Interrupt Flag Register) */
#define TIFR_REG    	(*(volatile uint8 *)0x58)

/* Bit numbers */

/* TCCR1A */
#define TCCR1A_COM1A1  	7
#define TCCR1A_COM1A0  	6
#define TCCR1A_COM1B1  	5
#define TCCR1A_COM1B0  	4
#define TCCR1A_FOC1A   	3
#define TCCR1A_FOC1B   	2
#define TCCR1A_WGM11   	1
#define TCCR1A_WGM10   	0
/* TCCR1B */
#define TCCR1B_ICNC1   	7
#define TCCR1B_ICES1   	6
#define TCCR1B_WGM13   	4
#define TCCR1B_WGM12   	3
#define TCCR1B_CS12    	2
#define TCCR1B_CS11    	1
#define TCCR1B_CS10    	0
/* TIMSK */
#define TIMSK_TICIE1  	5
/* TIFR */
#define TIFR_ICF1   	5


/* Interrupt vectors */

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		_VECTOR(6)

/* Interrupt Handler (ISR) */
#define _VECTOR(N) 			__vector_ ## N
#define ISR(vector) \
	void vector (void) __attribute__ ((signal)); \
	void vector (void)

#endif /* SRC_MCAL_ICU_ICU_PRIVATE_H_ */
