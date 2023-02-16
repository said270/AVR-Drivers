/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: RTOS stack            *****************/
/*************   SWC: TIMER0              *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef TIMER_INTERFACE_H

#define TIMER_INTERFACE_H


void TIMER0_voidInit(void);
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);
u8 TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));
#define  TIMER_FUNCSTATE_PERIODIC       1
#define  TIMER_FUNCSTATE_SINGLE         2
u8 TIMER0_u8TimerSchedule(u32 Copy_u32msDelay,void (*Copy_pvScheduleCallBack)(void),u8 Copy_FunctionState);


#endif
