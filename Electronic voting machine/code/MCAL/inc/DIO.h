/*/*****************************************************************************/

/* File Defination :
 *
 * File 		: DIO.h
 *
 * Created on	: Sep 11, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/
#include"std_types.h"

#ifndef MCAL_INC_DIO_H_
#define MCAL_INC_DIO_H_

/*DEFINATOINS*/
/*PORTS*/
#define PORTA_ID 	0
#define PORTB_ID 	1
#define PORTC_ID 	2
#define PORTD_ID 	3
/*PINS*/
#define PIN0_ID		0
#define PIN1_ID		1
#define PIN2_ID		2
#define PIN3_ID		3
#define PIN4_ID		4
#define PIN5_ID		5
#define PIN6_ID		6
#define PIN7_ID		7


/*TYPE DECLARATION*/
typedef enum
{
	INPUT,OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

typedef enum
{
	LOW ,
	HIGH
}GPIO_PinWriteType;
												/*FUNCTIONS*/
typedef enum
{
	PORT_LOW ,
	PORT_HIGH=0xff
}GPIO_PortWriteType;


/* Discription :
 *
 * setup the direction of the required pin input/output
 * if port number or pin number is not correct the function will not handle the request
 *
 */
void GPIO_setupPinDirection(uint8 port , uint8 pin , GPIO_PinDirectionType direction );

/* Discription :
 *
 *  setup the output of the required pin LOW/HIGH
 *  * if port number or pin number is not correct the function will not handle the request
 *
 */
void GPIO_writePin(uint8 port ,uint8 pin , GPIO_PinWriteType value);


/* Discription :
 * Read the vlaue of the pin that you need
 * it will return 0/1
 */
uint8 GPIO_readPin(uint8 port , uint8 pin);

/* Discription :
 *
 * setup the direction of the required port input/output
 *
 */
void GPIO_setupPortDirection(uint8 port , GPIO_PortDirectionType value);

/* Discription :
 *
 * to write all port together
 *
 */
void GPIO_writePort(uint8 port , GPIO_PortWriteType value);

/*  Discription :
 *
 *	to read all port together
 *
*/
uint8 GPIO_readPort(uint8 port);


#endif /* MCAL_INC_DIO_H_ */
