/*/*****************************************************************************/

/* File Defination :
 *
 * File 		: DIO.c
 *
 * Created on	: Sep 11, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/

/* INCLUDE :
 * ****************************************************************
 * ************************* include ******************************
 */
#include<avr/io.h>
#include<avr/delay.h>
#include<Common_Macros.h>
#include "DIO.h"




/* Defination :
 *
 * function will setup any pin to input/output
 * it will take port , pin , direction(INPUT OR OUTPUT)
 */



void GPIO_setupPinDirection(uint8 port , uint8 pin , GPIO_PinDirectionType direction )
{
	switch(port)
	{
	/*set direction register DDRA*/
	case PORTA_ID:

		if(direction== OUTPUT)
		{
			set_bit(DDRA,pin);
		}
		else if(direction==INPUT)
		{
			clear_bit(DDRA,pin);
		}

			break;
	/*set direction register DDRB*/
	case PORTB_ID:

		if(direction== OUTPUT)
			{
				set_bit(DDRB,pin);
			}
			else if(direction==INPUT)
			{
				clear_bit(DDRB,pin);
			}
			break;

	/*set direction register DDRC*/
	case PORTC_ID:
		if(direction== OUTPUT)
			{
				set_bit(DDRC,pin);
			}
			else if(direction==INPUT)
			{
				clear_bit(DDRC,pin);
			}
			break;
	/*set direction register DDRD*/
	case PORTD_ID:
		if(direction== OUTPUT)
			{
				set_bit(DDRD,pin);
			}
			else if(direction==INPUT)
			{
				clear_bit(DDRD,pin);
			}
			break;
	}
}




/* Defintation :
 *
 * function will setup status of the pin if it was ouput-----> it will (HIGH OR LOW)
 * function take port , pin and status
 */



void GPIO_writePin(uint8 port ,uint8 pin , GPIO_PinWriteType value)
{


	if(pin>PIN7_ID||pin<PIN0_ID||(value!=1 && value!=0))
	{
		/*do noting*/
	}
	else
	{
	switch(port)
	{
	/*set ouput of register DDRA*/

	case PORTA_ID:
		if(value==LOW)
		{
			clear_bit(PORTA,pin);
		}
		else if(value==HIGH)
		{
			set_bit(PORTA,pin);
		}
			break;
	/*set ouput of register DDRB*/

	case PORTB_ID:
		if(value==LOW)
			{
				clear_bit(PORTB,pin);
			}
			else if(value==HIGH)
			{
				set_bit(PORTB,pin);
			}
			break;
	/*set ouput of register DDRC*/

	case PORTC_ID:
		if(value==LOW)
			{
				clear_bit(PORTC,pin);
			}
			else if(value==HIGH)
			{
				set_bit(PORTC,pin);
			}
			break;
	/*set ouput of register DDRA*/

	case PORTD_ID:

		if(value==LOW)
			{
				clear_bit(PORTD,pin);
			}
			else if(value==HIGH)
			{
				set_bit(PORTD,pin);
			}

			break;

	}
	}
}




/* Defintation :
 * fucntion to read Is pin contain 1 or 0?
 * function takes port and pin
 */
uint8 GPIO_readPin(uint8 port , uint8 pin)
{
	switch(port)
	{
		uint8 localReading = 0x00;
	case PORTA_ID:
		localReading=get_bit(PINA,pin);
		return localReading;
		break;
	case PORTB_ID:
		localReading=get_bit(PINB,pin);
		return localReading;
			break;
	case PORTC_ID:
		localReading=get_bit(PINC,pin);
		return localReading;
			break;
	case PORTD_ID:
		localReading=get_bit(PIND,pin);
		return localReading;
			break;

	}
}







/* Defination :
 *
 *  * function will setup any port to input/output
 * it will take port and direction(POTA_INPUT 0  OR PORT_OUTPUT 1)
 */

void GPIO_setupPortDirection(uint8 port , GPIO_PortDirectionType value)
{
	if(port>PORTD_ID||port<PORTA_ID)
		{
			/*do noting*/
		}

		else
		{
	switch(port)
	{
	case PORTA_ID:
			DDRA=value;
			break;
		case PORTB_ID:
			DDRB=value;
				break;
		case PORTC_ID:
			DDRC=value;
				break;
		case PORTD_ID:
			DDRD=value;
				break;
	}
		}
}


void GPIO_writePort(uint8 port , GPIO_PortWriteType value)
{
	if(port>PORTD_ID||port<PORTA_ID)
			{
				/*do noting*/
			}

			else
			{
	switch(port)
		{
		case PORTA_ID:
				PORTA=value;
				break;
			case PORTB_ID:
				PORTB=value;

					break;
			case PORTC_ID:
				PORTC=value;

				break;
			case PORTD_ID:
				PORTD=value;

				break;
		}

			}
}





/* Defination :
* fucntion to read port
 * function takes port and read it
*/
uint8 GPIO_readPort(uint8 port)
{
	if(port>PORTD_ID||port<PORTA_ID)
	{
		return 0;
	}

	else
	{
		switch(port)
		{
		case PORTA_ID:
			return PINA;
		case PORTB_ID:
			return PINB;
		case PORTC_ID:
			return PINC;
		default:
			return PIND;
		}
	}
}





