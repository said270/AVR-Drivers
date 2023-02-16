/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: USART               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART_voidInit(void);
void USART_voidSendData(u8 Copy_u8Data);
u8  USART_u8RecieveData(void);

#endif
