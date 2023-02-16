/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: RTOS stack            *****************/
/*************   SWC: TIMER0              *********************/
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
static void (*Schedule_pvCallBackFunc)(void)=NULL;
static u8 TIMER0_InterruptSource =0;
static u8 TIMER0_FunctionState =0;
static u32 TIMER0_ScheduleCounter =0;
void TIMER0_voidInit(void){
	/* choose CTC mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*enable interrupt of output compare match */
	//SET_BIT(TIMSK,TIMSK_OCIE0);


	/*Set Compare Match Value */
	OCR0=125;     //1 m sec

/* Interrupt enable */
SET_BIT(TIMSK,TIMSK_OCIE0);

	/*Prescalar div by 64 */
	SET_BIT(TCCR0,TCCR0_CS00);
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

/*Timer 0 ISR */
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	TIMER0_pvCallBackFunc();
}
