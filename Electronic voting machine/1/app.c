/*****************************************************************************/

/* File Defination :
 *
 * File 		: App.c
 *
 * Created on	: Sep 9, 2023
 *
 * Author 		: ABDELFATTAH MOAWED
 */
/*****************************************************************************/



/**********************************include************************************/
/******************************************************************************/


#include"app.h"
#include"gpio.h"
#include"gpio.h"
#include"std_types.h"
#include"lcd.h"
#include"keypad.h"
#include<util/delay.h>



/*******************************************************************************
 *                              Global Variables	                           *
 *******************************************************************************/

static uint8 i=0;
static uint8 j=0;
static uint8 k=0;
static uint8 L=0;

/******************************Local Functions Prototypes *******************/
/*****************************************************************************/



static void APP_MainMenuScreen();

static void APP_Increment_A();
static void APP_Increment_C();
static void APP_Increment_B();
static void APP_Increment_D();
static void APP_WrongInput();
static void APP_Reset();
static void APP_Winner();



/*
************************************Functions definition***********************                         *
 *******************************************************************************/


/********A function to initialize the Application******/\
void APP_Init(){
	LCD_init();
}


void APP_WelcomeScreen(){

	/* display "Welcome" */
	LCD_clearScreen();
	LCD_displayString("Welcome");
	_delay_ms(SHORT_DELAY);
	LCD_clearScreen();
	LCD_displayString("1-to vote for A");
	LCD_moveCursor(1, 0);
	LCD_displayString("2-to vote for B");
	_delay_ms(750);
	LCD_clearScreen();
	LCD_displayString("3-to vote for C");
	LCD_moveCursor(1, 0);
	LCD_displayString("4-to vote for D");
	_delay_ms(750);
	LCD_clearScreen();
	LCD_displayString("5-for Reset");
	LCD_moveCursor(1, 0);
	LCD_displayString("6-the winner is ?");
	_delay_ms(750);
	LCD_clearScreen();
	/* Move to the next window ( Main Menu Screen )*/
	APP_MainMenuScreen();
}

/*A function to display the main menu*/
static void APP_MainMenuScreen(){

	/* display : -
	 * "A=0     B=0 "
	 * "C=0     D=0 "
	 */
	LCD_clearScreen();
	LCD_displayString("A=0      B=0");
	LCD_moveCursor(1, 0);
	LCD_displayString("C=0      D=0");

	/* Get the user decision */
	uint8 pressedKey = KEYPAD_getPressedKey();

	/* User choice is toincrement vlaue of A*/
	if(pressedKey == 1)
	{
		/* Move to increment vlaue of A  screen*/
		APP_Increment_A();
	}

	/* User choice is toincrement vlaue of B*/
	else if(pressedKey == 2)
	{
		/* Move to increment vlaue of A  screen*/
		APP_Increment_B();
	}
	/* User choice is to increment vlaue of c*/
	else if(pressedKey == 3)
	{
		/* Move to increment vlaue of c  screen*/
		APP_Increment_C();
	}
		/* User choice is to increment vlaue of D*/
	else if(pressedKey == 4)
	{
		/* Move to increment vlaue of D  screen*/
		APP_Increment_D();
	}
	/* User choice is to reset application*/
	else if(pressedKey == 5)
		{

			APP_Reset();
		}

	/* User choice is to determine the winner*/
	else if(pressedKey == 6)
	{
		APP_Winner();
	}
	/* User choice is unknown , so get back to wrong input screen */
	else
	{
		/* display : -
		 * "Wrong Input"
		 * "A,B,C or D only"
		 */
		LCD_clearScreen();
		LCD_displayString("Wrong Input");
		_delay_ms(SHORT_DELAY);
		LCD_clearScreen();
		LCD_displayString("1-to vote for A");
		LCD_moveCursor(1, 0);
		LCD_displayString("2-to vote for B");
		_delay_ms(750);
		LCD_clearScreen();
		LCD_displayString("3-to vote for C");
		LCD_moveCursor(1, 0);
		LCD_displayString("4-to vote for D");
		_delay_ms(750);
		LCD_clearScreen();
		LCD_displayString("5-for Reset");
		LCD_moveCursor(1, 0);
		LCD_displayString("6-the winner is ?");
		_delay_ms(750);
		LCD_clearScreen();

		/* Move to the menu screen again */
		APP_WrongInput();
	}
}



 void APP_SecondInput()
{
	/* Get the user decision */
		uint8 pressedKey = KEYPAD_getPressedKey();

		/* User choice is to increment vlaue of A*/
		if(pressedKey == 1)
		{
			/* Move to increment vlaue of A  screen*/
			APP_Increment_A();

		}

		/* User choice is to increment vlaue of B*/
		else if(pressedKey == 2)
		{

			/* Move to increment vlaue of A  screen*/
			APP_Increment_B();
		}
		/* User choice is to increment vlaue of c*/
		else if(pressedKey == 3)
		{
			/* Move to increment vlaue of c  screen*/
			APP_Increment_C();
		}
			/* User choice is to increment vlaue of D*/
		else if(pressedKey == 4)
		{
			/* Move to increment vlaue of D  screen*/
			APP_Increment_D();
		}
		/* User choice is to reset application*/
		else if(pressedKey == 5)
			{

				APP_Reset();
			}

		/* User choice is to determine the winner*/
		else if(pressedKey == 6)
		{
			APP_Winner();
		}
		/* User choice is unknown , so get back to welcome screen */
		else
		{
			/* display : -
			 * "Wrong Input"
			 * "A,B,C or D only"
			 */
			LCD_clearScreen();
			LCD_displayString("Wrong Input");
			_delay_ms(SHORT_DELAY);
			LCD_clearScreen();
			LCD_displayString("1-to vote for A");
			LCD_moveCursor(1, 0);
			LCD_displayString("2-to vote for B");
			_delay_ms(750);
			LCD_clearScreen();
			LCD_displayString("3-to vote for C");
			LCD_moveCursor(1, 0);
			LCD_displayString("4-to vote for D");
			_delay_ms(750);
			LCD_clearScreen();
			LCD_displayString("5-for Reset");
			LCD_moveCursor(1, 0);
			LCD_displayString("6-the winner is ?");
			_delay_ms(750);
			LCD_clearScreen();
			/* Move to the menu screen again */
			APP_WrongInput();
		}
}


