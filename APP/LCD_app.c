#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/DIO/DIO_int.h"
#include "../../LCD_int.h"

#include <util/delay.h>

int main (){
	DIO_setPortDirection(PORTA,OUTPUTPORT);
	DIO_setPortDirection(PORTD,OUTPUTPORT);
	
	LCD_voidInit;
	LCD_voidWritechar('A');
	while (1)
	{
		
	}
	return 0;
	
}