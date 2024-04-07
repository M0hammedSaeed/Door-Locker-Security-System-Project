/*******************************************************************************
 * [ File Name ]: keypad.h
 *
 * [Description]:  Header file for the Keypad driver.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_EHAL_KEYPAD_KEYPAD_H_
#define SRC_EHAL_KEYPAD_KEYPAD_H_

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                         DEFINITIONS AND CONFIGURATION
 *------------------------------------------------------------------------------*/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS					4
#define KEYPAD_NUM_ROWS					4

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID					PORTA_ID

#define KEYPAD_FIRST_ROW_PIN_ID			PIN0_ID
#define KEYPAD_FIRST_COLUMN_PIN_ID		PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED			LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED			LOGIC_HIGH

/*------------------------------------------------------------------------------
 *                             Function Prototype
 -------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:KEYPAD_getPressedKey
 [DISCRIPTION]:	Get the Keypad pressed button.
 [Args]: void
 [RUTURN]: uint8
 ---------------------------------------------------------------------------------------*/
uint8 KEYPAD_getPressedKey(void);

#endif /* SRC_EHAL_KEYPAD_KEYPAD_H_ */
