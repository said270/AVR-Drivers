/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: WDT               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

/*Sleep Options
 * 1-WDT_PRESCALAR_16ms          //16.3ms
 * 2-WDT_PRESCALAR_32ms          //32.5ms
 * 3-WDT_PRESCALAR_65ms          //65ms
 * 4-WDT_PRESCALAR_130ms         //0.13s
 * 5-WDT_PRESCALAR_260ms         //0.26s
 * 6-WDT_PRESCALAR_520ms         //0.52s
 * 7-WDT_PRESCALAR_1000ms         //1s
 * 8-WDT_PRESCALAR_2100ms         //2.1s
 */
#define WDT_PRESCALAR_16ms     0
#define WDT_PRESCALAR_32ms     1
#define WDT_PRESCALAR_65ms     2
#define WDT_PRESCALAR_130ms    3
#define WDT_PRESCALAR_260ms    4
#define WDT_PRESCALAR_520ms    5
#define WDT_PRESCALAR_1000ms   6
#define WDT_PRESCALAR_2100ms   7

void WDT_voidSleep(u8 Copy_u8Sleep);
void WDT_voidDisable(void);
void WDT_voidEnable(void);


#endif
