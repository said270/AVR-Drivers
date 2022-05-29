#ifndef  ADC_CONFIG_H

#define ADC_CONFIG_H

/* ADMUX BITS */
#define ADMUX_REFS1             7
#define ADMUX_REFS0             6
#define ADMUX_ADLAR             5

#define ADMUX_CHANNEL_NUM_MASK  0b11100000


/* ADCSRA BITS */
#define ADCSRA_ADEN             7
#define ADCSRA_ADSC             6
#define ADCSRA_ADATE            5
#define ADCSRA_ADIF             4
#define ADCSRA_ADIE             3
#define ADCSRA_ADPS2            2
#define ADCSRA_ADPS1            1
#define ADCSRA_ADPS0            0


#define ADC_u8_ADC_CHANNEL_0            0
#define ADC_u8_ADC_CHANNEL_1            1
#define ADC_u8_ADC_CHANNEL_2            2
#define ADC_u8_ADC_CHANNEL_3            3
#define ADC_u8_ADC_CHANNEL_4            4
#define ADC_u8_ADC_CHANNEL_5            5
#define ADC_u8_ADC_CHANNEL_6            6
#define ADC_u8_ADC_CHANNEL_7            7

#endif