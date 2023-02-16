#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"

u8 SSD_u8EnableSSD(SSD_Init * SSD){
	u8 Local_ErrorState=0;
	DIO_u8SetPinDirection(SSD->Enable_PORT,SSD->Enable_PIN,DIO_u8PIN_OUTPUT);
	if(SSD->COM_Type == SSD_u8COM_Anode){
		DIO_u8SetPinValue(SSD->Enable_PORT,SSD->Enable_PIN,DIO_u8PIN_HIGH);
	}
	else if(SSD->COM_Type == SSD_u8COM_Cathode){
		DIO_u8SetPinValue(SSD->Enable_PORT,SSD->Enable_PIN,DIO_u8PIN_LOW);
	}
	return Local_ErrorState;
}
u8 SSD_u8DisableSSD(SSD_Init * SSD){
	u8 Local_ErrorState=0;
		DIO_u8SetPinDirection(SSD->Enable_PORT,SSD->Enable_PIN,DIO_u8PIN_OUTPUT);
		if(SSD->COM_Type == SSD_u8COM_Anode){
			DIO_u8SetPinValue(SSD->Enable_PORT,SSD->Enable_PIN,DIO_u8PIN_LOW);
		}
		else if(SSD->COM_Type == SSD_u8COM_Cathode){
			DIO_u8SetPinValue(SSD->Enable_PORT,SSD->Enable_PIN,DIO_u8PIN_HIGH);
		}
		return Local_ErrorState;
}
u8 SSD_u8SetNumber(SSD_Init * SSD,u8 Copy_u8Number){
	u8 Local_ErrorState=0;
	DIO_u8SetPortDirection(SSD->PORT,DIO_u8PORT_OUTPUT);
	if (SSD->COM_Type == SSD_u8COM_Anode )
	switch(Copy_u8Number){
	case 0 : DIO_u8SetPortValue(SSD->PORT,~(0b00111111)); break;
	case 1 : DIO_u8SetPortValue(SSD->PORT,~(0b00000110)); break;
	case 2 : DIO_u8SetPortValue(SSD->PORT,~(0b01011011)); break;
	case 3 : DIO_u8SetPortValue(SSD->PORT,~(0b01001111)); break;
	case 4 : DIO_u8SetPortValue(SSD->PORT,~(0b01100110)); break;
	case 5 : DIO_u8SetPortValue(SSD->PORT,~(0b00111111)); break;
	case 6 : DIO_u8SetPortValue(SSD->PORT,~(0b01111100)); break;
	case 7 : DIO_u8SetPortValue(SSD->PORT,~(0b00000111)); break;
	case 8 : DIO_u8SetPortValue(SSD->PORT,~(0b01111111)); break;
	case 9 : DIO_u8SetPortValue(SSD->PORT,~(0b01100111)); break;
	}
	else if (SSD->COM_Type == SSD_u8COM_Cathode)
		switch(Copy_u8Number){
		case 0 : DIO_u8SetPortValue(SSD->PORT,0b00111111); break;
		case 1 : DIO_u8SetPortValue(SSD->PORT,0b00000110); break;
		case 2 : DIO_u8SetPortValue(SSD->PORT,0b01011011); break;
		case 3 : DIO_u8SetPortValue(SSD->PORT,0b01001111); break;
		case 4 : DIO_u8SetPortValue(SSD->PORT,0b01100110); break;
		case 5 : DIO_u8SetPortValue(SSD->PORT,0b00111111); break;
		case 6 : DIO_u8SetPortValue(SSD->PORT,0b01111100); break;
		case 7 : DIO_u8SetPortValue(SSD->PORT,0b00000111); break;
		case 8 : DIO_u8SetPortValue(SSD->PORT,0b01111111); break;
		case 9 : DIO_u8SetPortValue(SSD->PORT,0b01100111); break;
		}
	else {
		Local_ErrorState=1;
	}
	
	return Local_ErrorState;
}
