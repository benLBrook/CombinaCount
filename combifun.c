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

	else if(strcmp(inputCommand,mainCommands[4]) == 0)
	{
		printw("combination\n");
		/*
		int arrLength;
		int *parrLength;
		parrLength = &arrLength;
		int * pLargeNum;
		pLargeNum = combination(mainInt1,mainInt2,parrLength);*/
		int ans = combination(mainInt1,mainInt2);
		printw(" ans = %d",ans);

		/*
		for(int i = arrLength - 1; i >= 0;i--)
		{
			printw("%d",*(pLargeNum + i));	
		} */
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

int divide(int num, int largeNum[],int arrLength)
{
    int currentIndex = 0;
	int finalLength =  arrLength;
    int tempIndex = 0;
    int tempVal = largeNum[currentIndex];
    int carry;
    _Bool zeroTrack = 0;
    int i;
    for(i = 0; i <= arrLength;i++)
    {
        while(tempVal < num)
        {
            if(zeroTrack == 0)
            {
                largeNum[currentIndex] = 0;
                currentIndex++;
				finalLength--;
            }
            if (tempVal == 0)
            {
                tempVal = tempVal*10 + largeNum[tempIndex + 1];
                tempIndex++;
                largeNum[currentIndex] = 0;
                currentIndex++;
                continue;

            }
            
            tempVal = tempVal*10 + largeNum[currentIndex];
            tempIndex++;
        }
        zeroTrack = 1;// array now comsists of significant figures.
        carry = tempVal / num;
        largeNum[currentIndex] = carry;
        currentIndex++;
        tempIndex++;
        tempVal = tempVal - (carry * num);
        if (currentIndex > arrLength - 1)
        {
            break;
        }
        
       

    }
    return finalLength;
    
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

int smallFactorial(int n)
{
	if(n < 2)
	{
		return 1;
	}
	else
	{
		return n*smallFactorial(n - 1);
	}
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

void swap(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void reverseArray(int * pLargeNum,int arrLen)
{
	int i;
	for ( i = 0; i < arrLen / 2; i++)
	{
		swap((pLargeNum + i),(pLargeNum + arrLen - 1 - i));
	}
	
}

/*int * combination(int n, int r, int *arrLen)
{
	int * pLargeNum = NULL;
	printw("works here");
	pLargeNum = permutation(n,r,arrLen);

	reverseArray(pLargeNum,*arrLen);
	*arrLen = divide(smallFactorial(r),pLargeNum,*arrLen); 
	//make sure to dereference and update arrlen
	// *arrLen = the length!
	return pLargeNum;
}*/
int findMin(int x, int y)
{
	if(x > y)
	{
		return y;
	}
	return x;
}

int combination(int n, int r)
{
	int numArray[(n + 1)][(r + 1)];
	int i;
	int j;
	if( r > n)
	{
		return 0;
	}
	for(i = 0; i <= n;i++)
	{
		for(j = 0;j <= r;j++)
		{
			if( j == 0 || i == j)
			{
				numArray[i][j] = 1;
			}
			else
			{
				numArray[i][j] = numArray[i - 1][j - 1] + numArray[i - 1][j];
			}
			
		}
	}
	return numArray[n][r];
}
