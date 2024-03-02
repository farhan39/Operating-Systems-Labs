#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int size = 0;
	for (int i = 1; i < argc; ++i)
	{
		if (*argv[i] >= 48 && *argv[i] <= 57)
			size += 4;
		else ++size;
	}
	
	printf("\nTotal elements are : %d", argc);
	printf("\nSize is : %d", size);
	return 0;
}
