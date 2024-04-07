/*******************************************************************************
 * [   Module  ]: UART Register Module
 *
 * [ File Name ]: uart_private.h
 *
 * [Description]: Header File for ATmega32 UART Register.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_UART_UART_PRIVATE_H_
#define SRC_MCAL_UART_UART_PRIVATE_H_

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* USART */

/* Definition for UDR (USART I/O Data Register) */
#define UDR_REG				(*(volatile uint8 *)0x2C)
/* Definition for UCSRA (USART Control and Status Register A) */
#define UCSRA_REG			(*(volatile uint8 *)0x2B)
/* Definition for UCSRB (USART Control and Status Register B) */
#define UCSRB_REG			(*(volatile uint8 *)0x2A)
/* Definition for UCSRC (USART Control and Status Register C) */
#define UCSRC_REG			(*(volatile uint8 *)0x40)
/* Definition for UBRRH (USART Baud Rate Registers High) */
#define UBRRH_REG			(*(volatile uint8 *)0x40)
/* Definition for UBRRL (USART Baud Rate Registers Low) */
#define UBRRL_REG			(*(volatile uint8 *)0x29)

/* Bit numbers */

/* UCSRA */
#define UCSRA_RXC     7
#define UCSRA_TXC     6
#define UCSRA_UDRE    5
#define UCSRA_FE      4
#define UCSRA_DOR     3
#define UCSRA_PE      2
#define UCSRA_U2X     1
#define UCSRA_MPCM    0

/* UCSRB */
#define UCSRB_RXCIE   7
#define UCSRB_TXCIE   6
#define UCSRB_UDRIE   5
#define UCSRB_RXEN    4
#define UCSRB_TXEN    3
#define UCSRB_UCSZ2   2
#define UCSRB_RXB8    1
#define UCSRB_TXB8    0

/* UCSRC */
#define UCSRC_URSEL   7
#define UCSRC_UMSEL   6
#define UCSRC_UPM1    5
#define UCSRC_UPM0    4
#define UCSRC_USBS    3
#define UCSRC_UCSZ1   2
#define UCSRC_UCSZ0   1
#define UCSRC_UCPOL   0

/* UBRRH */
#define UBRRH_URSEL		7


/* Interrupt vectors */

/* USART, Rx Complete */
#define USART_RXC_vect			_VECTOR(13)
/* USART Data Register Empty */
#define USART_UDRE_vect			_VECTOR(14)
/* USART, Tx Complete */
#define USART_TXC_vect			_VECTOR(15)

/* Interrupt Handler (ISR) */
#define _VECTOR(N) 			__vector_ ## N
#define ISR(vector) \
	void vector (void) __attribute__ ((signal)); \
	void vector (void)

/*******************************************************************************
 *                                    MASK's
 *******************************************************************************/

/* the most commonly used baud rates for asynchronous operation */
#define USART_2400BPS   		 			2400
#define USART_4800BPS   		 			4800
#define USART_9600BPS   		 			9600
#define USART_14400BPS  		 			14400
#define USART_19200BPS  		 			19200
#define USART_38400BPS  		 			38400
#define USART_57600BPS  		 			57600
#define USART_115200BPS 		 			115200
#define USART_128000BPS 		 			128000
#define USART_256000BPS 		 			256000

/* Types of Parity generation and check */
#define USART_ParityCheckDisabled			0x00
#define USART_ParityCheckEnabledEven 	 	0x20
#define USART_ParityCheckEnabledOdd			0x30

/* Selects the Number of Stop Bits to be inserted by the Transmitter */
#define USART_1BitStop						0x00
#define USART_2BitsStop						0x08

/* Clock Polarity used for Synchronous Mode */
#define USART_RisingTxFallingRxEdge			0x00
#define USART_RisingRxFallingTxEdge			0x01

/* Mode Select between Asynchronous and Synchronous mode of operation */
#define USART_ASYNCHRONOUS_MODE				0x00
#define USART_SYNCHRONOUS_MODE				0x40

/* the number of data bits (Character Size) in a frame the Receiver and Transmitter use */
#define USART_5BitsDataSize					0x00
#define USART_6BitsDataSize					0x01
#define USART_7BitsDataSize					0x02
#define USART_8BitsDataSize					0x03
#define USART_9BitsDataSize 				0x07

/* Double the USART Transmission Speed */
#define USART_DoubleSpeedDisabled			0x00
#define USART_DoubleSpeedEnabled			0x02

#endif /* SRC_MCAL_UART_UART_PRIVATE_H_ */
