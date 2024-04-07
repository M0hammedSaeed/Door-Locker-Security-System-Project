/*******************************************************************************
 *
 *  [   Module  ]: External Interrupts Modules
 *
 *  [ File Name ]: ex_interrupt.h
 *
 *  [Description]: Header File for configuration AVR_ATmega32 External Interrupts.
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_H_
#define SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "../../utils/std_types.h"
#include "../GPIO/gpio.h"

/*******************************************************************************
 *                      Definitions and Configuration
 *******************************************************************************/

/*[Description]: Write ENABLE/DISABLE To Configure Specific Ex_Interrupt
 *[  Example  ]: EX_INT0   ENABLE
 *               EX_INT1   DISABLE
 */
#define EX_INT0			ENABLE
#define EX_INT1			DISABLE
#define EX_INT2			DISABLE

#define EX_INT0_PORT	PORTD_ID
#define EX_INT0_PIN		PIN2_ID

#define EX_INT1_PORT	PORTD_ID
#define EX_INT1_PIN		PIN3_ID

#define EX_INT2_PORT	PORTB_ID
#define EX_INT2_PIN		PIN2_ID
/*[Description]: Choose the external Interrupt0 trigger sense
 *[INT0_SENSE_TYPES]:
 *
 * 				--> [INT0_SENSE_LOW_LEVEL_MASK]
 * 				--> [INT0_SENSE_ANY_LOGICAL_CHANGE_MASK]
 *				--> [INT0_SENSE_FALLING_EDGE_MASK]
 * 				--> [INT0_SENSE_RISING_EDGE_MASK]
 *
 *[  Example  ]: INT0_SENSE_SELECTOR   INT0_SENSE_FALLING_EDGE_MASK
 *
 */
#define INT0_SENSE_SELECTOR			INT0_SENSE_FALLING_EDGE_MASK

/*[Description]: Choose the external Interrupt1 trigger sense
 *[INT1_SENSE_TYPES]:
 *
 * 				--> [INT1_SENSE_LOW_LEVEL_MASK]
 * 				--> [INT1_SENSE_ANY_LOGICAL_CHANGE_MASK]
 *				--> [INT1_SENSE_FALLING_EDGE_MASK]
 * 				--> [INT1_SENSE_RISING_EDGE_MASK]
 *
 *[  Example  ]: INT1_SENSE_SELECTOR   INT1_SENSE_LOW_LEVEL_MASK
 *
 */
#define INT1_SENSE_SELECTOR			INT1_SENSE_FALLING_EDGE_MASK

/*[Description]: Choose the external Interrupt2 trigger sense
 *[INT2_SENSE_TYPES]:
 *
 *				--> [INT2_SENSE_FALLING_EDGE_MASK]
 * 				--> [INT2_SENSE_RISING_EDGE_MASK]
 *
 *[  Example  ]: INT2_SENSE_SELECTOR   INT2_SENSE_RISING_EDGE_MASK
 *
 */
#define INT2_SENSE_SELECTOR			INT2_SENSE_RISING_EDGE_MASK

/*******************************************************************************
 *                         FUNCTIONS AND DECLARATIONS
 *******************************************************************************/

/*
 * [FUNCTION NAME]: Ex_INT_Init
 * [DISCRIPTION]  : This function is responsible to initialization one or more than one EXternal interrupt at
 *                  The same time from Configuration of External interrupt .
 * [Args]  : void
 * [RUTURN]: Void
 */
void Ex_INT_Init(void);

/*
 * [FUNCTION NAME]: Ex_INT_SetCallBack
 * [DISCRIPTION]  : This function allow Application layer call function from
 *                  MCAL layer by interrupt called callback function.
 * [Args]  : Pointer To Function take void and return void
 * [RUTURN]: Void
 */
void Ex_INT0_SetCallBack(void (*ptr_To_function)(void));
void Ex_INT1_SetCallBack(void (*ptr_To_function)(void));
void Ex_INT2_SetCallBack(void (*ptr_To_function)(void));

#endif /* SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_H_ */
