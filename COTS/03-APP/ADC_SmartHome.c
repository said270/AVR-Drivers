/*
 * MAIN.C
 *
 *  Created on: ??‏/??‏/????
 *      Author: SAIED
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include "KEYPAD_interface.h"
#include <util/delay.h>

void nota(void){
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(300);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
}
void main(void){
	u8 ADCReading,KPDState=0Xff,KPDvalue;
	u16 volt,volt1;
	u8 temp;
	u8 CheckPW=0;
	u8 ID[4];
	u8 Password[4];
	u8 degree[8]={0b00000011,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
u8 empty[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
PORT_voidInit();
ADC_voidInit();
CLCD_voidInit();
GIE_voidEnable();
while (1){
CLCD_voidSendString("    WELCOME");
_delay_ms(4000);
for (u8 d=0;d<=2;d++){
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("ENTER ID:");
for(u8 a=0;a<=3;a++){
	do{
		KPDState=KEYPAD_u8GetPressedKey();
		}while(KPDState==0xff);
		KPDvalue=KPDState;
		ID[a]=KPDvalue;
		 KPDState=0xff;
	    CLCD_voidSendNumber(ID[a]);
}
CLCD_voidGoToXY(1,0);
CLCD_voidSendString("ENTER PW:");
for(u8 b=0;b<=3;b++){
	do{
		KPDState=KEYPAD_u8GetPressedKey();
		}while(KPDState==0xff);
		KPDvalue=KPDState;
		Password[b]=KPDvalue;
		 KPDState=0xff;
	    CLCD_voidSendNumber(Password[b]);
}
for (u8 c=0;c<=3;c++){
 if(ID[c]==Password[3-c])
 {
CheckPW++;
 }
}
if(CheckPW == 4){
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("     CORRECT");
	 break;
 }
else{
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("   TRY AGAIN ");
}
CheckPW=0;
if (d==2){
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("    SYSTEM SHUT ");
	CLCD_voidGoToXY(1,4);
	CLCD_voidSendString("   Down");
	_delay_ms(1000);
CLCD_voidSendCommand(0b00001000);
break;
break;
}
}
CLCD_voidSendCommand(1);
CLCD_voidSendString("LEDS=");
CLCD_voidGoToXY(1,0);
CLCD_voidSendString("TEMP=");
CLCD_voidWriteSpecialChar(degree,0,1,7);
	 	CLCD_voidGoToXY(1,8);
	 	CLCD_voidSendData('C');
 while(1){
	ADC_u8GetChannelReadingSynchronous(SINGLE_ADC0,&ADCReading);
	volt=(ADCReading*5000UL)/256UL;
	CLCD_voidGoToXY(0,5);
if(volt >0 && volt <=1300){
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_HIGH);
	CLCD_voidSendNumber(4);
}
else if(volt >1300 && volt <=2300){
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_LOW);
	CLCD_voidSendNumber(3);
}
else if(volt >2300 && volt <=3500){
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_LOW);
	CLCD_voidSendNumber(2);
}
else if(volt >3500 && volt <=4000){
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_LOW);
	CLCD_voidSendNumber(1);
}
else if(volt >4000 && volt <=5000){
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_LOW);
	CLCD_voidSendNumber(0);
}

	 ADC_u8GetChannelReadingSynchronous(SINGLE_ADC1,&ADCReading);
	 	volt1=(ADCReading*5000UL)/256UL;
	 	temp=volt1/10;
	 	CLCD_voidGoToXY(1,5);
	 	 CLCD_voidSendNumber(temp);
	 	if(temp > 25){
	 		//Motor ON
	 		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);
	 		CLCD_voidGoToXY(1,15);
	 		CLCD_voidSendData('M');
	 	}
	 	else{
	 		//Motor OFF
	 		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_LOW);
	 		CLCD_voidWriteSpecialChar(empty,1,1,15);
	 	}

 }
}
}
