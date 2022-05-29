#ifndef _TIMER0_PRIV
#define _TIMER0_PRIV

#define TIMSK	 (*(volatile u8 * )0x59)
#define OCR0 	 (*(volatile u8 * )0x5C)
#define TCCR0	 (*(volatile u8 * )0x53)
#define TCNT0	 (*(volatile u8 * )0x52)
#define TIFR	 (*(volatile u8 * )0x58)



#define TIMER0_NORMAL 		1
#define TIMER0_CTC 			2
#define TIMER0_FAST_PWM 	3
#define TIMER0_PHASE_PWM 	4

#define TIMER0_DIV_BY_1			1
#define TIMER0_DIV_BY_8			8
#define TIMER0_DIV_BY_64		64
#define TIMER0_DIV_BY_256		256
#define TIMER0_DIV_BY_1024		1024


#define TIMER0_NO_ACTION	10
#define TIMER0_TOGGLE		20
#define TIMER0_SET			30
#define TIMER0_CLEAR		40


#endif