#include <stdio.h>
#include "combilib.h" //including combilib where all all function prototypes reside.
#include <ncurses.h>
#include <string.h>


void showMainWindow(void)
{
	char mystring[] = "hello";
	addstr(mystring);
	refresh();
	getch();// this could also be in the main function instead.
	
}

