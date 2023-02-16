/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: USART               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#ifndef USART_REGISTER_H
#define USART_REGISTER_H

#define UDR   *((volatile u8 *)0x2C)

#define UCSRA   *((volatile u8 *)0x2B)
#define UCSRA_RXC   7     //rx complete
#define UCSRA_TXC   6     //tx complete
#define UCSRA_UDRE  5      //REGISTER EMPTY
#define UCSRA_FE    4
#define UCSRA_DOR   3

#define UCSRB   *((volatile u8 *)0x2A)
#define UCSRB_RXCIE   7
#define UCSRB_TXCIE   6
#define UCSRB_UDRIE   5
#define UCSRB_RXEN    4
#define UCSRB_TXEN    3
#define UCSRB_UCSZ2   2
#define UCSRB_RXB8    1
#define UCSRB_TXB8    0

#define UCSRC   *((volatile u8 *)0x40)
#define UCSRC_URSEL   7       //REGISTER SELECT
#define UCSRC_UMSEL   6         //MODE SELECT
#define UCSRC_UPM1    5         //PARITY MODE
#define UCSRC_UPM0    4
#define UCSRC_USBS    3
#define UCSRC_UCSZ1   2
#define UCSRC_UCSZ0   1
#define UCSRC_UCPOL   0

#define UBRRH   *((volatile u8 *)0x40)
#define UBRRL   *((volatile u8 *)0x29)

#endif
