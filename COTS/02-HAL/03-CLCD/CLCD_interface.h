/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: HAL             *****************/
/*************   SWC: CLCD                *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#ifndef  CLCD_INTERFACE_H
#define  CLCD_INTERFACE_H
void CLCD_voidInit();

void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendString(const char * Copy_pcString);

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_voidWriteSpecialChar(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_voidSendNumber(u32 Copy_u32Number);

#endif
