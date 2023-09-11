/*/*****************************************************************************/

/* File Defination :
 *
 * File 		: keypad.h
 *
 * Created on	: Sep 9 , 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "STD_TYPES.h"

/*keypad configurations*/
#define KEYPAD_NUM_OF_COLS		4
#define KEYPAD_NUM_OF_ROWS		4
/*keypad port configurations*/
#define KEYPAD_ROWS_PORT_ID	 		 	PORTB_ID
#define KEYPAD_FIRST_ROW_PIN_ID			PIN4_ID
#define KEYPAD_COLS_PORT_ID				PORTD_ID
#define KEYPAD_FIRST_COL_PIN_ID			PIN2_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH


/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void);


#endif /* HAL_KEYPAD_KEYPAD_H_ */
