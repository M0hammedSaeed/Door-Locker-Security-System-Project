/*******************************************************************************
 * [ File Name ]: dc_motor.h
 *
 * [Description]: Header File that contain functions prototypes DC-Motor.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *********************************************************************************/


#ifndef SRC_EHAL_DC_MOTOR_DC_MOTOR_H_
#define SRC_EHAL_DC_MOTOR_DC_MOTOR_H_

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                              Definitions
 -------------------------------------------------------------------------------*/

typedef enum
{
	DC_MOTOR_STOP,
	DC_MOTOR_CLOCKWISE,
	DC_MOTOR_ANTI_CLOCKWISE
}EN_DcMotorState_t;

/*------------------------------------------------------------------------------
 *                             	 Configuration
 -------------------------------------------------------------------------------*/

#define DC_MOTOR_PORT_ID       	 PORTB_ID

#define DC_MOTOR_PIN1_ID		 PIN0_ID
#define DC_MOTOR_PIN2_ID		 PIN1_ID

/*------------------------------------------------------------------------------
 *                             Function Prototype
 -------------------------------------------------------------------------------*/

/*
 * [Function Name]: DcMotor_Init
 * [Description]  :  Initialize the DC Motor by:
 * 					 1. Setup the direction of the two motor pins as  output by send the request to GPIO driver.
 * 					 2. Stop the motor at the beginning
 * [Args]  : void
 * [Return]: Void
 */
void DcMotor_Init(void);

/*
 * [Function Name]: DcMotor_Rotate
 * [Description]  :  The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the motor state.
 * 					 Send the required duty cycle to the PWM driver based on the required speed value.
 * [Args]  : 1- Enum to select State
 * 			 2- uint8 to select Speed
 * [Return]: Void
 */
void DcMotor_Rotate(EN_DcMotorState_t state, uint8 speed);

#endif /* SRC_EHAL_DC_MOTOR_DC_MOTOR_H_ */
