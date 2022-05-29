#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include "WDT_int.h"
#include <util/delay.h>


int main(void) {
	
DIO_voidSetPortDirection(PORTB,OUTPUTPORT);
WDT_voidEnable(WD_TIME_2_s);
DIO_voidSetPinValue(PORTB,PIN0,HIGH);
_delay_ms(1000);
WDT_voidDisable();
DIO_voidSetPinValue(PORTB,PIN0,LOW);
_delay_ms(1000);

while (1){
	DIO_voidSetPinValue(PORTB,PIN1,HIGH);
	_delay_ms(1000);

	DIO_voidSetPinValue(PORTB,PIN1,LOW);
	_delay_ms(1000);

}


return 0;
}
