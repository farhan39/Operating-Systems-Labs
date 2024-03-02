#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{	
	int fd1;
	char buffer[1000];
	fd1 = open("file.txt", O_RDONLY);
	
	int z = open("fifo1", O_WRONLY);
	
	read(fd1, &buffer, 1000);
	write(z, &buffer, 1000);
	
	close(z);
	close(fd1);
	
	return 0;
}