/*functions to make increment A,B,C,D */


static void APP_Increment_A()
{


	i++;
	LCD_moveCursor(0,2);
	LCD_integerToString(i);

}



static void APP_Increment_B()
{
	j++;
	LCD_moveCursor(0,11);
	LCD_integerToString(j);

}



static void APP_Increment_C()
{
	k++;
	LCD_moveCursor(1,2);
	LCD_integerToString(k);

}


static void APP_Increment_D()
{
	L++;
	LCD_moveCursor(1,11);
	LCD_integerToString(L);


}

/**************************************************/
/*functions to Warin the user */


static void APP_WrongInput()
{
	LCD_clearScreen();
	LCD_displayString("A=       B=");
	LCD_moveCursor(0,2);
	LCD_integerToString(i);
	LCD_moveCursor(0,11);
	LCD_integerToString(j);
	LCD_moveCursor(1, 0);
	LCD_displayString("C=       D=");
	LCD_moveCursor(1,2);
	LCD_integerToString(k);
	LCD_moveCursor(1,11);
	LCD_integerToString(L);
	/* Get the user decision */
		uint8 pressedKey = KEYPAD_getPressedKey();

		/* User choice is toincrement vlaue of A*/
		if(pressedKey == 1)
		{
			/* Move to increment vlaue of A  screen*/
			APP_Increment_A();
		}

		/* User choice is toincrement vlaue of B*/
		else if(pressedKey == 2)
		{
			/* Move to increment vlaue of A  screen*/
			APP_Increment_B();
		}
		/* User choice is to increment vlaue of c*/
		else if(pressedKey == 3)
		{
			/* Move to increment vlaue of c  screen*/
			APP_Increment_C();
		}
			/* User choice is to increment vlaue of D*/
		else if(pressedKey == 4)
		{
			/* Move to increment vlaue of D  screen*/
			APP_Increment_D();
		}
		/* User choice is to reset application*/
		else if(pressedKey == 5)
			{

				APP_Reset();
			}

		/* User choice is to determine the winner*/
		else if(pressedKey == 6)
		{
			APP_Winner();
		}
		/* User choice is unknown , so get back to welcome screen */
		else
		{
			/* display : -
			 * "Wrong Input"
			 * "A,B,C or D only"
			 */
			LCD_clearScreen();
			LCD_displayString("Wrong Input");
			_delay_ms(SHORT_DELAY);
			LCD_clearScreen();
			LCD_displayString("1-to vote for A");
			LCD_moveCursor(1, 0);
			LCD_displayString("2-to vote for B");
			_delay_ms(750);
			LCD_clearScreen();
			LCD_displayString("3-to vote for C");
			LCD_moveCursor(1, 0);
			LCD_displayString("4-to vote for D");
			_delay_ms(750);
			LCD_clearScreen();
			LCD_displayString("5-for Reset");
			LCD_moveCursor(1, 0);
			LCD_displayString("6-the winner is ?");
			_delay_ms(750);
			LCD_clearScreen();
			/* Move to the menu screen again */
			APP_WrongInput();
		}
}




/*a function to reset application*/

static void APP_Reset()
{
	i=0;
	j=0;
	k=0;
	L=0;
	LCD_clearScreen();
	LCD_displayString("Reset.");
	_delay_ms(500);
	LCD_clearScreen();
	LCD_displayString("Reset..");
	_delay_ms(500);
	LCD_clearScreen();
	LCD_displayString("Reset...");
	_delay_ms(500);

	APP_WelcomeScreen();
}

/*fucntion to detect who the winer*/
static void APP_Winner()
{
	uint8 winner = i;
	if(winner<=j)
		winner=j;
	if(winner<=k)
		winner=k;
	if(winner<=L)
		winner=L;
	LCD_clearScreen();

	if(winner==i)
		LCD_displayString("The winner is A");
	else if(winner==j)
		LCD_displayString("The winner is B");
	else if(winner==k)
			LCD_displayString("The winner is C");
	else if(winner==L)
			LCD_displayString("The winner is D");


}
