/*******************************************************************************
 * [ File Name ]: buzzer.h
 *
 * [Description]: Header File that contain functions prototypes for Buzzer.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_EHAL_BUZZER_BUZZER_H_
#define SRC_EHAL_BUZZER_BUZZER_H_

/*------------------------------------------------------------------------------
 *                              Definitions
 -------------------------------------------------------------------------------*/

#define BUZZER_PORT_ID 		PORTD_ID
#define BUZZER_PIN_ID 		PIN2_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*--------------------------------------------------------------------------------------
 [Function Name]: Buzzer_init
 [DISCRIPTION]:	This function is responsible for Sets the direction of buzzer pin as output pin.
 [Args]: void
 [Return]: void
 ---------------------------------------------------------------------------------------*/
void Buzzer_init(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: Buzzer_on
 [DISCRIPTION]:	This function is responsible for Turns on the buzzer.
 [Args]: void
 [Return]: void
 ---------------------------------------------------------------------------------------*/
void Buzzer_on(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: Buzzer_off
 [DISCRIPTION]:	This function is responsible for Turns off the buzzer.
 [Args]: void
 [Return]: void
 ---------------------------------------------------------------------------------------*/
void Buzzer_off(void);

#endif /* SRC_EHAL_BUZZER_BUZZER_H_ */
