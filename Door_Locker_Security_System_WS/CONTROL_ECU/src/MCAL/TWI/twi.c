/*******************************************************************************
 *
 *  [   Module  ]: TWI Module
 *
 *  [ File Name ]: twi.c
 *
 *  [Description]: Source file for the TWI AVR driver
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  Includes
 *******************************************************************************/

#include "twi.h"
#include "twi_private.h"

/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/

/*
 * [Description]: Pointer To Function Save the Address Of The function
 *                That will called when Event or interrupt occur .
 */
static volatile void(*g_Ptr_To_Fun_TWI)(void) = NULL_PTR;

/*******************************************************************************
 *                                 TWI_ISR
 *******************************************************************************/

/*
 * [Description]: The ISR's specific For TWI Interrupt Enable
 */
ISR(TWI_vect)
{
	/* Call the Call Back function in the application after the Event is Occur */
	if(g_Ptr_To_Fun_TWI != NULL_PTR)
	{
		/* This is called --> Call Back Notification */
		/* another method to call the function using pointer to function g_Ptr_To_Fun_TWI(); */
		(*g_Ptr_To_Fun_TWI)();
	}
}

/*******************************************************************************
 *                      	Functions Definitions
 *******************************************************************************/

/*
 * [Function Name]: TWI_init
 * [Description]  : Functional responsible for Initialize the TWI device.
 * [Args]  : Void
 * [Return]: Void
 */
void TWI_init(void)
{
	/* Clear The Status Register and Choose Prescaler */
	TWSR_REG = TWI_PRESCALER_SELECTOR;

	TWBR_REG = BITRATE; /* Set Bit Rate */

#if TWI_INT_EN == ENABLE
	TWCR_REG |= I2C_INTERRUPT_ENABLED; /* Enable TWI Interrupt */
#elif TWI_INT_EN == DISABLE
	TWCR_REG |= I2C_INTERRUPT_ENABLED; /* Disable TWI Interrupt */
#endif

	/* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
	       General Call Recognition: Off */
	TWAR_REG = TWI_MY_ADDRESS;

	TWCR_REG = (1<<TWCR_TWEN); /* enable TWI */
}

/*
 * [Function Name]: TWI_start
 * [Description]  : Functional responsible for Send Start Condition to the Slave.
 * [Args]  : Void
 * [Return]: Enum
 */
TWI_Retuens_t TWI_start(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWSTA) | (1<<TWCR_TWEN);

	 /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
	while(!(TWCR_REG & (1<<TWCR_TWINT)));

	if((TWI_getStatus()) != TWI_START_STATE) /* check for Start condition Sent */
	{
		return START_NOT_SENT;
	}
	else
	{
		return EVENT_OK;
	}
}

/*
 * [Function Name]: TWI_repeatedStart
 * [Description]  : Functional responsible for Send repeated Start Condition to the Slave.
 * [Args]  : Void
 * [Return]: Enum
 */
TWI_Retuens_t TWI_repeatedStart(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWSTA) | (1<<TWCR_TWEN);

	 /* Wait for TWINT flag set in TWCR Register (repeated start bit is send successfully) */
	while(!(TWCR_REG & (1<<TWCR_TWINT)));

	if((TWI_getStatus()) != TWI_REPEATED_START_STATE) /* check for Repeated Start condition Sent */
	{
		return REPEATED_START_NOT_SENT;
	}
	else
	{
		return EVENT_OK;
	}
}

/*
 * [Function Name]: TWI_addressSelect
 * [Description]  : Functional responsible for the address with write or read bit to the Slave.
 * [Args]  : 1- uint8 to take the address
 * 			 2- Enum to select write or read Mode
 * [Return]: Enum
 */
TWI_Retuens_t TWI_addressSelect(uint8 address, TWI_Mode_t rw)
{
	if(rw == TWI_WRITE_MODE)
	{
		TWDR_REG = address + TWI_WRITE_MODE; /* Put SLA+W On TWI data Register */
	}
	else if(rw == TWI_READ_MODE)
	{
		TWDR_REG = address + TWI_READ_MODE; /* Put SLA+R On TWI data Register */
	}
	else{}

    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

	/* Wait for TWINT flag set in TWCR Register(data is send successfully) */
	while(!(TWCR_REG & (1<<TWCR_TWINT)));

	if((TWI_getStatus()) == TWI_MT_SLA_W_ACK_STATE) /* check for SLA+W transmitted & ACK received */
	{
		return SLA_W_ACK_SENT;
	}
	else if((TWI_getStatus()) == TWI_MT_SLA_W_NACK_STATE) /* check for SLA+W transmitted & NACK received */
	{
		return SLA_W_NACK_SENT;
	}

	if((TWI_getStatus()) == TWI_MT_SLA_R_ACK_STATE) /* check for SLA+R transmitted & ACK received */
	{
		return SLA_R_ACK_SENT;
	}
	else if((TWI_getStatus()) == TWI_MT_SLA_R_NACK_STATE) /* check for SLA+R transmitted & NACK received */
	{
		return SLA_R_NACK_SENT;
	}
	else
	{
		return SLA_RW_FAILED;
	}
}

