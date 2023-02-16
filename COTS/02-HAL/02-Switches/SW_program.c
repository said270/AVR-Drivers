#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "SW_interface.h"

u8 SW_u8GetState(u8 SW_u8PORT, u8 SW_u8PIN , u8 SW_u8LockingType,u8 SW_u8PullType){
	u8 Local_u8Sate;
	u8 Local_u8Value;
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_u8GetPinValue(SW_u8PORT,SW_u8PIN,&Local_u8Value);
	if(SW_u8LockingType == SW_u8SelfLocked)
	{
		if (SW_u8PullType == SW_u8PullDown){
			if(Local_u8Value==DIO_u8PIN_HIGH){
				Local_u8Sate=SW_u8Pressed;
			}
			else if(Local_u8Value==DIO_u8PIN_LOW){
				Local_u8Sate=SW_u8NotPressed;
			}
		}
		if (SW_u8PullType == SW_u8PullUp){
			if(Local_u8Value==DIO_u8PIN_HIGH){
				Local_u8Sate=SW_u8NotPressed;
			}
			else if(Local_u8Value==DIO_u8PIN_LOW){
				Local_u8Sate=SW_u8Pressed;
			}
		}

	}
	else if(SW_u8LockingType == SW_u8NotSelfLocked)
		{
			if (SW_u8PullType == SW_u8PullDown){
				if(Local_u8Value==DIO_u8PIN_HIGH){
					Local_u8Sate=SW_u8Pressed;
				}
				else if(Local_u8Value==DIO_u8PIN_LOW){
					Local_u8Sate=SW_u8NotPressed;
				}
			}
			if (SW_u8PullType == SW_u8PullUp){
				if(Local_u8Value==DIO_u8PIN_HIGH){
					Local_u8Sate=SW_u8NotPressed;
				}
				else if(Local_u8Value==DIO_u8PIN_LOW){
					Local_u8Sate=SW_u8Pressed;
				}
			}
         _delay_ms(100);
		}
	return Local_u8Sate;
}
