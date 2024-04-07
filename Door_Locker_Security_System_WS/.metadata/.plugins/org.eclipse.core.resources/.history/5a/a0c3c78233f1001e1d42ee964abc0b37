/*******************************************************************************
 *
 *  [   Module  ]: ICU Modules
 *
 *  [ File Name ]: icu.c
 *
 *  [Description]: Source File For ICU Module.
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "icu.h"
#include "icu_private.h"
#include "../GPIO/gpio.h"

/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/

/*
 * [Description]: Pointer To Function Save the Address Of The function
 *                That will called when Event or interrupt occur .
 *            ==> Global variables to hold the address of the call back function in the application
 */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		/* another method to call the function using pointer to function g_callBackPtr(); */
		(*g_callBackPtr)();
	}
}

/*******************************************************************************
 *                         Implementation FUNCTIONS
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
void Icu_init(const Icu_ConfigType * Config_Ptr)
{
	/* Configure ICP1/PD6 as i/p pin */
	GPIO_SetPinDir(ICP_PORT_ID, ICP_PIN_ID, pin_input);

	/* Timer1 always operates in Normal Mode */
	TCCR1A_REG = (1<<TCCR1A_FOC1A) | (1<<TCCR1A_FOC1B);

	/*
	 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
	 * of TCCR1B Register
	 */
	TCCR1B_REG = (TCCR1B_REG & 0xF8) | (Config_Ptr->clock);
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B_REG = (TCCR1B_REG & 0xBF) | ((Config_Ptr->edge)<<6);

	/* Initial Value for Timer1 */
	TCNT1_REG = 0;

	/* Initial Value for the input capture register */
	ICR1_REG = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	TIMSK_REG |= (1<<TIMSK_TICIE1);
}

/*
 * [FUNCTION NAME]: Icu_setCallBack
 * [DISCRIPTION]  : Function to set the Call Back function address.
 * [Args]  : pointer to function tack void and return void
 * [RUTURN]: Void
 */
void Icu_setCallBack(void(*Ptr_To_fun)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = (volatile void *) Ptr_To_fun;
}

/*
 * [FUNCTION NAME]: Icu_setEdgeDetectionType
 * [DISCRIPTION]  : Function to set the required edge detection.
 * [Args]  : enum
 * [RUTURN]: Void
 */
void Icu_setEdgeDetectionType(const Icu_EdgeType edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B_REG = (TCCR1B_REG & 0xBF) | ((edgeType)<<6);
}

/*
 * [FUNCTION NAME]: Icu_getInputCaptureValue
 * [DISCRIPTION]  : Function to get the Timer1 Value when the input is captured
 *                  The value stored at Input Capture Register ICR1
 * [Args]  : Void
 * [RUTURN]: uint16
 */
uint16 Icu_getInputCaptureValue(void)
{
	return ICR1_REG;
}

/*
 * [FUNCTION NAME]: Icu_clearTimerValue
 * [DISCRIPTION]  : Function to clear the Timer1 Value to start count from ZERO
 * [Args]  : Void
 * [RUTURN]: Void
 */
void Icu_clearTimerValue(void)
{
	TCNT1_REG = 0;
}

/*
 * [FUNCTION NAME]: Icu_DeInit
 * [DISCRIPTION]  : Function to disable the Timer1 to stop the ICU Driver
 * [Args]  : Void
 * [RUTURN]: Void
 */
void Icu_DeInit(void)
{
	/* Clear All Timer1 Registers */
	TCCR1A_REG = 0;
	TCCR1B_REG = 0;
	TCNT1_REG = 0;
	ICR1_REG = 0;

	/* Disable the Input Capture interrupt */
	TIMSK_REG &= ~(1<<TIMSK_TICIE1);
}

