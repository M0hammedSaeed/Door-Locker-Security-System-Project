/*******************************************************************************
 * [   Module  ]: TWI Register Module
 *
 * [ File Name ]: twi_private.h
 *
 * [Description]: Header File for ATmega32 TWI Register.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_TWI_TWI_PRIVATE_H_
#define SRC_MCAL_TWI_TWI_PRIVATE_H_

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* TWI stands for "Two Wire Interface" or "TWI Was I2C" */

/* Definition for TWBR (TWI Bit Rate Register) */
#define TWBR_REG				(*(volatile uint8 *)0x20)
/* Definition for TWSR (TWI Status Register) */
#define TWSR_REG    			(*(volatile uint8 *)0x21)
/* Definition for TWAR (TWI (Slave) Address Register) */
#define TWAR_REG    			(*(volatile uint8 *)0x22)
/* Definition for TWDR (TWI Data Register) */
#define TWDR_REG    			(*(volatile uint8 *)0x23)
/* Definition for TWCR (TWI Control Register) */
#define TWCR_REG    			(*(volatile uint8 *)0x56)

/* Bit numbers */

/* TWCR */
#define TWCR_TWINT   7
#define TWCR_TWEA    6
#define TWCR_TWSTA   5
#define TWCR_TWSTO   4
#define TWCR_TWWC    3
#define TWCR_TWEN    2
#define TWCR_TWIE    0

/* TWAR */
#define TWAR_TWA6    7
#define TWAR_TWA5    6
#define TWAR_TWA4    5
#define TWAR_TWA3    4
#define TWAR_TWA2    3
#define TWAR_TWA1    2
#define TWAR_TWA0    1
#define TWAR_TWGCE   0

/* TWSR */
#define TWSR_TWS7    7
#define TWSR_TWS6    6
#define TWSR_TWS5    5
#define TWSR_TWS4    4
#define TWSR_TWS3    3
#define TWSR_TWPS1   1
#define TWSR_TWPS0   0

/* Interrupt vectors */

/* 2-wire Serial Interface */
#define TWI_vect				_VECTOR(19)

/* ISR attribute function */
#define _VECTOR(N) 			__vector_ ## N
#define ISR(vector) \
	void vector (void) __attribute__ ((signal)); \
	void vector (void)

/*******************************************************************************
 *                                    MASK's
 *******************************************************************************/

#define TWI_INTERRUPT_DISABLED		0xFE
#define I2C_INTERRUPT_ENABLED		0x01

/* Rate of Data Transfer 100 Kb/s or 400 Kb/s */
#define TWI_DT_NORMAL_MODE			100000U
#define TWI_DT_FAST_MODE			400000U

#define TWI_PRESCALER_STATUS_CLR	0x00
#define TWI_PRESCALER_1				0x00
#define TWI_PRESCALER_4				0x01
#define TWI_PRESCALER_16			0x02
#define TWI_PRESCALER_64			0x03

#endif /* SRC_MCAL_TWI_TWI_PRIVATE_H_ */
