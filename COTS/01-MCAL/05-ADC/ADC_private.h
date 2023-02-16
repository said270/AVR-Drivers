/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: ADC               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef ADC_PRIVATE_H

#define ADC_PRIVATE_H

#define IDLE                 1
#define BUSY                 2

#define AREF                 0
#define AVCC                 64
#define INTERNAL             192

#define LEFT_ADJUST          1
#define RIGHT_ADJUST         2

#define DIV_BY_2             0
#define DIV_BY_4             2
#define DIV_BY_8             3
#define DIV_BY_16            4
#define DIV_BY_32            5
#define DIV_BY_64            6
#define DIV_BY_128           7

#define DISABLED             0
#define ENABLED              1

#define FREE_RUNNING         0
#define ANALOG_COMPATATOR    32
#define EXTI0                64
#define TIMER0_CMP           96
#define TIMER0_OVERFLOW      128

#define SingleChannelAsync 1
#define ChainAsync         2


#endif
