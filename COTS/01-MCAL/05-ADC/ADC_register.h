/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: ADC               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef ADC_REGISTER_H

#define ADC_REGISTER_H

#define ADMUX  *((volatile u8*)0x27)
/*Muliplexer Selection */
#define ADMUX_REFS1         7    
#define ADMUX_REFS0         6
/*ADC left adjust result */
#define ADMUX_ADLAR         5    


#define ADCSRA  *((volatile u8*)0x26)
#define ADCSRA_ADEN      7       //ADC enable
#define ADCSRA_ADSC      6       //ADC start conversion
#define ADCSRA_ADATE     5        //ADC AutoTrigger
#define ADCSRA_ADIF      4        //ADC interrupt flag
#define ADCSRA_ADIE      3       //ADC interrupt enable 
/* Prescalar selection */
#define ADCSRA_ADPS2     2
#define ADCSRA_ADPS1     1
#define ADCSRA_ADPS0     0


#define ADCH  *((volatile u8*)0x25)
#define ADCL  *((volatile u8*)0x24)

#define ADC   *((volatile u16*)0x24)

#define SFIOR   *((volatile u8*)0x50)

#endif
