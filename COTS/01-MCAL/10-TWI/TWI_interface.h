/*********************************************************************/
/*********************************************************************/
/******** Author:    Saied Kamara   ***********************************/
/******** Component: TWI           ***********************************/
/******** Layer:     MCAL          ***********************************/
/******** Version:   1.0           ***********************************/
/*********************************************************************/
/*********************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum {
	Noerr,
	StartConditionErr,
	RepeatedStartConditionErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MaterWriteByteErr,
	MaterReadByteWithACKErr,
}TWI_ErrorStatus;

/* Pass 0  to slave address if master will not be addressed */
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_SendStartCondition(void);
TWI_ErrorStatus TWI_SendRepeatedStart(void);

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);
TWI_ErrorStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

void TWI_SendStopCondition(void);

#endif
