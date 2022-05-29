#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_int.h"

#include <util/delay.h>
void LCD_voidSendCMD(u8 CMD){
	DIO_voidSetPinValue(Control_PORT    ,   RS,    LOW);
	DIO_voidSetPinValue(Control_PORT    ,   RW,    LOW);
	DIO_voidSetPortValue(DATA_PORT  , CMD);
	DIO_voidSetPinValue(Control_PORT    ,   EN,    HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(Control_PORT    ,   EN,    LOW);
	_delay_ms(2);
}

void LCD_void4bitInit(void){
	_delay_ms(35);
	//Function set
	LCD_voidSendCMD(0b00100000);
	LCD_voidSendCMD(0b00100000);
	LCD_voidSendCMD(0b10000000);
	_delay_ms(1);
	//ON/OFF Display
	LCD_voidSendCMD(0b00000000);
	LCD_voidSendCMD(0b11000000);
	_delay_ms(1);
	//Clear display
	LCD_voidSendCMD(0b00000000);
	LCD_voidSendCMD(0b00010000);
	_delay_ms(2);
	//Entry mode
	LCD_voidSendCMD(0b00000000);
	LCD_voidSendCMD(0b01100000);
	_delay_ms(2);



}

void LCD_voidWriteChar4bit(u8 Data){
	DIO_voidSetPinValue(Control_PORT    ,   RS,   HIGH);
	DIO_voidSetPinValue(Control_PORT    ,   RW,    LOW);
	DIO_voidSetPinValue(DATA_PORT,PIN4,GET_BIT(Data,0));
	DIO_voidSetPinValue(DATA_PORT,PIN5,GET_BIT(Data,1));
	DIO_voidSetPinValue(DATA_PORT,PIN6,GET_BIT(Data,2));
	DIO_voidSetPinValue(DATA_PORT,PIN7,GET_BIT(Data,3));
	DIO_voidSetPinValue(Control_PORT    ,   EN,    HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(Control_PORT    ,   EN,    LOW);
    _delay_ms(2);
	DIO_voidSetPinValue(DATA_PORT,PIN4,GET_BIT(Data,4));
	DIO_voidSetPinValue(DATA_PORT,PIN5,GET_BIT(Data,5));
	DIO_voidSetPinValue(DATA_PORT,PIN6,GET_BIT(Data,6));
	DIO_voidSetPinValue(DATA_PORT,PIN7,GET_BIT(Data,7));
	DIO_voidSetPinValue(Control_PORT    ,   EN,    HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(Control_PORT    ,   EN,    LOW);
	_delay_ms(2);

}

void LCD_voidInit(void)
{
	// wait for VDD to rise to 4.5
	_delay_ms(35);
	//function set command 
	LCD_voidSendCMD(0b00111000);
	_delay_ms(1);
	//display on/off command
	LCD_voidSendCMD(0b00001100);
	_delay_ms(1);
	//clear display command
	LCD_voidSendCMD(0b00000001);
	_delay_ms(2);
	//Entry mode command
	LCD_voidSendCMD(0b00000110);
	
	
}

void LCD_voidWriteChar(u8 Data){
	DIO_voidSetPinValue(Control_PORT    ,   RS,   HIGH);
	DIO_voidSetPinValue(Control_PORT    ,   RW,    LOW);
	DIO_voidSetPortValue(DATA_PORT  , Data);
	DIO_voidSetPinValue(Control_PORT    ,   EN,    HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(Control_PORT    ,   EN,    LOW);
	_delay_ms(2);
	
}
void LCD_voidWriteString(u8 String[]){

	for (u8 i=0;i<=20;i++){
		if (String[i]=='\0'){
			break;
		}

	LCD_voidWriteChar(String[i]);

	}

}
void LCD_voidGoToXY(u8 Copy_u8LineNm,u8 Copy_u8CharNm){
	if (Copy_u8LineNm==1){
		LCD_voidSendCMD(0x80+Copy_u8CharNm);
	}
	else if (Copy_u8LineNm==2){
		LCD_voidSendCMD(0xC0+Copy_u8CharNm);
	}
}
void LCD_voidWriteIntegar(u32 Data){
	/*we have to transform this data into known numbers each of 0-9
	range in order for LCD to understand*/
	u8 DataArray[50];
	u8 Size=0;
	u8 Number;
	while (Data !=0){
		Number=Data%10;
		Data=Data/10;
		DataArray[Size]=Number;
		Size++;
	}
	//48 s the address of zero
	for (s16 i=Size-1;i>=0;i--){
		LCD_voidWriteChar(DataArray[i]+48);
	}


}
