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

u16 Power (u16 number , u16 power ){
	if (power == 0 ){
		return 1;
	}
	for (u8 m=1;m<power;m++){
		number = number * number;
	}
	return number;
}

void main(void) {
	u8 Negative[8]={0b00000000,0b00000000,0b00000000,0b00011111,0b00000000,0b00000000,0b00000000,0b00000000};
	u8 current;
	u16 Number1[10],Number2[10],Num1=0,Num2=0,result=0,assign;
	u8 i=0,a=0,b=0,c=0,d=0;
	PORT_voidInit();
	CLCD_voidInit();
    u8 y=0;
	while (1)
	{
		for (i=0 ; i<=10 ;i++){
			do{
				current=KEYPAD_u8GetPressedKey();
			}while(current == 0xff);
			if (current == '+' || current == '-' || current == '*' || current == '/'){
				assign = current;
				CLCD_voidSendData(assign);
				y++;
				break;
			}
			CLCD_voidSendNumber(current);
			y++;
			Number1[i]=current;
		}
		b=i;
		for (a=0 ; a <= b; a++){
			i--;
			Num1=Num1 + Number1[a] * Power(10,i);
		}
		//CLCD_voidSendNumber(Num1);

		for (i=0 ; i<=10 ;i++){
			do{
				current=KEYPAD_u8GetPressedKey();
			}while(current == 0xff);
			if (current == '='){
				CLCD_voidSendData(current);
				y++;
				break;
			}
			CLCD_voidSendNumber(current);
			y++;
			Number2[i]=current;
		}
		b=i;
		for (a=0 ; a <= b; a++){
			i--;
			Num2=Num2 + Number2[a] * Power(10,i);
		}
		//CLCD_voidSendNumber(Num2);
		if(assign == '+'){
			result=Num1+Num2;
		}
		else if (assign == '-'){
			result=Num1-Num2;
		}
		else if (assign == '*'){
					result=Num1*Num2;
				}
		else if (assign == '/'){
					result=Num1/Num2;
				}
		if (Num2 > Num1){
			CLCD_voidWriteSpecialChar(Negative,0,0,y);
			result = Num2-Num1;
		}
		CLCD_voidSendNumber(result);
		_delay_ms(6000);
	}
}
