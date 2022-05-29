#ifndef       LCD_INT_h
#define       LCD_INT_h

#define       RS       PIN7
#define       RW       PIN6
#define       EN       PIN5

#define       Control_PORT       PORTD
#define       DATA_PORT          PORTA
void LCD_voidSendCMD(u8 CMD);
void LCD_voidWriteChar4bit(u8 Data);
void LCD_void4bitInit(void);

void LCD_voidWriteIntegar(u32 Data);

void LCD_voidInit(void);

void LCD_voidWriteChar(u8 Data);
void LCD_voidWriteString(u8 String[]);

void LCD_voidGoToXY(u8 Copy_u8LineNm,u8 Copy_u8CharNm);









#endif
