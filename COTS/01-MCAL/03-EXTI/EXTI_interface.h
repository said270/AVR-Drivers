/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: EXTI               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef EXTI_INTERFACE_H

#define EXTI_INTERFACE_H

#define LOW_LEVEL        1
#define ON_CHANGE        2
#define FALLING_EDGE     3
#define RISING_EDGE      4

#define ENABLED          1
#define DISABLED         1

/* for PreBuild Configs functions  */
void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pfInt0Func)(void));
u8 EXTI_u8Int1SetCallBack(void (*Copy_pfInt1Func)(void));
u8 EXTI_u8Int2SetCallBack(void (*Copy_pfInt2Func)(void));
/* for PostBuild Configs functions  */
/*Sense Options INPUT : Copy_u8Sense
 * 1-LOW_LEVEL
 * 2-ON_CHANGE
 * 3-FALLING_EDGE
 * 4-RISING_EDGE
 * output : Error State with type u8
 */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

/*Sense Options INPUT : Copy_u8IntNumber
 * 1-INT0
 * 2-INT1
 * 3-INT2
 * output : Error State with type u8
 */
u8 EXTO_u8IntEnable(u8 Copy_u8IntNumber);
u8 EXTO_u8IntDisable(u8 Copy_u8IntNumber);

#endif
