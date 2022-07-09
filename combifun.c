#include <stdio.h>
#include "combilib.h" //including combilib where all all function prototypes reside.
#include <ncurses.h>
#include <string.h>


void showMainWindow(void)
{
	char mainStr1[] = "-----------------\n| ";
	char mainStr2[] = " CombinaCount ";
	char mainStr3[] = "|\n|";
	char mainStr4[] = " version: 1.0.0 ";
	char mainStr5[] = "|\n----------------\n\n";
	char *ch1, *ch2;
	char inputCommand[5];
	char mainCommands[7][5] = { {"fact"},{"perm"},{"ster"},{"part"},{"comb"},{"mcom"},{"quit"} };//quit used next version.
	int mainInt1;
	int mainInt2;
	ch1 = mainStr2;
	ch2 = mainStr4;
	addstr(mainStr1);
	move(1,14);
	addstr(mainStr3);
	move(2,15);
	addstr(mainStr5);
	move(1,1);
	while(*ch1)
	{
		addch(*ch1);
		ch1++;
		refresh();
		napms(100);
	}
	move(2,1);
	while(*ch2)
	{
		addch(*ch2);
		ch2++;
		refresh();
		napms(100);
	}
	move(5,0);
	attron(A_BLINK);
	addstr(">> ");
	attrset(A_NORMAL);
	scanw("%s %d %d",inputCommand,&mainInt1,&mainInt2);
	move(7,2);
	addstr(">>");
	move(7,5);
	if(strcmp(inputCommand,mainCommands[0]) == 0)
	{
		printw("factorial\n");
		int arrLength;
		int *parrLength;
		parrLength = &arrLength;
		int * pLargeNum;
		pLargeNum = factorial(mainInt1,parrLength);
		printw(" ans = ");
		for(int i = arrLength - 1; i >= 0;i--)
		{
			printw("%d",*(pLargeNum + i));	
		}
		printw("\n>> ");	
	}
	else if(strcmp(inputCommand,mainCommands[1]) == 0)
	{
		printw("permutation\n");
		int arrLength;
		int *parrLength;
		parrLength = &arrLength;
		int * pLargeNum;
		pLargeNum = permutation(mainInt1,mainInt2,parrLength);
		printw(" ans = ");
		for(int i = arrLength - 1; i >= 0;i--)
		{
			printw("%d",*(pLargeNum + i));	
		}
		printw("\n>> ");

	}
	
	//printw("\ntest rn %s%s %d %d",mainCommands[0],inputCommand,mainInt1,mainInt2);//test rm
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

int * factorial(int n,int *arrLen)
{
	static int largeNum[500];
	largeNum[0] = 1;
	int arrLength = 1;
	int i;
	for(i = 2; i <= n;i++)
	{
		arrLength = multiply(i,largeNum,arrLength);
	}
	*arrLen = arrLength; 
	return largeNum;// Number stored in reverse order.
}


int * permutation(int n, int r, int *arrLen)
{
	static int largeNum[500];
	largeNum[0] = 1;
	int arrLength = 1;
	int i;
	for(i = n - r + 1; i <= n;i++)
	{
		arrLength = multiply(i,largeNum,arrLength);
	}
	*arrLen = arrLength; 
	return largeNum;
}
