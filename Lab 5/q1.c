#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main ()
{
	char c[100];
	int fd1, fd2;
	
	int p_id = fork();
	
	if (p_id > 0)
	{
		wait(NULL);
	}
	
	else if (p_id == 0)
	{	
		fd1 = open("file.txt", O_WRONLY);
		write(fd1, "hello\n", 6);
		fd2 = dup(fd1);
		write(fd2, "world\n", 6);
	}
	
	return 0;
}
