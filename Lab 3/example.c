#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	printf("PID of example.c is %d\n", getpid());
	char* args[] = {"./hello.c", "C", "Programming", NULL};
	execv(args[0], args);
	printf("Back to example.c\n");
	return 0;
}
