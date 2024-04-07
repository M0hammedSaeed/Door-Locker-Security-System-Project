/*******************************************************************************
 *
 *  [   Module  ]: ICU Modules
 *
 *  [ File Name ]: icu.h
 *
 *  [Description]: Header File for ICU Module
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_ICU_ICU_H_
#define SRC_MCAL_ICU_ICU_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "../../utils/std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

#define ICP_PORT_ID				PORTD_ID
#define ICP_PIN_ID				PIN6_ID

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;


/*******************************************************************************
 *                           FUNCTIONS Prototypes
 *******************************************************************************/

/*
 * [FUNCTION NAME]: Icu_init
 * [DISCRIPTION]  : Function to initialize the ICU driver
 * 					1. Set the required clock.
 * 					2. Set the required edge detection.
 * 					3. Enable the Input Capture Interrupt.
 * 					4. Initialize Timer1 Registers
 * [Args]  : pointer to constant structure
 * [RUTURN]: Void
 */
void Icu_init(const Icu_ConfigType * Config_Ptr);

/*
 * [FUNCTION NAME]: Icu_setCallBack
 * [DISCRIPTION]  : Function to set the Call Back function address.
 * [Args]  : pointer to function tack void and return void
 * [RUTURN]: Void
 */
void Icu_setCallBack(void(*Ptr_To_fun)(void));

/*
 * [FUNCTION NAME]: Icu_setEdgeDetectionType
 * [DISCRIPTION]  : Function to set the required edge detection.
 * [Args]  : enum
 * [RUTURN]: Void
 */
void Icu_setEdgeDetectionType(const Icu_EdgeType edgeType);

/*
 * [FUNCTION NAME]: Icu_getInputCaptureValue
 * [DISCRIPTION]  : Function to get the Timer1 Value when the input is captured
 *                  The value stored at Input Capture Register ICR1
 * [Args]  : Void
 * [RUTURN]: uint16
 */
uint16 Icu_getInputCaptureValue(void);

/*
 * [FUNCTION NAME]: Icu_clearTimerValue
 * [DISCRIPTION]  : Function to clear the Timer1 Value to start count from ZERO
 * [Args]  : Void
 * [RUTURN]: Void
 */
void Icu_clearTimerValue(void);

/*
 * [FUNCTION NAME]: Icu_DeInit
 * [DISCRIPTION]  : Function to disable the Timer1 to stop the ICU Driver
 * [Args]  : Void
 * [RUTURN]: Void
 */
void Icu_DeInit(void);

#endif /* SRC_MCAL_ICU_ICU_H_ */
