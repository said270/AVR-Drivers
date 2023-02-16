/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: WDT               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#ifndef WDT_REGISTER_H
#define WDT_REGISTER_H

#define WDTCR     *((volatile u8 *)0x41)
#define WDTCR_WDTOE  4
#define WDTCR_WDE    3
#define WDTCR_WDP2    2
#define WDTCR_WDP1    1
#define WDTCR_WDP0    0

#endif
