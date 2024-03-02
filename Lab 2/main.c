#include<stdio.h>
#include"function1.c"
#include"function2.c"

int main (int n, char** argv)
{
	highestNumber(*argv, n);
	if(sortedOrNot(*argv, n))
		printf("Array is sorted.\n");
	else printf("Array is not sorted.\n");
	return 0;
}
