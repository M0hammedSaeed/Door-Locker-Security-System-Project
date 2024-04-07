/*******************************************************************************
 *
 *  [   Module  ]: Global Interrupt
 *
 *  [ File Name ]: g_interrupt.h
 *
 *  [Description]: Header File for Global Interrupt Enable or Disable For AVR.
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_G_INTERRUPT_G_INTERRUPT_H_
#define SRC_MCAL_G_INTERRUPT_G_INTERRUPT_H_

/*******************************************************************************
 *                         FUNCTIONS AND DECLARATIONS
 *******************************************************************************/

/*
 * [FUNCTION NAME]: GI_Enable
 * [DISCRIPTION]  : This Function used to enable Global Interrupt Enable (GIE)
 * [RUTURN]: Void
 */
void GI_Enable(void);

/*
 * [FUNCTION NAME]: GI_Disable
 * [DISCRIPTION]  : This Function used to Disable Global Interrupt Enable (GIE)
 * [RUTURN]: Void
 */
void GI_Disable(void);


#endif /* SRC_MCAL_G_INTERRUPT_G_INTERRUPT_H_ */
