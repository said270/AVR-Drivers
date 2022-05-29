#ifndef  ADC_PRIVATE_H

#define ADC_PRIVATE_H

#define   SREG      *((volatile  u8*)0x5F)
#define   ADMUX      *((volatile  u8*)0x27)
#define   ADCSRA     *((volatile  u8*)0x26)
#define   ADCH      *((volatile  u8*)0x25)
#define   ADCL      *((volatile  u8*)0x24)


#define   ADC      *((volatile  u16*)0x24)




#endif