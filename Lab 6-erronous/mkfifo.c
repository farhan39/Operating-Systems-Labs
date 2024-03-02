#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int x;
	x = mkfifo("fifo1", 0666);
	printf("A named pipe created");
	return 0;
}
