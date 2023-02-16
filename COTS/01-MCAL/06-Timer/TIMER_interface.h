/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: TIMER               *********************/
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

void TIMER1_voidInit(void);
void TIMER1_voidSetTopValue(u16 Copy_u16TopValue);
void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16Value);
void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16  TIMER1_u16ReadTimerValue(void);

#define  ICU_RISING_EDGE       1
#define  ICU_FALLING_EDGE      2
void ICU_voidSetTriggerEdge(u8 Copy_u8Edge);
void ICU_voidInit(void);
void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);
u16  ICU_u16ReadInputCapture(void);
u8   ICU_u8SetCallBackFunction(void (*Copy_pvCallBackFunc)(void));

#endif
