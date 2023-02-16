/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/

/*************   Layer: HAL             *****************/
/*************   SWC: KEYPAD                *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"


u8 KEYAD_u8GetPressedKey()
{
	u8 Local_u8PressedKey=KEYPAD_NO_PRESSED_KEY;
	u8 Local_u8ColumnIndex , Local_u8RowIndex, Local_u8PinState;

	static u8 Local_u8KPDArr[4][4]=KPD_ARR_VAL;
	static u8 Local_u8KPDColumnArr[COLUMN_NUMNER]={KEYPAD_COLUMN0_PIN,KEYPAD_COLUMN1_PIN,KEYPAD_COLUMN2_PIN,KEYPAD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUMNER]={KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};

	for (Local_u8ColumnIndex=0 ; Local_u8ColumnIndex <COLUMN_NUMNER ; Local_u8ColumnIndex++){

		/* Activate Current Column */
		DIO_u8SetPinValue(KEYPAD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);

		for(Local_u8RowIndex=0 ; Local_u8RowIndex < ROW_NUMNER;Local_u8RowIndex=0){
			/* Read Current Row */
			DIO_u8GetPinValue(KEYPAD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinState);
			/* Check if switch is pressed */
           if (Local_u8PinState == DIO_u8PIN_LOW ){
        	   Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
        	   /* Pooling till switch is unpressed */
        	   while (Local_u8PinState == DIO_u8PIN_LOW)
        	   {
        		   DIO_u8GetPinValue(KEYPAD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinState);
        	   }
        	   return Local_u8PressedKey;
           }
		}
		/* Deactivate Current Column */
		DIO_u8SetPinValue(KEYPAD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}
