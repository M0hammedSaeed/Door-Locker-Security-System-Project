/*******************************************************************************
 *
 *  [   Module  ]: ULTRASONIC Module
 *
 *  [ File Name ]: ultrasonic.h
 *
 *  [Description]: Header file for the HC-SR04 Ultrasonic driver
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_EHAL_ULTRASONIC_ULTRASONIC_H_
#define SRC_EHAL_ULTRASONIC_ULTRASONIC_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "../../utils/std_types.h"

/*******************************************************************************
 *                      Definitions and Configuration
 *******************************************************************************/

#define ULTRASONIC_TRIGGER_PORT_ID          PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID           PIN5_ID
#define ULTRASONIC_NUM_OF_DETECTED_EDGES    2

/*******************************************************************************
 *                         FUNCTIONS PROTOTYPES
 *******************************************************************************/

/*
 * [FUNCTION NAME]: Ultrasonic_init
 * [DISCRIPTION]  : Initialize the Ultrasonic driver by:
 * 					1. Initialize the Trigger pin direction
 * 					2. Initialize the ICU driver and Its Call back function.
 * [Args]  : void
 * [RUTURN]: uint16
 */
void Ultrasonic_init(void);

/*
 * [FUNCTION NAME]: Ultrasonic_readDistance
 * [DISCRIPTION]  : Function calculates the distance measured by the Ultrasonic sensor by:
 * 					1. Clear all the variables from the previous read operation.
 *				 	2. Clear the ICU timer register
 * 					3. Send the Trigger to the Ultrasonic by call Ultrasonic_Trigger function
 * 					4. Wait for the measurements to be done by the ICU. We need two edges raising and falling.
 * 					5. Calculate the distance in Centimeter value
 * [Args]  : void
 * [RUTURN]: uint16
 */
uint16 Ultrasonic_readDistance(void);


#endif /* SRC_EHAL_ULTRASONIC_ULTRASONIC_H_ */
