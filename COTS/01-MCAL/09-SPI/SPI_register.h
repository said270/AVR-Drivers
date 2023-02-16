/***********************************************/
/***********************************************/
/*************   Author: Saied Kamara    *********/
/*************   Layer: MCAL             *****************/
/*************   SWC: SPI               *********************/
/*************   Version: 1.0            *****************/
/***********************************************/
/***********************************************/
#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

#define SPDR     *((volatile u8*)0x2F)       //SPI data register

#define SPSR     *((volatile u8*)0x2E)      //SPI Status register
#define SPSR_SPIF   7                       //interrupt flag
#define SPSR_SPI2X  0                       //prescalar 2

#define SPCR     *((volatile u8*)0x2D)     //SPI control register
#define SPCR_SPE   6                       //SPI enable
#define SPCR_MSTR  4                      //SPI master bit
#define SPCR_SPR1  1                      //SPI prescalar 0 , 1
#define SPCR_SPR0  0


#endif
