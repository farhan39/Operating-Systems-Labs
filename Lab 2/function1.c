#include<stdio.h>
#include<stdlib.h>

void highestNumber (char* arr, int size)
{
 	char max = arr[size - 1];
	for (int i = size - 1; i >= 0; --i)
		if (arr[i] > max)
			max = arr[i];
	printf("max number is : %d", int(max));
	printf("\n");
}
