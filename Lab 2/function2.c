#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool sortedOrNot(char* arr, int size)
{
	for (int i = 0; i < size; ++i)
		if (arr[i] > arr[i + 1])
			return 0;
	return 1;
}
