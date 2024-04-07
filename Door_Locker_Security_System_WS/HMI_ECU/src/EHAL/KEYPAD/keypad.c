/*******************************************************************************
 * [ File Name ]: keypad.c
 *
 * [Description]: Source file for the Keypad driver.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "keypad.h"
#include "../../MCAL/GPIO/gpio.h"

/*------------------------------------------------------------------------------
 *                        Private Functions Prototypes
 *------------------------------------------------------------------------------*/

#if (KEYPAD_NUM_COLS == 3)
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: KEYPAD_4x3_adjustKeyNumber
 [DISCRIPTION]:	Function responsible for mapping the switch number in the keypad to
 	 	 	    its corresponding functional number in the proteus for 4x3 keypad
 [Args]: uint8
 [RUTURN]: uint8
 ---------------------------------------------------------------------------------------*/
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number);
#elif (KEYPAD_NUM_COLS == 4)
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: KEYPAD_4x4_adjustKeyNumber
 [DISCRIPTION]:	Function responsible for mapping the switch number in the keypad to
 	 	 	    its corresponding functional number in the proteus for 4x4 keypad
 [Args]: uint8
 [RUTURN]: uint8
 ---------------------------------------------------------------------------------------*/
static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number);
#endif

/*------------------------------------------------------------------------------
 *                               FUNCTIONS Definitions
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:KEYPAD_getPressedKey
 [DISCRIPTION]:	Get the Keypad pressed button.
 [Args]: void
 [RUTURN]: uint8
 ---------------------------------------------------------------------------------------*/
uint8 KEYPAD_getPressedKey(void)
{
	uint8 col = 0;
	uint8 row = 0;
	uint8 keypad_port_value = 0;
	while(1)
	{
		/*
		 * Each time setup the direction for all keypad port as input pins,
		 * except this column will be output pin
		 */
		for(col = 0; col < KEYPAD_NUM_COLS; col++) /* loop for columns */
		{
			GPIO_SetPortDir(KEYPAD_PORT_ID, port_input);
			GPIO_SetPinDir(KEYPAD_PORT_ID, KEYPAD_FIRST_COLUMN_PIN_ID+col, pin_output);
#if (KEYPAD_BUTTON_PRESSED == LOGIC_LOW)
			/* Clear the column output pin and set the rest pins value */
			keypad_port_value = ~(1<<(KEYPAD_FIRST_COLUMN_PIN_ID+col));
#elif (KEYPAD_BUTTON_PRESSED == LOGIC_HIGH)
			/* Set the column output pin and clear the rest pins value */
			keypad_port_value = (1<<(KEYPAD_FIRST_COLUMN_PIN_ID+col));
#endif
			GPIO_WritePort(KEYPAD_PORT_ID, keypad_port_value);

			for(row = 0; row < KEYPAD_NUM_ROWS; row++) /* loop for rows */
			{
				if(GPIO_ReadPin(KEYPAD_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID+row) == KEYPAD_BUTTON_PRESSED)
				{
					/* Check if the switch is pressed in this row */
					#if (KEYPAD_NUM_COLS == 3)
						return KEYPAD_4x3_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#elif (KEYPAD_NUM_COLS == 4)
						return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#endif
				}
			}
		}
	}
}

#if (KEYPAD_NUM_COLS == 3)
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: KEYPAD_4x3_adjustKeyNumber
 [DISCRIPTION]:	Function responsible for mapping the switch number in the keypad to
 	 	 	    its corresponding functional number in the proteus for 4x3 keypad
 [Args]: uint8
 [RUTURN]: uint8
 ---------------------------------------------------------------------------------------*/
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number)
{
	uint8 keypad_button = 0;
	switch(button_number)
	{
	case 10:
		keypad_button = '*';  /* ASCII Code of '*' */
		break;
	case 11:
		keypad_button = 0;
		break;
	case 12:
		keypad_button = '#'; /* ASCII Code of '#' */
		break;
	default:
		keypad_button = button_number;
		break;
	}
	return keypad_button;
}


#elif (KEYPAD_NUM_COLS == 4)
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: KEYPAD_4x4_adjustKeyNumber
 [DISCRIPTION]:	Function responsible for mapping the switch number in the keypad to
 	 	 	    its corresponding functional number in the proteus for 4x4 keypad
 [Args]: uint8
 [RUTURN]: uint8
 ---------------------------------------------------------------------------------------*/
static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number)
{
	uint8 keypad_button = 0;
	switch(button_number)
	{
	case 1:
		keypad_button = 7;
		break;
	case 2:
		keypad_button = 8;
		break;
	case 3:
		keypad_button = 9;
		break;
	case 4:
		keypad_button = '%';  /* ASCII Code of '%' */
		break;
	case 5:
		keypad_button = 4;
		break;
	case 6:
		keypad_button = 5;
		break;
	case 7:
		keypad_button = 6;
		break;
	case 8:
		keypad_button = '*';  /* ASCII Code of '*' */
		break;
	case 9:
		keypad_button = 1;
		break;
	case 10:
		keypad_button = 2;
		break;
	case 11:
		keypad_button = 3;
		break;
	case 12:
		keypad_button = '-';  /* ASCII Code of '-' */
		break;
	case 13:
		keypad_button = 13;  /* ASCII of Enter */
		break;
	case 14:
		keypad_button = 0;
		break;
	case 15:
		keypad_button = '=';  /* ASCII Code of '=' */
		break;
	case 16:
		keypad_button = '+';  /* ASCII Code of '+' */
		break;
	default:
		keypad_button = button_number;
		break;
	}
	return keypad_button;
}

#endif
