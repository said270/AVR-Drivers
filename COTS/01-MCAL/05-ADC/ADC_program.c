/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: ADC               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"

/*Global variable to Indicate the ADC BUSY state */
u8 ADC_u8BusyState=IDLE;
u8 ADC_u8ISRSource;
/* Global Vars to Pass ASYNC INFO to ISR */
static u8* ADC_pu8Reading=NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;

/*Global Varaiables to Pass the chain INFO to ISR */
static u8  *ADC_pu8ChannelArr=NULL;
static u8   ADC_u8ChainSize;
static u16 *ADC_pu16ResultArr=NULL;
static u8   ADC_u8ChainConversionIndex=0;          //determine current conversion

void ADC_voidInit(void){
	/* SET ADC Reference Voltage */
	ADMUX &= 0b00111111;
	ADMUX |= ADC_REF_Voltage;

	/* SET ADC AJUSTMENT */
#if ADC_ADJUST_RESULT == LEFT_ADJUST
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_ADJUST_RESULT  == RIGHT_ADJUST
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#endif

	/* Selection OF Prescalar */
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_PRESCALAR;

	/* Checking The Auto Trigger */
#if ADC_AUTO_TRIGGER  == DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#elif ADC_AUTO_TRIGGER  == ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	SFIOR &= 0b00011111;
	SFIOR |= ADC_AUTO_TRIGGER_SOURCE;
#endif

	/* Checking Interrupt Enable */
#if ADC_INTERRUPT   == DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
#elif ADC_INTERRUPT   == ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADIE);
#endif
	//Enable ADC peripheral
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}
u8 ADC_u8GetChannelReadingSynchronous(u8 Copy_u8Channel,u8* Copy_pu8Reading){
	u32 Local_u32Counter=0;
	u8  Local_u8ErrorState=OK;
	if(ADC_u8BusyState==IDLE)
	{
		ADC_u8BusyState=BUSY;
		/* Clear ADMUX bits for channel choice */
		ADMUX &= 0b11100000;
		/* Set channel bits in ADMUX */
		ADMUX |= Copy_u8Channel;

		/* Start Conversion of ADC */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/* Polling (Bust waiting) until the conversion is done or counter reaches TIMEOUT*/
		while ((GET_BIT(ADCSRA,ADCSRA_ADIF))==0 && (Local_u32Counter !=ADC_TIMEOUT )){
			Local_u32Counter++;
		}
		if(Local_u32Counter == ADC_TIMEOUT){
			//Loop is broken caz of timeout is reached
			Local_u8ErrorState=NOK;
		}
		else {
			//Loop is broken via flag is raised
			/* Clear Conversion Flag */
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			/* return reading */
			*Copy_pu8Reading=ADCH;
			/*ADC finished conversion return to idle */
			ADC_u8BusyState=IDLE;

		}
	}
	else{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}
u16 ADC_u16GetChannelReadingSynchronous(u8 Copy_u8Channel){
	/* Clear ADMUX bits for channel choice */
	ADMUX &= 0b11100000;
	/* Set channel bits in ADMUX */
	ADMUX |= Copy_u8Channel;

	/* Start Conversion of ADC */
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/* Polling (Bust waiting) until the conversion is done */
	while ((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);
	/* Clear Conversion Flag */
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	/* return reading */
	return ADC;

}

u8 ADC_u8GetChannelReadingASynchronous(u8 Copy_u8Channel,u8* Copy_pu8Reading,void(*Copy_pvNotification)(void)){

	u8 Local_u8ErrorState=OK;
	if(ADC_u8BusyState==IDLE ){
		if(Copy_pvNotification==NULL ){
			Local_u8ErrorState=NULL_POINTER;
		}
		else{
			/*make ADC busy for not work until it finishes conversion*/
			ADC_u8BusyState=BUSY;
			/*Make ISR source Single channel ASYNC*/
			ADC_u8ISRSource = SingleChannelAsync;
			/*intialize global variable reading */
			ADC_pu8Reading=Copy_pu8Reading;

			/*intialize call back function */
			ADC_pvCallBackNotificationFunc=Copy_pvNotification;
			/* Clear ADMUX bits for channel choice */
			ADMUX &= 0b11100000;
			/* Set channel bits in ADMUX */
			ADMUX |= Copy_u8Channel;

			/* Start Conversion of ADC */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*enable Interrupt */
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
	}
	else{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}
u8 ADC_u8GetChainASynchronous(Chain_t * Copy_Chain){
	u8 Local_ErrorState=OK;
	//Check NULL pointer
	if (Copy_Chain == NULL){
		Local_ErrorState=NULL_POINTER;
	}
	//Check Busy State
	else {
		if(ADC_u8BusyState==IDLE){
			//if IDLE we start our chain

			//Make BUSY state
			ADC_u8BusyState=BUSY;

			/*Make ISR source Chain ASYNC*/
			ADC_u8ISRSource = ChainAsync;

			/*Initialize Chain Channel array */
			ADC_pu8ChannelArr=Copy_Chain->Channel;

			/*Initialize result array */
			ADC_pu16ResultArr=Copy_Chain->Result;

			/*Initialize Chain Size */
			ADC_u8ChainSize=Copy_Chain->Size;

			/*Initialize Notification Func */
			ADC_pvCallBackNotificationFunc=Copy_Chain->NotificationFunc;

			//Return Index to Zero for New Chain Conversions
			ADC_u8ChainConversionIndex=0;

			//set Required Channel
			//set first channel
			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8ChannelArr[ADC_u8ChainConversionIndex];

			/* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*enable interrupt */
			SET_BIT(ADCSRA,ADCSRA_ADIE);



		}
		else{
			//if BUSY we return a BUSY FUNC
			Local_ErrorState=BUSY_FUNC;
		}


	}
	return Local_ErrorState;
}

void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
	if (ADC_u8ISRSource == SingleChannelAsync){

		//read ADC result
		*ADC_pu8Reading=ADCH;
		/*Get back to idle state */
		ADC_u8BusyState=IDLE;
		//call notification function
		ADC_pvCallBackNotificationFunc();
		//ADC finished its JOB
	}
	else if (ADC_u8ISRSource == ChainAsync) {
		/* ISR Source is Chain */

		/* Read the last Conversion */
		ADC_pu16ResultArr[ADC_u8ChainConversionIndex]=ADCH;

		/*Increment Index */
		ADC_u8ChainConversionIndex++;
		/*Check if I am finished or not */
		if(ADC_u8ChainConversionIndex == ADC_u8ChainSize){
			/* Chain is finished */

			//call notification function
			ADC_pvCallBackNotificationFunc();

			//make State IDLE
			/*note : we make this step first as if inside notification function is calling Chain Conversion */

			//call notification function
			ADC_pvCallBackNotificationFunc();

			//disable Interrupt
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else{
			/*Chain Not finished */

           //set new Channel
			ADMUX &= 0b11100000;
		    ADMUX |= ADC_pu8ChannelArr[ADC_u8ChainConversionIndex];

		    /* Start Conversion */
		    SET_BIT(ADCSRA,ADCSRA_ADSC);

		}
	}

}
