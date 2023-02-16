/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: RTOS stack            *****************/
/*************   SWC: RTOS              *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef RTOS_INTERFACE_H

#define RTOS_INTERFACE_H

/* APIs we will use */
void RTOS_voidStart(void);

u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);
void RTOS_voidSuspendTask(u8 Copy_u8Priority);
void RTOS_voidResumeTask(u8 Copy_u8Priority);
void RTOS_voidDeleteTask(u8 Copy_u8Priority);

#endif
