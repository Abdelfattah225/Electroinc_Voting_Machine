/*****************************************************************************/

/* File Defination :
 *
 * File 		: Common_Marcos.h
 *
 * Created on	: Aug 29, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/

#ifndef LIB_COMMON_COMMON_MACROS_H_
#define LIB_COMMON_COMMON_MACROS_H_

/* set any bit in any register*/
#define set_bit(reg,bit) (reg)|=(1<<(bit))
/* clear any bit in any register*/
#define clear_bit(reg,bit) (reg)&= ~(1<<(bit))
/* toggle any bit in any register*/
#define toggle_bit(reg,bit) (reg)^=(1<<(bit))
/* git any bit in any register*/
#define get_bit(reg,bit) ((reg>>bit)&1)


#endif /* LIB_COMMON_COMMON_MACROS_H_ */
