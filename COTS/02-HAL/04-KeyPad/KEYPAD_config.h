/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: HAL             *****************/
/*************   SWC: KEYPAD                *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define  KEYPAD_PORT             DIO_u8PORTD

#define  KEYPAD_COLUMN0_PIN         DIO_u8PIN0
#define  KEYPAD_COLUMN1_PIN         DIO_u8PIN1
#define  KEYPAD_COLUMN2_PIN         DIO_u8PIN2
#define  KEYPAD_COLUMN3_PIN         DIO_u8PIN3

#define  KEYPAD_ROW0_PIN            DIO_u8PIN4
#define  KEYPAD_ROW1_PIN            DIO_u8PIN5
#define  KEYPAD_ROW2_PIN            DIO_u8PIN6
#define  KEYPAD_ROW3_PIN            DIO_u8PIN7
/* Value to return if no key is pressed */
#define  KEYPAD_NO_PRESSED_KEY   0xff
/* array to define which key is pressed */
#define  KPD_ARR_VAL   {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}


#endif
