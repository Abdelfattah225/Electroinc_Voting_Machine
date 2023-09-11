/*/*****************************************************************************/

/* File Defination :
 *
 * File 		: keypad.c
 *
 * Created on	: Sep 9, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/

/*include*/

#include <avr/io.h>
#include "keypad.h"
#include "Common_Macros.h"
#include "DIO.h"


/*
*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void)
{
	uint8 row,col;
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID,INPUT);
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+1,INPUT);
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+2,INPUT);
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+3,INPUT);

	GPIO_setupPinDirection(KEYPAD_COLS_PORT_ID,KEYPAD_FIRST_COL_PIN_ID,INPUT);
	GPIO_setupPinDirection(KEYPAD_COLS_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+1,INPUT);
	GPIO_setupPinDirection(KEYPAD_COLS_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+2,INPUT);
#if (KEYPAD_NUM_OF_COLS==4)
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+3,INPUT);
#endif

	while(1)
	{
		for(row=0;row<KEYPAD_NUM_OF_ROWS;row++)
		{
			GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+row,OUTPUT);
			GPIO_writePin(KEYPAD_ROWS_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID+row, KEYPAD_BUTTON_PRESSED);

			for(col=0;col<KEYPAD_NUM_OF_COLS;col++)
			{
				if(GPIO_readPin(KEYPAD_COLS_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+col) == KEYPAD_BUTTON_PRESSED)
				{
					#if (KEYPAD_NUM_COLS == 3)

					#ifdef STANDARD_KEYPAD
						return ((row*KEYPAD_NUM_COLS)+col+1);
					#else
						return KEYPAD_4x3_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#endif

					#elif (KEYPAD_NUM_COLS == 4)

					#ifdef STANDARD_KEYPAD
						return ((row*KEYPAD_NUM_COLS)+col+1);
					#else
						return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#endif
					#endif

				}
			}
			GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+row,OUTPUT);
		}
	}
}
