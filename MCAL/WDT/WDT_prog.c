#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "WDT_int.h"
#include "WDT_config.h"
#include "WDT_priv.h"

void  WDT_voidEnable(u8 Time_choise){
	
if( Time_choise == 0){
	SET_BIT(WDTCR,3);
	CLR_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
}
	
	else if ( Time_choise == 1){
	SET_BIT(WDTCR,3);
	SET_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
	}
	
	else if ( Time_choise == 2){
	SET_BIT(WDTCR,3);
	CLR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
	}
	
	else if ( Time_choise == 3){
	SET_BIT(WDTCR,3);
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
	}
	
	else if ( Time_choise == 4){
	SET_BIT(WDTCR,3);
	CLR_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	}

	else if ( Time_choise == 5){
	SET_BIT(WDTCR,3);
	SET_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	}
	else if ( Time_choise == 6){
	SET_BIT(WDTCR,3);
	CLR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	}
	
	else if ( Time_choise == 7 ){
	SET_BIT(WDTCR,3);
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	}
	
	
	
	
	
}

void WDT_voidDisable (void){
	WDTCR=0xff;
	
	WDTCR=0x00;
}
/*Refresh is used when you want to intialize the WDT
and start to use it again with different time*/
void WDT_voidRefresh(void){

	asm("WDR");
}
