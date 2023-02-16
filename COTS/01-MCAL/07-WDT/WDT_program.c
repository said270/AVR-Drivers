/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: WDT               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT_config.h"
#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_register.h"

void WDT_voidSleep(u8 Copy_u8Sleep){
/*Clear Prescalar Bits*/
	WDTCR &= 0b11111000;
/*Set prescalar */
	WDTCR |= Copy_u8Sleep;
}
void WDT_voidDisable(void){
WDTCR |= 0b00011000;
WDTCR =0;
}
void WDT_voidEnable(void){
SET_BIT(WDTCR,WDTCR_WDE);
}
