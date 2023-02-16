/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: PORT               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"

void PORT_voidInit(){
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
	
	PORTA=PORTA_Value;
	PORTB=PORTB_Value;
	PORTC=PORTC_Value;
	PORTD=PORTD_Value;
}