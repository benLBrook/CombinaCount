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

int multiply(int num, int largeNum[],int arrLength)
{
	int carry = 0;
	int i;
	for(i = 0; i < arrLength; i++)
	{
		int product = largeNum[i] * num + carry;
		largeNum[i] = product % 10;
		carry = product / 10;
	}

	while(carry)
	{
		largeNum[arrLength] = carry % 10;
		carry = carry / 10;
		arrLength++;
	}
	return arrLength;
}

int * factorial(int n)
{
	int largeNum[500];
	largeNum[0] = 1;
	int arrLength = 1;
	int i;
	for(i = 2; i <= n;i++)
	{
		arrLength = multiply(i,largeNum,arrLength);
	}
	return largeNum;// Number stored in reverse order.
}