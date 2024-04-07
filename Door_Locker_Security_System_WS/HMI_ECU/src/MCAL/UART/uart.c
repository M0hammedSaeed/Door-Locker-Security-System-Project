/*******************************************************************************
 *
 *  [   Module  ]: UART Module
 *
 *  [ File Name ]: uart.c
 *
 *  [Description]: Source file for the UART AVR driver
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  Includes
 *******************************************************************************/

#include "uart_private.h"
#include "uart.h"
#include "../../utils/common_macros.h"

/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/

/*
 * [Description]: Pointer To Function Save the Address Of The function
 *                That will called when Event or interrupt occur .
 *            ==> AND Every interrupt type have Pointer To g_Function .
 */
static volatile void(*g_Ptr_To_Fun_RXC)(void)= NULL_PTR;
static volatile void(*g_Ptr_To_Fun_TXC)(void)= NULL_PTR;
static volatile void(*g_Ptr_To_Fun_UDRE)(void)= NULL_PTR;

/*******************************************************************************
 *                                 USART_ISR
 *******************************************************************************/

/*
 * [Description]: The ISR's specific For RX Complete Interrupt Enable
 */
ISR(USART_RXC_vect)
{
	/* Call the Call Back function in the application after the Event is Occur */
	if(g_Ptr_To_Fun_RXC != NULL_PTR)
	{
		/* This is called --> Call Back Notification */
		/* another method to call the function using pointer to function g_Ptr_To_Fun_RXC(); */
		(*g_Ptr_To_Fun_RXC)();
	}
}

/*
 * [Description]: The ISR's specific For TX Complete Interrupt Enable
 */
ISR(USART_TXC_vect)
{
	/* Call the Call Back function in the application after the Event is Occur */
	if(g_Ptr_To_Fun_TXC != NULL_PTR)
	{
		/* This is called --> Call Back Notification */
		/* another method to call the function using pointer to function g_Ptr_To_Fun_TXC(); */
		(*g_Ptr_To_Fun_TXC)();
	}
}

/*
 * [Description]: The ISR's specific For USART Data Register Empty Interrupt Enable
 */
ISR(USART_UDRE_vect)
{
	/* Call the Call Back function in the application after the Event is Occur */
	if(g_Ptr_To_Fun_UDRE != NULL_PTR)
	{
		/* This is called --> Call Back Notification */
		/* another method to call the function using pointer to function g_Ptr_To_Fun_UDRE(); */
		(*g_Ptr_To_Fun_UDRE)();
	}
}

/*******************************************************************************
 *                      	Functions Definitions
 *******************************************************************************/

/*
 * [Function Name]: USART_Init
 * [Description]  : Functional responsible for Initialize the UART device.
 * [Args]  : Void
 * [Return]: Void
 */
