#ifndef BIT_MATH_H

#define BIT_MATH_H


#define SET_BIT(NUM,BIT_NUM)   NUM |=  (1 << BIT_NUM)
#define CLR_BIT(NUM,BIT_NUM)   NUM &= ~(1 << BIT_NUM)
#define TGL_BIT(NUM,BIT_NUM)   NUM ^=  (1 << BIT_NUM)
#define	GET_BIT(NUM,BIT_NUM)	(NUM >> BIT_NUM) & 1

#endif