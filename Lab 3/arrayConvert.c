#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{	
	char* args[argc];
	int k = 1;
	for (int i = 1; i < argc; ++i)	//started from 1 as first argument is always filename
		if (((argv[i] >= 65 && argv[i] <= 90) || (argv[i] >= 97 && argv[i] <= 122)) || (argv[i] >= 48 && argv[i] <= 57))
		{
				args[k] = argv[i];
				++k;
		}
	args[k] = NULL;
	execv("./findTotalElementsAndSizeInBytes", args);
	return 0;
}
