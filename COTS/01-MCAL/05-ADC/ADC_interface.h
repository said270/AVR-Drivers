/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: ADC               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef ADC_INTERFACE_H

#define ADC_INTERFACE_H

void ADC_voidInit(void);
/* Select ADC channel */
#define SINGLE_ADC0           0
#define SINGLE_ADC1           1
#define SINGLE_ADC2           2
#define SINGLE_ADC3           3
#define SINGLE_ADC4           4
#define SINGLE_ADC5           5
#define SINGLE_ADC6           6
#define SINGLE_ADC7           7

#define DIFF_ADC0_ADC0_10x    8
#define DIFF_ADC1_ADC0_10x    9
#define DIFF_ADC0_ADC0_200x   10
#define DIFF_ADC1_ADC0_200x   11
#define DIFF_ADC2_ADC2_10x    12

/* Synchronous Functions */
u8 ADC_u8GetChannelReadingSynchronous(u8 Copy_u8Channel,u8* Copy_pu8Reading);
u16 ADC_u16GetChannelReadingSynchronous(u8 Copy_u8Channel);

/*Asynchronous Functions */
/*Remember:To Enable Global Interrupt */
u8 ADC_u8GetChannelReadingASynchronous(u8 Copy_u8Channel,u8* Copy_pu8Reading,void(*Copy_pvNotification)(void));

/* Asynchronous Chain Conversion */
typedef struct {
	u8 * Channel;
	u16 * Result;
	u8 Size;
	void (*NotificationFunc)(void);
}Chain_t;

u8 ADC_u8GetChainASynchronous(Chain_t * Copy_Chain);

#endif
