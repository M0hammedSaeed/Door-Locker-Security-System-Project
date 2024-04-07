/*******************************************************************************
 * [   Module  ]: Global Interrupt Register
 *
 * [ File Name ]: g_interrupt_private.h
 *
 * [Description]: Header File for ATmega32 EGlobal Interrupt Register.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_G_INTERRUPT_G_INTERRUPT_PRIVATE_H_
#define SRC_MCAL_G_INTERRUPT_G_INTERRUPT_PRIVATE_H_

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* Definition for SREG ( Status Register) */
#define SREG_REG		(*(volatile uint8 *)0x5F)

/* Bit 7  – (I) Global Interrupt Enable */
#define SREG_I			7

#endif /* SRC_MCAL_G_INTERRUPT_G_INTERRUPT_PRIVATE_H_ */
