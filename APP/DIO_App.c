#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include <util/delay.h>


int main(void)
{
	DIO_voidSetPinDirection(PORTA , PIN0 , OUTPUT);
	while(1)
	{
		DIO_voidSetPinValue(PORTA , PIN0 , HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA , PIN0 , LOW);
		_delay_ms(1000);
		
		
	}
	return 0;
}