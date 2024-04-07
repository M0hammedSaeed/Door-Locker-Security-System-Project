/*******************************************************************************
 *
 *  [   Module  ]: Global Interrupt
 *
 *  [ File Name ]: g_interrupt.c
 *
 *  [Description]: Source File for Global Interrupt Enable or Disable For AVR.
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "g_interrupt_private.h"
#include "g_interrupt.h"
#include "../../utils/common_macros.h"

/*******************************************************************************
 *                         Implementation FUNCTIONS
 *******************************************************************************/

/*
 * [FUNCTION NAME]: GI_Enable
 * [DISCRIPTION]  : This Function used to enable Global Interrupt Enable (GIE)
 * [RUTURN]: Void
 */
void GI_Enable(void)
{
	SET_BIT(SREG_REG,SREG_I);
}

/*
 * [FUNCTION NAME]: GI_Disable
 * [DISCRIPTION]  : This Function used to Disable Global Interrupt Enable (GIE)
 * [RUTURN]: Void
 */
void GI_Disable(void)
{
	CLEAR_BIT(SREG_REG,SREG_I);
}
