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
#include "GIE_interface.h"
#include "CLCD_interface.h"
#include "TIMER_interface.h"

/*void PWM1(void){

	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter==2){
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_LOW);
	}
	else if (Local_u8Counter==17)
			{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_LOW);

			}
		else if (Local_u8Counter==20)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_HIGH);
			Local_u8Counter=0;
		}

}*/
static u16 RISING_Reading1=0;
static u16 RISING_Reading2=0;
static u16 FALLING_Reading3=0;
static u16 Period_Ticks=0;
static u16 ON_Ticks=0;
void ICU_HW(void){
	static u8 Counter=0;
	Counter++;
	if(Counter==1){
    /*Get First Rising Reading */
		RISING_Reading1=ICU_u16ReadInputCapture();
	}
	else if(Counter==2){
		/*Get second rising reading */
		RISING_Reading2=ICU_u16ReadInputCapture();
		Period_Ticks=RISING_Reading2-RISING_Reading1;
		/*Set Trigger to Falling to capture ON Ticks */
        ICU_voidSetTriggerEdge(ICU_FALLING_EDGE);

	}
	else if(Counter==3){
		FALLING_Reading3=ICU_u16ReadInputCapture();
	        ON_Ticks=FALLING_Reading3-RISING_Reading2;
	        /*Disable Interrupt */
	        ICU_voidDisableInterrupt();

		}
}

void main(void){
	PORT_voidInit();
	CLCD_voidInit();
/*Set call Back Func */
	ICU_u8SetCallBackFunction(ICU_HW);
	/*Intialize Timer1 To normal Mode */
	TIMER1_voidInit();
	ICU_voidInit();
	/* Intialize Timer to Give FAST PWM*/
	TIMER0_voidInit();
	GIE_voidEnable();



while (1){
	/* wait until ticks is complete*/
while (Period_Ticks==0 || ON_Ticks==0);
CLCD_voidGoToXY(0,0);
CLCD_voidSendString("PeriodTicks=");
CLCD_voidSendNumber(Period_Ticks);
CLCD_voidGoToXY(1,0);
CLCD_voidSendString("ON Ticks=");
CLCD_voidSendNumber(ON_Ticks);

}
}
