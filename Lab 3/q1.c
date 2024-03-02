#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int fd_read = open("readfile.txt", O_RDONLY);
	int fd_write = open("writefile.txt", O_WRONLY);
	char c[100];
	
	while (read(fd_read, c, 1))	// reads 1 character at a time
	{
		lseek(fd_read, 1, SEEK_CUR);
		write(fd_write, c, 1);
	}
	
	close(fd_read);
	
	fd_read = open("writefile.txt", O_RDONLY);
	read(fd_read, c, 15);
	
	puts(c);
	
	close(fd_read);
	close(fd_write);
	
	return 0;
}
