/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: TIMER               *********************/
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

/*Register for Timer1 */
#define TCCR1A        *((volatile u8*)0x4F)
#define TCCR1A_WGM10     0
#define TCCR1A_WGM11     1
#define TCCR1A_COM1A1    7
#define TCCR1A_COM1A0    6

#define TCCR1B        *((volatile u8*)0x4E)
#define TCCR1B_WGM12     3
#define TCCR1B_WGM13     4
#define TCCR1B_CS10      3
#define TCCR1B_CS11      3
#define TCCR1B_CS12      3
#define TCCR1B_ICES1     6                /*ICU Trigger Select */

#define ICR1          *((volatile u16*)0x46)

#define OCR1A         *((volatile u16*)0x4A)

#define TCNT1         *((volatile u16*)0x4C)

#endif
