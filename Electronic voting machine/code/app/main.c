/*/*****************************************************************************/

/* File Defination :
 *
 * File 		: main.c
 *
 * Created on	: Sep 9, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/



#include"app.h"
#include<util/delay.h>

#define F_CPU 8000000UL
int main(){

	APP_Init();
	APP_WelcomeScreen();
	_delay_ms(200);
	while(1)
	{
		APP_SecondInput();
		_delay_ms(200);

	}
}

