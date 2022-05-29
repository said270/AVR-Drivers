#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../DIO/DIO_int.h"
#include "ADC_int.h"
#include <util/delay.h>
#define RED_LED_PIN      PIN0
#define YELLOW_LED_PIN   PIN1
#define GREEN_LED_PIN   PIN2
#define LEDS_PORT        PORTB

int main(void)
{
	/* Variable to get the ADC Digital value */
	u16 Local_u16ADCDigitalValue = 0;
	/* Variable to get the ADC Analog value in Volt */
	u16 Local_u16ADCAnalogValue  = 0;
	/* Set the direction output for the PINS connected to the LEDS */
	DIO_voidSetPinDirection(LEDS_PORT,RED_LED_PIN,OUTPUT);
	DIO_voidSetPinDirection(LEDS_PORT,YELLOW_LED_PIN,OUTPUT);
	DIO_voidSetPinDirection(LEDS_PORT,GREEN_LED_PIN,OUTPUT);
	DIO_voidSetPortDirection(PORTC,0xff);
	DIO_voidSetPinDirection(PORTA,PIN7,OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN6,OUTPUT);

	DIO_voidSetPinDirection(PORTA,PIN5,OUTPUT);



	/* Turn Off All the leds */
	DIO_voidSetPinValue(LEDS_PORT,RED_LED_PIN,LOW);
	DIO_voidSetPinValue(LEDS_PORT,YELLOW_LED_PIN,LOW);
	DIO_voidSetPinValue(LEDS_PORT,GREEN_LED_PIN,LOW);

	/* ADC Init */
	ADC_voidInit();
	LCD_voidInit();


	while(1)
	{
		/* Get the Digital value of the ADC */
		Local_u16ADCDigitalValue = ADC_u16GetDigitalValue(ADC_u8_ADC_CHANNEL_0);
		/* Convert the Digital value of the ADC into a value represented in volt */
		Local_u16ADCAnalogValue = ((Local_u16ADCDigitalValue * 5000UL)/1024);
		/* If the input voltage is less than 1.5 v turn on the Red Led        */
		/* If the input voltage is between 1.5v and 3v turn on the Yellow Led */
		/* If the input voltage is between 3v and 5v turn on the Green Led    */
		if(Local_u16ADCAnalogValue < 1500)
		{
			/* Turn on The Red Led */
			DIO_voidSetPinValue(LEDS_PORT,RED_LED_PIN,HIGH);
			DIO_voidSetPinValue(LEDS_PORT,YELLOW_LED_PIN,LOW);
			DIO_voidSetPinValue(LEDS_PORT,GREEN_LED_PIN,LOW);
		}
		else if((Local_u16ADCAnalogValue >= 1500) && (Local_u16ADCAnalogValue < 3000))
		{
			/* Turn on The Yellow Led */
			DIO_voidSetPinValue(LEDS_PORT,RED_LED_PIN,LOW);
			DIO_voidSetPinValue(LEDS_PORT,YELLOW_LED_PIN,HIGH);
			DIO_voidSetPinValue(LEDS_PORT,GREEN_LED_PIN,LOW);
		}
		else if((Local_u16ADCAnalogValue >= 3000) && (Local_u16ADCAnalogValue < 5000))
		{
			/* Turn on The Green Led */
			DIO_voidSetPinValue(LEDS_PORT,RED_LED_PIN,LOW);
			DIO_voidSetPinValue(LEDS_PORT,YELLOW_LED_PIN,LOW);
			DIO_voidSetPinValue(LEDS_PORT,GREEN_LED_PIN,HIGH);
		}

		LCD_voidWriteIntegar(Local_u16ADCAnalogValue);

 _delay_ms(1000);
 LCD_voidSendCMD(0b00000001);
	}


	return 0;
}