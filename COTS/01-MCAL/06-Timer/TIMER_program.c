/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: TIMER               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIMER_register.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;
static void (*ICU_pvCallBackFunc)(void)=NULL;
static void (*Schedule_pvCallBackFunc)(void)=NULL;
static u8 TIMER0_InterruptSource =0;
static u8 TIMER0_FunctionState =0;
static u32 TIMER0_ScheduleCounter =0;
void TIMER0_voidInit(void){
	/* choose FAST PWM mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*enable interrupt of output compare match */
	//SET_BIT(TIMSK,TIMSK_OCIE0);

	TIMER0_InterruptSource==0;

	/*Set Compare Match Value */
	OCR0=64;

	/* Choose Non inverted mode : CLR on CMP and SET on top */
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);

	/*Prescalar div by 8 */
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);


}
u8 TIMER0_u8TimerSchedule(u32 Copy_u32msDelay,void (*Copy_pvScheduleCallBack)(void),u8 Copy_FunctionState){
u8 Local_u8ErrorState=OK;
/* choose CTC mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/* Define Source of interrupt to be from Schedule */
	TIMER0_InterruptSource = 1;
/* CHOOSE OC0 to No operation */
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
	/*Choose value of OCR0=250 for calculations */
	OCR0=250;
	/*Set Call back function*/
	Schedule_pvCallBackFunc=Copy_pvScheduleCallBack;
	/*Set Counter */
	TIMER0_ScheduleCounter=(Copy_u32msDelay/8);
	/* SET funtion State of user's defined to pass to ISR	 */
	TIMER0_FunctionState=Copy_FunctionState;
	/*enable interrupt of output compare match */
		SET_BIT(TIMSK,TIMSK_OCIE0);
	/*Prescalar div by 256 : 32us Ticktime */
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);

return Local_u8ErrorState;
}
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value){
	OCR0=Copy_u8Value;
}
u8 TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void)){
	u8 Local_ErrorState=OK;
	if(Copy_pvCallBackFunc!=NULL){
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else{
		Local_ErrorState=NULL_POINTER;
	}
	return Local_ErrorState;
}
void TIMER1_voidInit(void){
/*set Compare output mode [Non Inverting ]: SET on TOP CLR on CMP
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);*/

	/*WaveForm :Fast PWM with ICR1 to set top
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1A,TCCR1B_WGM12);
	SET_BIT(TCCR1A,TCCR1B_WGM13);*/

	//Set prescalar
	TCCR1B &= PRESCALAR_MASK;
	TCCR1B |= DIV_BY_8;

}
void TIMER1_voidSetTopValue(u16 Copy_u16TopValue){
ICR1=Copy_u16TopValue;
}
void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16Value){
OCR1A=Copy_u16Value;
}
void TIMER1_voidSetTimerValue(u16 Copy_u16Value){
TCNT1=Copy_u16Value;
}
u16  TIMER1_u16ReadTimerValue(void){
	return TCNT1;
}

void ICU_voidInit(void){
	/*Intialize Trigger Source to rising edge */
     SET_BIT(TCCR1B,TCCR1B_ICES1);
     /*enable interrupt */
     SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidSetTriggerEdge(u8 Copy_u8Edge){
if(Copy_u8Edge == ICU_RISING_EDGE){
SET_BIT(TCCR1B,TCCR1B_ICES1);
}

else if(Copy_u8Edge == ICU_FALLING_EDGE){
CLR_BIT(TCCR1B,TCCR1B_ICES1);
}

}
void ICU_voidEnableInterrupt(void){
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidDisableInterrupt(void){
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
u16 ICU_u16ReadInputCapture(void){
	return ICR1;
}
u8 ICU_u8SetCallBackFunction(void (*Copy_pvCallBackFunc)(void)){
	u8 Local_ErrorState=OK;
	if(Copy_pvCallBackFunc != NULL){
	ICU_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else {
		Local_ErrorState=NULL_POINTER;
	}
	return Local_ErrorState;
}
/*Timer 0 ISR */
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	static u32 Local_u32Counter=0;
	if(TIMER0_InterruptSource==0){
	if(TIMER0_pvCallBackFunc!=NULL){

		TIMER0_pvCallBackFunc();
	}
	else{

	}
	}
	else if(TIMER0_InterruptSource==1){
		/* Schedule is Interrupt source */
		Local_u32Counter++;
      if(Local_u32Counter==TIMER0_ScheduleCounter){
		Schedule_pvCallBackFunc();
		if (TIMER0_FunctionState==TIMER_FUNCSTATE_PERIODIC){
		Local_u32Counter=0;
		}
		else if (TIMER0_FunctionState==TIMER_FUNCSTATE_SINGLE){
			/*disable interrupt of output compare match */
					CLR_BIT(TIMSK,TIMSK_OCIE0);
		}
		}
		else{

		}
	}

}
/*ICU ISR */
void __vector_6(void) __attribute__((signal));
void __vector_6(void){
	if(ICU_pvCallBackFunc!=NULL){

		ICU_pvCallBackFunc();
	}
	else{

	}

}
