/*******************************************************************************
 *
 *  [   Module  ]: External EEPROM
 *
 *  [ File Name ]: external_eeprom.c
 *
 *  [Description]: Source file for the External EEPROM Memory
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  Includes
 *******************************************************************************/

#include "external_eeprom.h"
#include "../../MCAL/TWI/twi.h"

/*******************************************************************************
 *                      	Functions Definitions
 *******************************************************************************/

/*
 * [Function Name]: EEPROM_init
 * [Description]  : Functional responsible for Initialize the external EEPROM 24C16.
 * [Args]  : void
 * [Return]: void
 */
void EEPROM_init(void)
{
	TWI_init();
}

/*
 * [Function Name]: EEPROM_writeByte
 * [Description]  : Functional responsible for write data byte for external EEPROM 24C16.
 * [Args]  : 1- uint16
 * 			 2- uint8
 * [Return]: uint8
 */
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data)
{
	/* Send the Start Bit */
	if(TWI_start() != EVENT_OK)
		return ERROR;

	/* Send the device address, we need to get A8 A9 A10 address bits from the
	 * memory location address and R/W=0 (write) */
	if(TWI_addressSelect((uint8)(0xA0|((u16addr & 0x0700)>>7)), TWI_WRITE_MODE) != SLA_W_ACK_SENT)
		return ERROR;

	 /* Send the required memory location address */
	if(TWI_dataEvent((uint8 *)&u16addr, TWI_WRITE_MODE, ACK) != DATA_WRITE_ACK_SENT)
		return ERROR;

	/* write byte to eeprom */
	if(TWI_dataEvent(&u8data, TWI_WRITE_MODE, ACK) != DATA_WRITE_ACK_SENT)
		return ERROR;

	/* Send the Stop Bit */
	TWI_stop();

	return SUCCESS;
}

/*
 * [Function Name]: EEPROM_writeByte
 * [Description]  : Functional responsible for read data byte for external EEPROM 24C16.
 * [Args]  : 1- uint16
 * 			 2- pointer to uint8
 * [Return]: uint8
 */
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data)
{
	/* Send the Start Bit */
	if(TWI_start() != EVENT_OK)
		return ERROR;

	/* Send the device address, we need to get A8 A9 A10 address bits from the
	 * memory location address and R/W=0 (write) */
	if(TWI_addressSelect((uint8)(0xA0|((u16addr & 0x0700)>>7)), TWI_WRITE_MODE) != SLA_W_ACK_SENT)
		return ERROR;

	 /* Send the required memory location address */
	if(TWI_dataEvent((uint8 *)&u16addr, TWI_WRITE_MODE, ACK) != DATA_WRITE_ACK_SENT)
		return ERROR;

	/* Send the Repeated Start Bit */
	if(TWI_repeatedStart() != EVENT_OK)
		return ERROR;

	/* Send the device address, we need to get A8 A9 A10 address bits from the
	 * memory location address and R/W=1 (Read) */
	if(TWI_addressSelect((uint8)(0xA0|((u16addr & 0x0700)>>7)), TWI_READ_MODE) != SLA_R_ACK_SENT)
		return ERROR;

	/* Read Byte from Memory without send ACK */
	if(TWI_dataEvent(u8data, TWI_READ_MODE, NACK) != DATA_READ_NACK_SENT)
		return ERROR;

	/* Send the Stop Bit */
	TWI_stop();

	return SUCCESS;
}
