/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: HAL             *****************/
/*************   SWC: CLCD                *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include <util/delay.h>

u8 Global_u8NumberOfLetters=0;
void CLCD_voidSendCommand(u8 Copy_u8Command){
	/* Set RS -> LOW for command send */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/* Set RW-> LOW for writing */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/* Put command on Data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send High Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	/*Send Low Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}
void CLCD_voidSendData(u8 Copy_u8Data){
	/* Set RS -> LOW for data send */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/* Set RW-> LOW for writing */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/* Put command on Data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send High Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	/*Send Low Enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	Global_u8NumberOfLetters++;
	/* Use a global variable for DDRAM to move to 2nd line when 1st line is complete */
	/* Shift address from 0x16 into 0x40 of 2nd line */
	if(Global_u8NumberOfLetters==16){
		CLCD_voidGoToXY(1,0);
	}
	if(Global_u8NumberOfLetters==32){
			CLCD_voidGoToXY(0,0);
			Global_u8NumberOfLetters=0;
		}
}

void CLCD_voidInit(){
	/* wait for 30 ms for power to be stable */
	_delay_ms(40);

	/* Function Set for 2 lines and 5*8 Font size */
	CLCD_voidSendCommand(0b00111000);
	_delay_us(39);

	/* Display ON and cursor OFF and no blink for cursor */
	CLCD_voidSendCommand(0b00001100);
	_delay_us(39);

	/* clear display */
	CLCD_voidSendCommand(0b00000001);
	_delay_ms(2);



}
void CLCD_voidSendString(const char * Copy_pcString){
	u8 Local_u8CharNumber=0,Local_u8Count=0;
	for(Local_u8CharNumber=0 ; ; Local_u8CharNumber++ ){
		if (*(Copy_pcString + Local_u8CharNumber) == '\0'){
			break;
		}
	}
	for(Local_u8Count=0 ; Local_u8Count <Local_u8CharNumber ; Local_u8Count++ ){
		CLCD_voidSendData(*(Copy_pcString + Local_u8Count));
		if(Local_u8Count==15){
			CLCD_voidGoToXY(1,0);
		}
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos){
	u8 Local_u8Address;
	/* Location at first line */
	if (Copy_u8XPos==0){
		Local_u8Address=Copy_u8YPos;
	}
	/* Location at second line */
	else if (Copy_u8XPos==1){
		Local_u8Address=Copy_u8YPos+0x40;
	}
	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidWriteSpecialChar(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos,u8 Copy_u8YPos){
	u8 Local_u8Iterator;
	/* Get CGRAM address */
	u8 Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
	/* Access CGRAM ( Send CGRAM address to LCD ) */
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);
	/* Write Data to CGRAM */
	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++){
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/* Go to User definded postion so we have to access DDRAM */
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	/* Write on DDRAM */
	CLCD_voidSendData(Copy_u8PatternNumber);
}
void CLCD_voidSendNumber(u32 Copy_u32Number){
	u8 Local_u8ArrayOfDigits[32];
	u8 Local_u8Numberofdigits=0;
	u8 Local_u8Digit;
	u32 Local_u32Copy=Copy_u32Number;
	u8 Local_u8Size=0;
	while (Local_u32Copy!=0){
		Local_u32Copy=Local_u32Copy/10;
		Local_u8Size++;
	}
	while (Copy_u32Number!=0){
		Local_u8Digit=Copy_u32Number%10;
		Copy_u32Number=Copy_u32Number/10;
		Local_u8ArrayOfDigits[Local_u8Size]=Local_u8Digit;
		Local_u8Numberofdigits=Local_u8Numberofdigits+1;
		Local_u8Size=Local_u8Size-1;
	}

for (u8 i =1 ; i <=Local_u8Numberofdigits ; i++ ){
	CLCD_voidSendData(Local_u8ArrayOfDigits[i]+48);
}
}
