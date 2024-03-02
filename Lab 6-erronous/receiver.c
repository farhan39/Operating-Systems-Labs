#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{	
	int z = open("fifo1", O_RDONLY);
	char buffer[1000];
	
	int fd1 = open("updated.txt", O_WRONLY);
	read(z, &buffer, 1000);
	
	int numLength = 0;
	
	for (int i = 0; buffer[i] != '\0'; ++i)
	{
		if (buffer[i] == ' ')
		{
			int j = i - 1;
		
			int* num = (int*)malloc (numLength * sizeof(int));
			bool palindrome = true;
			
			for (int numIndex = 0, bufferIndex = j; numIndex < numLength; ++numIndex, --bufferIndex)
				num[numIndex] = buffer[bufferIndex];
					
			for (int numIndex  = 0, bufferIndex = j - numLength; numIndex != j; ++numIndex, ++bufferIndex)
				if (num[numIndex] != buffer[bufferIndex])
					palindrome = false;
			
			if (palindrome)
			{
				write(fd1, &num, 4 * numLength);
			}
			
			numLength = 0;
			free(num);
		}
		
		else ++numLength;
	}
	
	close(z);
	close(fd1);
//	fclose(fifo1);
	
	return 0;
}
