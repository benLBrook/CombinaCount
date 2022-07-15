void showMainWindow(void);
int multiply(int num,int largeNum[],int arrLength);//multiply function for large numbers stored in arrays.
int divide(int num,int largeNum[],int arrLength); 
int * factorial(int n,int *arrLen);
//int smallFactorial(int n);// can only do atmost 12!, switching to long long to cover upto  MAX LONG LONG<21!  
int * permutation(int n, int r, int *arrLen);
//int * combination(int n, int r, int *arrLen); //modify for larger nums.
int combination(int n, int k);
void swap(int * x, int * y);
void reverseArray(int LargeNum[],int arrLen);
int findMin(int x, int y);