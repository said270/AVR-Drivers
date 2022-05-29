#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SPI_int.h"
#include "SPI_priv.h"
#include "../DIO/DIO_int.h"
void  SPI_voidMasterInit(void){
	//MOSI o/p   SCK  o/p  Others i/p
	DIO_voidSetPinDirection(PORTB,PIN4,INPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,INPUT);

	DIO_voidSetPinDirection(PORTB,PIN5,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,OUTPUT);
	//enable MSTR , enable SPI ,clk/16
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,4);
	SET_BIT(SPCR,6);

	
	
}

void   SPI_voidMasterTransmit(u8 Data){
	SPDR=Data;
	//wait till trasmission complete
	while ((GET_BIT(SPSR,7))!=1);
	
}

void SPI_voidSlaveInit(void){
	//MISO output
	DIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);
	
	DIO_voidSetPinDirection(PORTB,PIN4,INPUT);
	DIO_voidSetPinDirection(PORTB,PIN5,INPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,INPUT);
	//enable SPI
	SET_BIT(SPCR,6);
}

u8  SPI_voidSlaveRecive(void){
	
    while ((GET_BIT(SPSR,7))!=1);

	
	return SPDR;
}