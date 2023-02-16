/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: RTOS stack            *****************/
/*************   SWC: RTOS              *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "GIE_interface.h"

#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"

Task_t SystemTasks[TASK_NUM]={{NULL}};
void RTOS_voidStart(void){
	TIMER_u8SetCallBack(&voidScheduler);
	GIE_voidEnable();
	TIMER0_voidInit();
}
void voidScheduler(void){
	static u8 Local_u8TaskCounter=0;

	/* Loop to check all tasks : too see if this task comes at this time or not */
	for (Local_u8TaskCounter = 0 ; Local_u8TaskCounter <TASK_NUM ; Local_u8TaskCounter++){
		if(SystemTasks[Local_u8TaskCounter].State==TASK_ACTIVE){
			//do nothing
			if ( ( SystemTasks[Local_u8TaskCounter].FirstDelay )== 0)
			{
				/* Invoke Task Func */
				if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL){
					SystemTasks[Local_u8TaskCounter].TaskFunc();
					/* Assign first delay to periodicity */
					SystemTasks[Local_u8TaskCounter].FirstDelay=SystemTasks[Local_u8TaskCounter].Periodicity-1;
				}
				else{
					//do nothing
				}
			}
				else {
					SystemTasks[Local_u8TaskCounter].FirstDelay--;
				}
			}
		else {

		}
		}
	}
u8 RTOS_voidCreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay){
	u8 Local_u8ErrorState=OK;
	/* We work as static allocation */
	/* we make priority as the element array */
	/*we check if the element of priority is empty to assign new one */
	if (SystemTasks[Copy_u8Priority].TaskFunc==NULL){
		SystemTasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;
		SystemTasks[Copy_u8Priority].State=TASK_ACTIVE;
		SystemTasks[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
	}
	else {
		/* Priority is reserved */ /* Dont create task */
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
void RTOS_voidSuspendTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].State=TASK_SUSPENDED;
}
void RTOS_voidResumeTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].State=TASK_ACTIVE;
}
void RTOS_voidDeleteTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].TaskFunc=NULL;
}
