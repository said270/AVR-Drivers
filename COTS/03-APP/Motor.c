/*
 * main.c
 *
 *  Created on: 7/11/2022
 *      Author: SAIED
 */

#include <stdio.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KEYPAD_interface.h"


void main(void) {

	PORT_voidInit();
	CLCD_voidInit();
	u8 current=0xff,Motor_Type,Spin_Type,angle,iteration,steps;
	u8 arr[8]={0b00001110,0b00001010,0b00001110,0b00000100,0b00011111,0b00000100,0b00000100,0b00011111};


	while (1){
		// Hamoksha //
		/*for (u8 i= 0 ; i<=15;i++){
	CLCD_voidSendCommand(0b00000001);
	CLCD_voidWriteSpecialChar(arr,0,0,i);
	_delay_ms(200);
	}*/
		Spin_Type=0; Motor_Type=0; angle=0; iteration=0; steps=0;
		CLCD_voidSendString("Welcome To Motor APP");
		_delay_ms(3000);
		CLCD_voidSendCommand(0b00000001);
		_delay_ms(100);
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("1 - DC MOTOR");
		_delay_ms(100);
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("2 - Stepper");

		do{
			current=KEYPAD_u8GetPressedKey();
		} while(current == 0xff);
		Motor_Type=current;
		current = 0xff;
		// DC Motor
		if(Motor_Type==1){
			CLCD_voidSendCommand(0b00000001);
			_delay_ms(50);
			CLCD_voidGoToXY(0,0);
			_delay_ms(100);
			CLCD_voidSendString("1 -CW");
			CLCD_voidGoToXY(1,0);
			_delay_ms(100);
			CLCD_voidSendString("2 -ACW");
			do{
				current=KEYPAD_u8GetPressedKey();
			} while(current == 0xff);
			Spin_Type=current;
			current=0xff;
			if (Spin_Type == 1){
				while (1){
					DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
					CLCD_voidSendCommand(0b00000001);
					_delay_ms(100);
					CLCD_voidSendString("Press 1 To Return ");
					do{
						current=KEYPAD_u8GetPressedKey();
					} while(current == 0xff);

					if(current==1){
						DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
						CLCD_voidSendCommand(0b00000001);
						_delay_ms(100);
						break;
					}

				}
				current = 0xff;
			}
			else if(Spin_Type == 2){
				while (1){
					DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
					CLCD_voidSendCommand(0b00000001);
					_delay_ms(100);
					CLCD_voidSendString("Press 1 To Return ");
					do{
						current=KEYPAD_u8GetPressedKey();
					} while(current == 0xff);

					if(current==1){
						DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
						DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
						CLCD_voidSendCommand(0b00000001);
						_delay_ms(100);
						break;
					}
				}

			}
			current = 0xff;
		}

		// Steeper
		else if(Motor_Type==2){
			CLCD_voidSendCommand(0b00000001);
			_delay_ms(100);
			CLCD_voidGoToXY(0,0);
			_delay_ms(100);
			CLCD_voidSendString("Please Enter Angle :");
			do{
				current=KEYPAD_u8GetPressedKey();
			} while(current == 0xff);
			angle =current;
			current=0xff;
			steps=angle*5.7;
			iteration=steps/4;
			for( u8 loop = 0 ; loop<=iteration;loop++){
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_HIGH);
				_delay_ms(10);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_HIGH);
				_delay_ms(10);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_HIGH);
				_delay_ms(10);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_LOW);
				_delay_ms(10);
			}
			CLCD_voidSendCommand(0b00000001);
			_delay_ms(100);
			CLCD_voidSendString("Finished");
			_delay_ms(1000);
			CLCD_voidSendCommand(0b00000001);
			_delay_ms(100);
		}
		/*
     // Clock wise
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
	_delay_ms(2000);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
	_delay_ms(2000);
	// Anto Clock wise
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(2000);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
		_delay_ms(2000);
		 */
	}
}

