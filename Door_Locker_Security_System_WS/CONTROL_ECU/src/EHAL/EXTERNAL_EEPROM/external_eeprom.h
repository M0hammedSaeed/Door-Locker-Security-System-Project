/*******************************************************************************
*
*  [   Module  ]: External EEPROM
*
*  [ File Name ]: external_eeprom.h
*
*  [Description]: Header File for the External EEPROM Memory
*
*  [   Author  ]: Mohamed Saeed
*
*******************************************************************************/

#ifndef SRC_EHAL_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_
#define SRC_EHAL_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_

/*******************************************************************************
*                                  INCLUDES
*******************************************************************************/

#include "../../utils/std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * [Function Name]: EEPROM_init
 * [Description]  : Functional responsible for Initialize the external EEPROM 24C16.
 * [Args]  : void
 * [Return]: void
 */
void EEPROM_init(void);

/*
 * [Function Name]: EEPROM_writeByte
 * [Description]  : Functional responsible for write data byte for external EEPROM 24C16.
 * [Args]  : 1- uint16
 * 			 2- uint8
 * [Return]: uint8
 */
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);

/*
 * [Function Name]: EEPROM_writeByte
 * [Description]  : Functional responsible for read data byte for external EEPROM 24C16.
 * [Args]  : 1- uint16
 * 			 2- pointer to uint8
 * [Return]: uint8
 */
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);

#endif /* SRC_EHAL_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_ */
