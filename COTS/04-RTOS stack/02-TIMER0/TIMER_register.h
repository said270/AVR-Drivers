/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: RTOS stack            *****************/
/*************   SWC: TIMER0              *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef TIMER_REGISTER_H

#define TIMER_REGISTER_H

/* Register for Timer0 */
#define TCCR0      *((volatile u8*)0x53)           //timer0 control register
#define TCCR0_WGM00     6                          //waveform generation mode bit0
#define TCCR0_WGM01     3                          //waveform generation mode bit1
#define TCCR0_CS02      2                          //prescalar//
#define TCCR0_CS01      1
#define TCCR0_CS00      0

#define OCR0         *((volatile u8*)0x5C)      //output compare register 0

#define TIMSK        *((volatile u8*)0x59)      // timer interrupt mask
#define TIMSK_OCIE0    1                          //output compare interrupt
#define TIMSK_TICIE1   5                         //TIMER1 ICR interrupt enable

#endif
