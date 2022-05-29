#ifndef		DIO_INT_H
#define		DIO_INT_H

void 	DIO_voidSetPinDirection(u8 PORT , u8 PIN , u8 Direction);
void 	DIO_voidSetPortDirection(u8 PORT , u8 Direction);

void 	DIO_voidSetPinValue(u8 PORT , u8 PIN , u8 Value);
void 	DIO_voidSetPortValue(u8 PORT , u8 Value);

u8 		DIO_u8GetPinValue(u8 PORT , u8 PIN);

#define		PORTA		0
#define		PORTB		1
#define		PORTC		2
#define		PORTD		3

#define		PIN0		0
#define		PIN1		1
#define		PIN2		2
#define		PIN3		3
#define		PIN4		4
#define		PIN5		5
#define		PIN6		6
#define		PIN7		7

#define		OUTPUT		1
#define		INPUT		0

#define     OUTPUTPORT   0xff
#define     INPUTPORT    0x00

#define		HIGH		1
#define		LOW			0


#endif