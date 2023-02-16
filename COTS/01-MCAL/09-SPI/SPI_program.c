/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: SPI               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"

void SPI_voidMasterInit(){
	/*Set master */
	SET_BIT(SPCR,SPCR_MSTR);

	/*Set CLK prescalar div_by_16 */
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	/* SPI enable */
	SET_BIT(SPCR,SPCR_SPE);

	/* Data Order by defualt */
	/* Clock polarity and phase by defualt */
}
void SPI_voidSlaveInit(){
	/* SPI enable */
	SET_BIT(SPCR,SPCR_SPE);
	/*Set slave */
	CLR_BIT(SPCR,SPCR_MSTR);

}
u8  SPI_u8tranceiver(u8 Copy_u8Data){
	/*Put data to Master's SPDR */
	SPDR=Copy_u8Data;
	/*Wait for data to be sent */
	while (GET_BIT(SPSR,SPSR_SPIF) == 0);
	/*Read the recived data */
     return SPDR;

}
