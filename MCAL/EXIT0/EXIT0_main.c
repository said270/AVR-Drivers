#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../GIE/GIE_INT.h"
#include "EXIT0_int.h"
#include <util/delay.h>

#define  NULL                 ( void * )0
//pointer to function
//void (*pf)(void)= NULL

void  Toggle (void){

	DIO_voidSetPinValue(PORTA,PIN0,HIGH);
	_delay_ms(500);
	DIO_voidSetPinValue(PORTA,PIN0,LOW);
	_delay_ms(500);
	
}

int main (void){
	
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	DIO_voidSetPinValue(PORTD,PIN2,HIGH);
	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	EXIT0_voidSetCallBack (Toggle);
	EXIT0_voidInit();
	EXIT0_voidEnable();
	GIE_voidEnable();
	
	
	while(1){
		
	}
	
	
	
	
	
	
	return 0 ;
}
