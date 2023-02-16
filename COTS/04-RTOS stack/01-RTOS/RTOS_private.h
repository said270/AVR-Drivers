/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: RTOS stack            *****************/
/*************   SWC: RTOS              *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef RTOS_PRIVATE_H

#define RTOS_PRIVATE_H

typedef struct {
	u16 Periodicity;
	void (*TaskFunc)(void);
	u8 State;
	u16 FirstDelay;
}Task_t;
static void voidScheduler(void);

#define TASK_ACTIVE      1
#define TASK_SUSPENDED   2
#endif
