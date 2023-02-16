/*********************************************************************/
/*********************************************************************/
/******** Author:    Saied Kamara   ***********************************/
/******** Component: TWI           ***********************************/
/******** Layer:     MCAL          ***********************************/
/******** Version:   1.0           ***********************************/
/*********************************************************************/
/*********************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWCR  *((volatile u8 *) 0x56)
#define TWCR_TWINT      7  // interrupt flag
#define TWCR_TWEA      6   //enable ACK
#define TWCR_TWSTA      5 //start condition
#define TWCR_TWSTO      4  //stop condition
#define TWCR_TWWC      3  //write collision
#define TWCR_TWEN      2    //enable
#define TWCR_TWIE      0      //interrupt enable

#define TWDR  *((volatile u8 *) 0x23)

#define TWAR  *((volatile u8 *) 0x22)
#define TWAR_TWGCE 0       //general call enable

#define TWSR  *((volatile u8 *) 0x21)
#define TWSR_TWPS0   0      //prescalar
#define TWSR_TWPS1   1

#define TWBR  *((volatile u8 *) 0x20)

#endif
