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
static u8 Ticks=0;
static u8 ONTicks=0;
void ICU_SW(void){
	static u8 Counter=0;
	Counter++;
	if(Counter==1){

		TIMER1_voidSetTimerValue(0);
	}
	else if(Counter==2){
		Ticks=TIMER1_u16ReadTimerValue();
        EXTI_u8Int0SetSenseControl(FALLING_EDGE);

	}
	else if(Counter==3){
			ONTicks=TIMER1_u16ReadTimerValue();
			ONTicks-=Ticks;
	        EXTI_u8IntDisable(INT0);

		}
}

void main(void){
	PORT_voidInit();
	CLCD_voidInit();
	EXTI_voidINT0Init();
	EXTI_u8Int0SetCallBack(ICU_SW);
	TIMER1_voidInit();
	TIMER0_voidInit();
	GIE_voidEnable();


while (1){
	/* wait until ticks is complete*/
while (Ticks==0 && ONTicks==0);
CLCD_voidGoToXY(0,0);
CLCD_voidSendString("PeriodTicks=");
CLCD_voidSendNumber(Ticks);
CLCD_voidGoToXY(1,0);
CLCD_voidSendString("ON Ticks=");
CLCD_voidSendNumber(ONTicks);

}
}
