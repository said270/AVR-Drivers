#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_reg.h"



/*

DIO_voidSetPinDirection(PORTA ,  PIN0 , OUTPUT );

*/

void 	DIO_voidSetPinDirection(u8 PORT , u8 PIN , u8 Direction)
{
	if(PORT <= PORTD && PIN <= PIN7 )
	{
		if(Direction == OUTPUT)
		{
			switch(PORT)
			{
				case PORTA :	SET_BIT(DDRA_REG , PIN); break;
				case PORTB :	SET_BIT(DDRB_REG , PIN); break;
				case PORTC :	SET_BIT(DDRC_REG , PIN); break;
				case PORTD :	SET_BIT(DDRD_REG , PIN); break;
			}
		}else if(Direction == INPUT)
		{
			switch(PORT)
			{
				case PORTA :	CLR_BIT(DDRA_REG , PIN); break;
				case PORTB :	CLR_BIT(DDRB_REG , PIN); break;
				case PORTC :	CLR_BIT(DDRC_REG , PIN); break;
				case PORTD :	CLR_BIT(DDRD_REG , PIN); break;
			}
		}
		else{/* Do nothing */}
	}
	else{/*do nothing*/}
}
void 	DIO_voidSetPinValue(u8 PORT , u8 PIN , u8 Value)
{
	if(PORT <= PORTD && PIN <= PIN7 )
	{
		if(Value == HIGH)
		{
			switch(PORT)
			{
				case PORTA :	SET_BIT(PORTA_REG , PIN); break;
				case PORTB :	SET_BIT(PORTB_REG , PIN); break;
				case PORTC :	SET_BIT(PORTC_REG , PIN); break;
				case PORTD :	SET_BIT(PORTD_REG , PIN); break;
			}
		}else if(Value == LOW)
		{
			switch(PORT)
			{
				case PORTA :	CLR_BIT(PORTA_REG , PIN); break;
				case PORTB :	CLR_BIT(PORTB_REG , PIN); break;
				case PORTC :	CLR_BIT(PORTC_REG , PIN); break;
				case PORTD :	CLR_BIT(PORTD_REG , PIN); break;
			}
		}
		else{/* Do nothing */}
	}
	else{/*do nothing*/}
}
/*
	x = DIO_u8GetPinValue(PORTB , PIN15);
*/
u8 		DIO_u8GetPinValue(u8 PORT , u8 PIN)
{
	/*	Local variable to hold the PIN Value */
	u8 LOC_u8Result = 0XFF ;
	if(PORT <= PORTD && PIN <= PIN7 )
	{
			switch(PORT)
			{
				case PORTA :	LOC_u8Result = GET_BIT(PINA_REG , PIN); break;
				case PORTB :	LOC_u8Result = GET_BIT(PINB_REG , PIN); break;
				case PORTC :	LOC_u8Result = GET_BIT(PINC_REG , PIN); break;
				case PORTD :	LOC_u8Result = GET_BIT(PIND_REG , PIN); break;
			}
	}
	else{/*do nothing*/}
	return LOC_u8Result;
}

void 	DIO_voidSetPortDirection(u8 PORT , u8 Direction)
{
	switch(PORT)
	{
		case PORTA :	DDRA_REG = Direction; break;
		case PORTB :	DDRB_REG = Direction; break;
		case PORTC :	DDRC_REG = Direction; break;
		case PORTD :	DDRD_REG = Direction; break;
	}
}
/*DIO_voidSetPortValue(PORTA , 0XFF)
*/
void 	DIO_voidSetPortValue(u8 PORT , u8 Value)
{
	switch(PORT)
	{
		case PORTA :	PORTA_REG = Value; break;
		case PORTB :	PORTB_REG = Value; break;
		case PORTC :	PORTC_REG = Value; break;
		case PORTD :	PORTD_REG = Value; break;
	}
}