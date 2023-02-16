#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

/* Global Pointer To function to hold INT0 ISR address */
void (*EXTI_pvInt0Func)(void)=NULL;
/* Global Pointer To function to hold INT1 ISR address */
void (*EXTI_pvInt1Func)(void)=NULL;
/* Global Pointer To function to hold INT2 ISR address */
void (*EXTI_pvInt2Func)(void)=NULL;

void EXTI_voidINT0Init(void){
	/* Check Sense control  */
#if  INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif  INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif  INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif  INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error "Wrong INT0_SENSE configuration option"

#endif
	/* CHECK INTERRUPT ENABLE INITIAL STATE */
#if INT0_INTIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INTIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong Initial State option"
#endif
}

void EXTI_voidINT1Init(void){
	/* Check Sense control  */
#if  INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif  INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif  INT1_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif  INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#else
#error "Wrong INT0_SENSE configuration option"

#endif
	/* CHECK INTERRUPT ENABLE INITIAL STATE */
#if INT1_INTIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INTIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong Initial State option"
#endif
}
void EXTI_voidINT2Init(void){
	/* Check Sense control  */
#if  INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_INT2);

#elif  INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);

#else
#error "Wrong INT0_SENSE configuration option"

#endif
	/* CHECK INTERRUPT ENABLE INITIAL STATE */
#if INT2_INTIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);
#elif INT2_INTIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong Initial State option"
#endif
}
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;
	switch (Copy_u8Sense){
	case LOW_LEVEL :
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case ON_CHANGE :
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case FALLING_EDGE :
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	case RISING_EDGE :
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	default : Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8Int0SetCallBack(void (*Copy_pfInt0Func)(void)){
u8 Local_u8ErrorState=OK;
if(Copy_pfInt0Func != NULL ){
	EXTI_pvInt0Func=Copy_pfInt0Func;
}
else {
	Local_u8ErrorState=NULL_POINTER;
}

return Local_u8ErrorState;
}

/* ISR of INT0 */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	if(EXTI_pvInt0Func !=NULL){
		EXTI_pvInt0Func();
	}
	else{

	}
}
u8 EXTI_u8Int1SetCallBack(void (*Copy_pfInt1Func)(void)){
u8 Local_u8ErrorState=OK;
if(Copy_pfInt1Func != NULL ){
	EXTI_pvInt1Func=Copy_pfInt1Func;
}
else {
	Local_u8ErrorState=NULL_POINTER;
}

return Local_u8ErrorState;
}

/* ISR of INT0 */
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	if(EXTI_pvInt1Func !=NULL){
		EXTI_pvInt1Func();
	}
	else{

	}
}
u8 EXTI_u8Int2SetCallBack(void (*Copy_pfInt2Func)(void)){
u8 Local_u8ErrorState=OK;
if(Copy_pfInt2Func != NULL ){
	EXTI_pvInt2Func=Copy_pfInt2Func;
}
else {
	Local_u8ErrorState=NULL_POINTER;
}

return Local_u8ErrorState;
}

/* ISR of INT0 */
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	if(EXTI_pvInt2Func !=NULL){
		EXTI_pvInt2Func();
	}
	else{

	}
}
