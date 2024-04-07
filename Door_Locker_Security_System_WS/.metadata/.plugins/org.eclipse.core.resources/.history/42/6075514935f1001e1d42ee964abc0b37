/*******************************************************************************
 *
 *  [   Module  ]: UART Module
 *
 *  [ File Name ]: uart.h
 *
 *  [Description]: Header file for the UART AVR driver
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_UART_UART_H_
#define SRC_MCAL_UART_UART_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "../../utils/std_types.h"

/*******************************************************************************
 *                      Definitions and Configuration
 *******************************************************************************/

/*
 * [Description]: To used baud rates for asynchronous operation
 * 				  just copy Mask of Baud Rates and paste in BAUDRATE selector.
 *
 * [Example]: #define USART_BAUDRATE_SELECTOR   USART_9600BPS
 *            like this you configure USART to work with 9600 Bit Per Second.
 *
 * [SELECT BAUDRATE]:
 * 			--> [USART_2400BPS]
 * 			--> [USART_4800BPS]
 * 			--> [USART_9600BPS]
 * 			--> [USART_14400BPS]
 * 			--> [USART_19200BPS]
 * 			--> [USART_38400BPS]
 * 			--> [USART_57600BPS]
 * 			--> [USART_115200BPS]
 * 			--> [USART_128000BPS]
 * 			--> [USART_256000BPS]
 */
#define USART_BAUDRATE_SELECTOR				USART_9600BPS

/*
 * [Description]: To Select Types of Parity generation and check just copy Mask
 * 				  of Parity and paste in parity check selector.
 *
 * [Example]: #define USART_ParityCheck   USART_ParityCheckDisabled
 *            like this you configure USART to no parity bit in the frame .
 *
 * [Select Parity Check]:
 * 			--> [USART_ParityCheckDisabled]
 * 			--> [USART_ParityCheckEnabledEven]
 * 			--> [USART_ParityCheckEnabledOdd]
 */
#define USART_ParityCheck					USART_ParityCheckDisabled

/*
 * [Description]: To selects the number of Stop Bits to be inserted by the Transmitter
 * 				  just copy Mask and paste in Stop Bits selector.
 *
 * [Example]: #define USART_StopBits_Selector		USART_1BitStop
 *            like this you configure USART to insert one stop bit in the frame.
 *
 * [Select Number of Stop Bits]:
 * 			--> [USART_1BitStop]
 * 			--> [USART_2BitsStop]
 */
#define USART_StopBits_Selector				USART_1BitStop

/*
 * [Description]: To enabled and disabled the USART Interrupt
 * 				  just copy Mask and paste in Interrupt Status selector.
 *
 * [Example]: #define USART_InterruptStatus				DISABLE
 *            like this you configure USART to disabled the interrupt.
 *
 * [Select]:
 * 			--> [DISABLE]
 * 			--> [ENABLE]
 */
#define USART_InterruptStatus				DISABLE

/*
 * [Description]: To Select Clock Polarity used for Synchronous Mode
 * 				  just copy Mask and paste in Clock Polarity selector.
 *
 * [Example]: #define USART_ClockPolarity		USART_RisingTxFallingRxEdge
 *            like this you configure USART to Transmitted Data Changed at Rising XCK Edge
 *            Received Data Sampled at Falling XCK Edge.
 *
 * [Select Clock Polarity]:
 * 			--> [DISABLE]
 * 			--> [USART_RisingTxFallingRxEdge]
 * 			--> [USART_RisingRxFallingTxEdge]
 */
#define USART_ClockPolarity					DISABLE

/*
 * [Description]: To selects between Asynchronous and Synchronous mode of operation
 * 				  just copy Mask and paste in Operation Mode selector.
 *
 * [Example]: #define USART_OperationMode_SELECTOR		USART_ASYNCHRONOUS_MODE
 *            like this you configure USART to selects Asynchronous mode of operation.
 *
 * [Select mode of operation]:
 * 			--> [USART_ASYNCHRONOUS_MODE]
 * 			--> [USART_SYNCHRONOUS_MODE]
 */
#define USART_OperationMode_SELECTOR		USART_ASYNCHRONOUS_MODE

/*
 * [Description]: To selects number of data bits (Character Size) in a frame the Receiver and
 * 				  Transmitter use just copy Mask and paste in Data Size selector.
 *
 * [Example]: #define USART_DataSize_SELECTOR				USART_8BitsDataSize
 *            like this you configure USART to selects number of data bits in frame 8 bits.
 *
 * [Select Data Size]:
 * 			--> [USART_5BitsDataSize]
 * 			--> [USART_6BitsDataSize]
 * 			--> [USART_7BitsDataSize]
 * 			--> [USART_8BitsDataSize]
 * 			--> [USART_9BitsDataSize]
 */
#define USART_DataSize_SELECTOR				USART_8BitsDataSize

/*
 * [Description]: To selects Double the USART Transmission Speed just copy Mask and paste
 * 				  in Double the USART Transmission Speed selector.
 *
 * [Example]: #define USART_DoubleSpeedStatus				USART_DoubleSpeedEnabled
 *            like this you configure USART to selects Enable Double the USART Transmission Speed.
 *
 * [Select Double the USART Transmission Speed]:
 * 			--> [USART_DoubleSpeedDisabled]
 * 			--> [USART_DoubleSpeedEnabled]
 */
#define USART_DoubleSpeedStatus				USART_DoubleSpeedEnabled

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * [Function Name]: USART_Init
 * [Description]  : Functional responsible for Initialize the UART device.
 * [Args]  : Void
 * [Return]: Void
 */
void USART_Init(void);

/*
* [Function Name]: USART_sendByte
* [Description]  : Functional responsible for send byte to another UART device.
* [Args]  : constant uint16
* [Return]: Void
*/
void USART_sendByte(const uint16 data);

/*
* [Function Name]: USART_recieveByte
* [Description]  : Functional responsible for receive byte from another UART device.
* [Args]  : void
* [Return]: uint16
*/
uint16 USART_recieveByte(void);

/*
* [Function Name]: USART_sendString
* [Description]  : Send the required string through UART to the other UART device.
* [Args]  : pointer to constant uint8
* [Return]: Void
*/
void USART_sendString(const uint8 *Str);

/*
* [Function Name]: USART_receiveString
* [Description]  : Receive the required string until pressed Enter Key through UART from the other UART device.
* [Args]  : pointer to constant uint8
* [Return]: Void
*/
void USART_receiveString(uint8 *Str);

/*
* [Function Name]: USART_SetCallBack
* [Description]  : This function's is responsible to set the Call Back function address.
*                  Every set callback function follow specific interrupt.
* [Args]  : Pointer To Function take void and return void
* [Return]: Void
*/
void USART_RXC_SetCallBack(void (*Ptr_To_fun)(void));
void USART_TXC_SetCallBack(void (*Ptr_To_fun)(void));
void USART_UDRE_SetCallBack(void (*Ptr_To_fun)(void));

#endif /* SRC_MCAL_UART_UART_H_ */
