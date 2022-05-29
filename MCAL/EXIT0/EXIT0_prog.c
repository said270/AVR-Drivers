#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXIT0_INT.h"
#include "EXIT0_config.h"
#include "EXIT0_private.h"

#define  NULL                 ( void * )0
static void (*Gpf)(void)=NULL;
void EXIT0_voidInit(void){
	#if  SENSE_MODE  == FALLING
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,0);
	#elif SENSE_MODE  == RISING
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,0);
	#elif SENSE_MODE  == LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,0);
	#elif SENSE_MODE  == IOC
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,0);
	#else
		#error ("Wrong Sense_Mode choice!")
	#endif
	//Disable EXIT0
	CLR_BIT(GICR,6);
	
	
}
void EXIT0_voidEnable(void){
	
	SET_BIT(GICR,6);
	
	
}
void EXIT0_voidDisable(void){
	
	CLR_BIT(GICR,6);
	
	
}

void EXIT0_voidSetCallBack(void (*pf)(void)){
	if (pf !=NULL){
		Gpf=pf;
	}
}

//writing ISR
// __ : for vector table 
//only HW can call it not SW
void __vector_1(void)  __attribute__((signal,used));
//by this i told the combiler this will be used by hardware 
void __vector_1(void){
	Gpf(); /*== Toggle ();*/
	
}
