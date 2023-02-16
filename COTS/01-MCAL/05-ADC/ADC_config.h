/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: ADC               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef ADC_CONFIG_H

#define ADC_CONFIG_H

#define ADC_TIMEOUT          50000

/*options :
 * 1-AREF
 * 2-AVCC
 * 3-INTERNAL  (2.56V)
 */
#define ADC_REF_Voltage    AVCC

/*options
 * 1-LEFT_ADJUST
 * 2-RIGHT_ADJUST
 */
#define ADC_ADJUST_RESULT     LEFT_ADJUST

/*options
 * 1-DIV_BY_2
 * 2-DIV_BY_4
 * 3-DIV_BY_8
 * 4-DIV_BY_16
 * 5-DIV_BY_32
 * 6-DIV_BY_64
 * 7-DIV_BY_128
 *
 */
#define ADC_PRESCALAR       DIV_BY_128

/*options
 * 1-DISABLED
 * 2-ENABLED
 */
#define ADC_INTERRUPT         DISABLED
#define ADC_AUTO_TRIGGER      DISABLED

/*options
 * 1-FREE_RUNNING
 * 2-ANALOG_COMPATATOR
 * 3-EXTI0
 * 4-TIMER0_CMP
 * 5-TIMER0_OVERFLOW
 */
#define ADC_AUTO_TRIGGER_SOURCE     FREE_RUNNING

#endif
