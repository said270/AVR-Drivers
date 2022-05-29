#ifndef    WDT_INT_H

#define    WDT_INT_H


void  WDT_voidEnable(u8   Time_choise);



void WDT_voidDisable (void);


void WDT_voidRefresh(void);

#define  WD_TIME_16_ms         0
#define  WD_TIME_32_ms         1
#define  WD_TIME_65_ms         2
#define  WD_TIME_130_ms        3
#define  WD_TIME_260_ms        4
#define  WD_TIME_500_ms         5
#define  WD_TIME_1_s           6
#define  WD_TIME_2_s           7





#endif
