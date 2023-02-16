/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: USART               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"


void USART_voidInit(void){
 /* Intialize
  * 1 stop bit
  * no parity
  * 8 data bits
  * no interrupt
  * Asynchronus
  * 9600 bps
  */
	u8 Local_u8UCSRC=0;
	/*enable RX and TX*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	/* 1 stop bit */
	CLR_BIT(UCSRC,UCSRC_USBS);

	/* no Parity */
	CLR_BIT(UCSRC,UCSRC_UPM0);
	CLR_BIT(UCSRC,UCSRC_UPM1);

	/* 8 Bit size */
SET_BIT(Local_u8UCSRC,UCSRC_URSEL);
SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
CLR_BIT(UCSRB,UCSRB_UCSZ2);

UCSRC=Local_u8UCSRC;
UBRRL = 51; //BAUD RATE 9600
}
void USART_voidSendData(u8 Copy_u8Data){
while (GET_BIT(UCSRA,UCSRA_UDRE) ==0);    //wait till register is empty
UDR=Copy_u8Data;

}
u8 USART_u8RecieveData(void){

while (GET_BIT(UCSRA,UCSRA_RXC) ==0);
return UDR;
}