/*
 * [Function Name]: TWI_dataEvent
 * [Description]  : Functional responsible for Send and receive with ACK or NACK Data.
 * [Args]  : 1- pointer to uint8 to send or receive the data
 * 			 2- Enum to select write or read Mode
 * 			 3- Enum to select after transmit or receive the data send ACK or NACK
 * [Return]: Enum
 */
TWI_Retuens_t TWI_dataEvent(uint8 *data, TWI_Mode_t rw, TWI_ACK_t ack)
{
	if(rw == TWI_WRITE_MODE)
	{
		TWDR_REG = *data; /* Put data On TWI data Register */

	    /*
		 * Clear the TWINT flag before sending the data TWINT=1
		 * Enable TWI Module TWEN=1
		 */
		TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

		/* Wait for TWINT flag set in TWCR Register(data is send successfully) */
		while(!(TWCR_REG & (1<<TWCR_TWINT)));

		if((TWI_getStatus()) == TWI_MT_DATA_W_ACK_STATE) /* check for Data transmitted & ACK received */
		{
			return DATA_WRITE_ACK_SENT;
		}
		else if((TWI_getStatus()) == TWI_MT_DATA_W_NACK_STATE) /* check for Data transmitted & NACK received */
		{
			return DATA_WRITE_NACK_SENT;
		}
		else
		{
			return DATA_WRITE_FAILED;
		}
	}
	else if(rw == TWI_READ_MODE)
	{
		if(ack == ACK)
		{
			/*
			 * Clear the TWINT flag before reading the data TWINT=1
			 * Enable sending ACK after reading or receiving data TWEA=1
			 * Enable TWI Module TWEN=1
			 */
			TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWEA) | (1<<TWCR_TWEN);
		}
		else if(ack == NACK)
		{
		     /*
			 * Clear the TWINT flag before reading the data TWINT=1
			 * Enable TWI Module TWEN=1
			 */
			TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
		}

		/* Wait for TWINT flag set in TWCR Register(data is received successfully) */
		while(!(TWCR_REG & (1<<TWCR_TWINT)));

		*data = TWDR_REG; /* Read Data */

		if((TWI_getStatus()) == TWI_MR_DATA_R_ACK_STATE) /* check for Data & ACK received */
		{
			return DATA_READ_ACK_SENT; /* return to indicate ACK received */
		}
		else if((TWI_getStatus()) == TWI_MR_DATA_R_NACK_STATE) /* check for Data transmitted & NACK received */
		{
			return DATA_READ_NACK_SENT; /* return to indicate NACK received */
		}
		else
		{
			return DATA_READ_FAILED; /* else return for data transmission failure */
		}
	}
	else
	{
		return DATA_RW_FAILED;
	}
}

/*
 * [Function Name]: TWI_stop
 * [Description]  : Functional responsible for Send Stop Condition to the Slave.
 * [Args]  : Void
 * [Return]: Void
 */
void TWI_stop(void)
{
    /*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_REG = (1<<TWCR_TWINT) | (1<<TWCR_TWSTO) | (1<<TWCR_TWEN);

	 /* Wait for TWSTO is clear in TWCR Register (stop bit is send successfully) */
	while(TWCR_REG & (1<<TWCR_TWSTO));
}

/*
 * [Function Name]: TWI_getStatus
 * [Description]  : Functional responsible for Get the STatus of the TWI logic and the Two-wire Serial Bus.
 * [Args]  : void
 * [Return]: uint8
 */
uint8 TWI_getStatus(void)
{
	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	return (TWSR_REG & 0xF8);
}

/*
* [Function Name]: TWI_SetCallBack
* [Description]  : This function's is responsible to set the Call Back function address.
* [Args]  : Pointer To Function take void and return void
* [Return]: Void
*/
void TWI_SetCallBack(void (*Ptr_To_fun)(void))
{
	g_Ptr_To_Fun_TWI = (volatile void *)Ptr_To_fun;
}