void USART_Init(void)
{
	uint8  UCSRA_Init = 0;
	uint8  UCSRB_Init = 0;
	uint8  UCSRC_Init = 0;
	uint16 UBRR_Init  = 0;

	/* Set the USART Operation Mode and the USART Double Transmission Speed */
#if(USART_OperationMode_SELECTOR == USART_ASYNCHRONOUS_MODE) && (USART_DoubleSpeedStatus == USART_DoubleSpeedDisabled)
	UBRR_Init =  (uint16)(((F_CPU / (USART_BAUDRATE_SELECTOR * 16UL))) - 1); /* Calculate the UBRR register value */

	#elif(USART_OperationMode_SELECTOR == USART_ASYNCHRONOUS_MODE) && (USART_DoubleSpeedStatus == USART_DoubleSpeedEnabled)
	UCSRA_Init |= (1<<UCSRA_U2X); /* U2X = 1 for double transmission speed */
	UBRR_Init = (uint16)(((F_CPU / (USART_BAUDRATE_SELECTOR * 8UL))) - 1); /* Calculate the UBRR register value */

	/* Set the USART Operation Mode and the USART Clock Polarity */
#elif(USART_OperationMode_SELECTOR == USART_SYNCHRONOUS_MODE) && (USART_ClockPolarity == USART_RisingTxFallingRxEdge)
	UCSRC_Init |= (1<<UCSRC_UMSEL); /* Synchronous Operation */
	UBRR_Init = (uint16)(((F_CPU / (USART_BAUDRATE_SELECTOR * 2UL))) - 1); /* Calculate the UBRR register value */

#elif(USART_OperationMode_SELECTOR == USART_SYNCHRONOUS_MODE) && (USART_ClockPolarity == USART_RisingRxFallingTxEdge)
	UCSRC_Init |= (1<<UCSRC_UMSEL) | (1<<UCSRC_UCPOL); /* Synchronous Operation */
	UBRR_Init = (uint16)(((F_CPU / (USART_BAUDRATE_SELECTOR * 2UL))) - 1); /* Calculate the UBRR register value */

#endif

	/*
	 * Enable USART RX Complete Interrupt Enable
	 * Enable USART Tx Complete Interrupt Enable
	 * Enable USART Data Register Empty Interrupt Enable
	 */
#if(USART_InterruptStatus == ENABLE)
	UCSRB_Init |= (1<<UCSRB_TXCIE) | (1<<UCSRB_UDRIE) | (1<<UCSRB_RXCIE);
#endif

	/* Set the USART Stop Bits */
#if(USART_StopBits_Selector == USART_2BitsStop)
	UCSRC_Init |= (1<<UCSRC_USBS);
#endif

	/* Set the USART Data Size */
	switch(USART_DataSize_SELECTOR)
	{
	case USART_5BitsDataSize: /* For 5-bit data mode */
		break;
	case USART_6BitsDataSize: /* For 6-bit data mode */
		UCSRC_Init |= (1<<UCSRC_UCSZ0);
		break;
	case USART_7BitsDataSize: /* For 7-bit data mode */
		UCSRC_Init |= (1<<UCSRC_UCSZ1);
		break;
	case USART_8BitsDataSize: /* For 8-bit data mode */
		UCSRC_Init |= (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
		break;
	case USART_9BitsDataSize: /* For 9-bit data mode */
		UCSRC_Init |= (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
		UCSRB_Init |= (1<<UCSRB_UCSZ2);
		break;
	default:
		break;
	}

	/* Set the USART Parity Check */
	UCSRC_Init |= USART_ParityCheck;


	UCSRA_REG = UCSRA_Init;
	/* Receiver Enable and Transmitter Enable */
	UCSRB_REG = UCSRB_Init | (1<<UCSRB_RXEN) | (1<<UCSRB_TXEN);
	/* The URSEL must be one when writing the UCSRC */
	UCSRC_REG = UCSRC_Init |(1<<UCSRC_URSEL);
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH_REG = (uint8)(UBRR_Init >> 8);
	UBRRL_REG = (uint8)UBRR_Init;
}

/*
 * [Function Name]: USART_sendByte
 * [Description]  : Functional responsible for send byte to another UART device.
 * [Args]  : constant uint16
 * [Return]: Void
 */
void USART_sendByte(const uint16 data)
{
#if USART_InterruptStatus == ENABLE
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte
	 */
	if((UCSRA_REG & (1<<UCSRA_UDRE)) != 0)
	{
		if(USART_DataSize_SELECTOR == USART_9BitsDataSize)
		{
			UCSRB_REG = (UCSRB_REG & 0xFD) | ((data & (1<<8)) >> 7);
		}
	}

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR_REG = (uint8)data;

#elif USART_InterruptStatus == DISABLE
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while((UCSRA_REG & (1<<UCSRA_UDRE)) == 0);

	if(USART_DataSize_SELECTOR == USART_9BitsDataSize)
	{
		UCSRB_REG = (UCSRB_REG & 0xFD) | ((data & (1<<8)) >> 7);
	}

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR_REG = (uint8)data;
#endif

}

/*
* [Function Name]: USART_recieveByte
* [Description]  : Functional responsible for receive byte from another UART device.
* [Args]  : void
* [Return]: uint16
*/
uint16 USART_recieveByte(void)
{
	uint16 data = 0;

#if USART_InterruptStatus == ENABLE
	/* RXC flag is set when the UART receive data */
	if((UCSRA_REG & (1<<UCSRA_RXC)) != 0)
	{
		if(USART_DataSize_SELECTOR == USART_9BitsDataSize)
		{
			data = ((UCSRB_REG & (1<<UCSRB_RXB8))) << 8;
		}
		/*
		 * Read the received data from the Rx buffer (UDR)
		 * The RXC flag will be cleared after read the data
		 */
		data |= UDR_REG;
	}
#elif USART_InterruptStatus == DISABLE
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while((UCSRA_REG & (1<<UCSRA_RXC)) == 0);

	if(USART_DataSize_SELECTOR == USART_9BitsDataSize)
	{
		data = ((UCSRB_REG & (1<<UCSRB_RXB8))) << 8;
	}
	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
	data |= UDR_REG;
#endif
	return data;
}

/*
* [Function Name]: USART_sendString
* [Description]  : Send the required string through UART to the other UART device.
* [Args]  : pointer to constant uint8
* [Return]: Void
*/
void USART_sendString(const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		USART_sendByte(Str[i++]);
	}
	/************************* Another Method *************************
	while(*Str != '\0')
	{
		USART_sendByteBlocking(Str[i]);
		Str++;
	}
	*******************************************************************/

}

/*
* [Function Name]: USART_receiveString
* [Description]  : Receive the required string until pressed Enter Key through UART from the other UART device.
* [Args]  : pointer to constant uint8
* [Return]: Void
*/
void USART_receiveString(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = USART_recieveByte();

	/* Receive the whole string until the pressed Enter Key */
	while(Str[i] != 13)
	{
		i++;
		Str[i] = USART_recieveByte();
	}
	/* After receiving the whole string plus pressed Enter Key, replace the Enter Key with '\0' */
	Str[i] = '\0';
}

/*
* [Function Name]: USART_SetCallBack
* [Description]  : This function's is responsible to set the Call Back function address.
*                  Every set callback function follow specific interrupt.
* [Args]  : Pointer To Function take void and return void
* [Return]: Void
*/
void USART_RXC_SetCallBack(void (*Ptr_To_fun)(void))
{
	g_Ptr_To_Fun_RXC = (volatile void *)Ptr_To_fun;
}

void USART_TXC_SetCallBack(void (*Ptr_To_fun)(void))
{
	g_Ptr_To_Fun_TXC = (volatile void *)Ptr_To_fun;
}

void USART_UDRE_SetCallBack(void (*Ptr_To_fun)(void))
{
	g_Ptr_To_Fun_UDRE = (volatile void *)Ptr_To_fun;
}
