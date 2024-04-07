/*******************************************************************************
 * [ File Name ]: buzzer.c
 *
 * [Description]: Source File that contain implementation functions for Buzzer.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "buzzer.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                               FUNCTIONS IMPLEMENTATION
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [Function Name]: Buzzer_init
 [DISCRIPTION]:	This function is responsible for Sets the direction of buzzer pin as output pin.
 [Args]: void
 [Return]: void
 ---------------------------------------------------------------------------------------*/
void Buzzer_init(void)
{
	GPIO_SetPinDir(BUZZER_PORT_ID, BUZZER_PIN_ID, pin_output);
	GPIO_WritePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

/*--------------------------------------------------------------------------------------
 [Function Name]: Buzzer_on
 [DISCRIPTION]:	This function is responsible for Turns on the buzzer.
 [Args]: void
 [Return]: void
 ---------------------------------------------------------------------------------------*/
void Buzzer_on(void)
{
	GPIO_WritePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}

/*--------------------------------------------------------------------------------------
 [Function Name]: Buzzer_off
 [DISCRIPTION]:	This function is responsible for Turns off the buzzer.
 [Args]: void
 [Return]: void
 ---------------------------------------------------------------------------------------*/
void Buzzer_off(void)
{
	GPIO_WritePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
