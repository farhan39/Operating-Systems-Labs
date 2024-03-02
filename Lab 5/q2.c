#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main ()
{
	int fd1[2];
	char buffer[100];
	
	pipe(fd1);
	
	pid_t pid = fork();
	
	if (pid > 0)
	{
		int myarr1[10] = {0, 1, 2, 4, 5, 1, 67, 11, 12, 8};
		
		printf("Original Array :");
		for (int i = 0; i < 10; ++i)
		{
			write(fd1[1], &myarr1[i], 1);
			printf("\n%d", myarr1[i]);
		}
		
		close(fd1[1]);
		wait(NULL);
	}
	
	else if (pid == 0)
	{
		int myarr2[10];
		
		int sum = 0, average = 0, min = 0, max = 0;
		
		for (int i = 0; i < 10; ++i)
		{
			read(fd1[0], &myarr2[i], 1);
			sum += myarr2[i];
			
			if (min > myarr2[i])
				min = myarr2[i];
			if (max < myarr2[i])
				max = myarr2[i];
		}
		
		printf("Sum : %d", sum);
		printf("\nAverage : %d", sum/10);
		printf("\nMin : %d", min);
		printf("\nMax : %d", max);
		printf("\n");
		close(fd1[0]);
	}
	
	return 0;
}
