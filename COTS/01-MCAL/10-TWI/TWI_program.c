/*********************************************************************/
/*********************************************************************/
/******** Author:    Saied Kamara   ***********************************/
/******** Component: TWI           ***********************************/
/******** Layer:     MCAL          ***********************************/
/******** Version:   1.0           ***********************************/
/*********************************************************************/
/*********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress){
	/* Set Clock Freq to 400kbps */
	/*Set TWBR to 2 */
	TWBR=2;
	/* Clear 2 bits of TWBS */
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/* Set Slave Address for this master if to recive anytime */
	if(Copy_u8SlaveAddress !=0){
		TWAR= (Copy_u8SlaveAddress<<1) ;
	}

	/*Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);

}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress){
	/* Intialize address */
	TWAR= (Copy_u8SlaveAddress<<1) ;
	/*Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrorStatus TWI_SendStartCondition(void){
	TWI_ErrorStatus Local_ErrorStatus =Noerr;
	/* Send Start Condition on Bus */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear The interrupt flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until flag is risen again for operation complete */
	while ((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check that operation is completed proberly */
	/* We musk the first 3 bits */
	if ((TWSR & 0xF8) != START_ACK){
		Local_ErrorStatus=StartConditionErr;

	}
	else{

	}

	return Local_ErrorStatus;
}
TWI_ErrorStatus TWI_SendRepeatedStart(void){
	TWI_ErrorStatus Local_ErrorStatus =Noerr;
	/* Send Start Condition on Bus */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear The interrupt flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until flag is risen again for operation complete */
	while ((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check that operation is completed proberly */
	/* We musk the first 3 bits */
	if ((TWSR & 0xF8) != REP_START_ACK){
		Local_ErrorStatus=RepeatedStartConditionErr;

	}
	else{

	}

	return Local_ErrorStatus;
}
TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress){
	TWI_ErrorStatus Local_ErrorStatus =Noerr;

	/* Clear Start Condion bit : a must in Data sheet after each operation to clear the previous's bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Set The slave Address int the 7 MSBs */
	TWDR=Copy_u8SlaveAddress <<1 ;
	/* Choose to write in bit 0 */
	CLR_BIT(TWDR,0);

	/* Clear The interrupt flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until flag is risen again for operation complete */
	while ((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check that operation is completed proberly */
	/* We musk the first 3 bits */
	if ((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK){
		Local_ErrorStatus=SlaveAddressWithWriteErr;

	}
	else{

	}

	return TWI_ErrorStatus;
}
TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress){
	TWI_ErrorStatus Local_ErrorStatus =Noerr;

	/* Clear Start Condion bit : a must in Data sheet after each operation to clear the previous's bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Set The slave Address int the 7 MSBs */
	TWDR=Copy_u8SlaveAddress <<1 ;
	/* Choose to read in bit 0 */
	SET_BIT(TWDR,0);
	/* Clear The interrupt flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until flag is risen again for operation complete */
	while ((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check that operation is completed proberly */
	/* We musk the first 3 bits */
	if ((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK){
		Local_ErrorStatus=SlaveAddressWithReadErr;

	}
	else{

	}

	return TWI_ErrorStatus;
}

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte){
	TWI_ErrorStatus Local_ErrorStatus =Noerr;

	/*Put Data in Data Register */
	TWDR=Copy_u8DataByte;

	/* Clear The interrupt flag to Start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until flag is risen again for operation complete */
	while ((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check that operation is completed proberly */
	/* We musk the first 3 bits */
	if ((TWSR & 0xF8) != MSTR_WR_BYTE_ACK){
		Local_ErrorStatus=MaterWriteByteErr;

	}
	else{

	}

	return TWI_ErrorStatus;

	return TWI_ErrorStatus;
}

TWI_ErrorStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte){
	TWI_ErrorStatus Local_ErrorStatus =Noerr;

	/*Enable Master Generating ACK after reciveing data */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Clear The interrupt flag to Start the Reciveing ( Slave Sending Data )*/
	SET_BIT(TWCR,TWCR_TWINT);

	/* wait until flag is risen again for operation complete */
	while ((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/*Check that operation is completed proberly */
	/* We musk the first 3 bits */
	/* we check Reading with ACK */
	if ((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK){
		Local_ErrorStatus=MaterReadByteWithACKErr;

	}
	else{
		/*Read Data from register  */
		*Copy_pu8DataByte = TWDR;
	}


	return TWI_ErrorStatus;
}

void TWI_SendStopCondition(void){
	/* Set stop Condition Bit */
	SET_BIT(TWCR,TWCR_TWSTO);

	/* Clear The interrupt flag to start the operation	*/
	SET_BIT(TWCR,TWCR_TWINT);
	/* you now Left the network so we not checking status */
}
