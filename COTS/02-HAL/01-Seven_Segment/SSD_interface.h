#ifndef SSD_INTERFACE_H

#define SSD_INTERFACE_H

typedef struct {
	u8 COM_Type;
	u8 PORT;
	u8 Enable_PORT;
	u8 Enable_PIN;
}SSD_Init;

#define SSD_u8COM_Anode   0
#define SSD_u8COM_Cathode 1

u8 SSD_u8EnableSSD(SSD_Init * SSD);
u8 SSD_u8DisableSSD(SSD_Init * SSD);
u8 SSD_u8SetNumber(SSD_Init * SSD,u8 Copy_u8Number);





#endif
