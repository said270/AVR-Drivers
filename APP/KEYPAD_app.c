#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/DIO/DIO_int.h"
#include "../LCD/LCD_int.h"

#include "KEYPAD_int.h"
#include <util/delay.h>
u8 KEYPAD_u8Switch[4][4]={{'1','2','3','+'},
		{'4','5','6','-'},
		{'7','8','9','*'},
		{'=','0','.','/'}};

u8 KEYPAD_u8GetPressedKey(void){
	//as it returns we should initialize values to be sure no key is used
	u8 LOC_u8Return=0xFF;
	u8 LOC_u8Column=0;
	u8 LOC_u8ROW=0;


	for (LOC_u8Column=0; LOC_u8Column<4; LOC_u8Column++)
	{	
		DIO_voidSetPinValue(KEYPAD_PORT,LOC_u8Column,LOW);
		for (LOC_u8ROW=4;LOC_u8ROW<8;LOC_u8ROW++){
			if(DIO_u8GetPinValue(KEYPAD_PORT  , LOC_u8ROW)==0) {
				LOC_u8Return=KEYPAD_u8Switch[LOC_u8ROW-4][(LOC_u8Column)];
				while (DIO_u8GetPinValue(KEYPAD_PORT  , LOC_u8ROW)==0);
				_delay_ms(5);
			}

		}
		DIO_voidSetPinValue(KEYPAD_PORT,LOC_u8Column,HIGH);
	}
	return LOC_u8Return;
}
