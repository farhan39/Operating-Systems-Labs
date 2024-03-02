#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

int main() 
{
    int fd1[2], fd2[2];
    pid_t pid;
    
    char buffer[BUFFER_SIZE];

    if (pipe(fd1) == -1 || pipe(fd2) == -1) 
    {
        fprintf(stderr, "pipe error");
        exit(1);
    }

    pid = fork();

    if (pid < 0) 
    {
        fprintf(stderr, "fork error");
        exit(1);
    } 
    
    else if (pid > 0) 
    {
        // Parent process
        close(fd1[0]); // Close the read end of the first pipe
        close(fd2[1]); // Close the write end of the second pipe

        // Read data from the file
        FILE *file = fopen("file.txt", "r");
        
        if (file == NULL) 
        {
            fprintf(stderr, "file error");
            exit(1);
        }

        while (fgets(buffer, BUFFER_SIZE, file)) 
        {
            // Write data to the first pipe
            if (write(fd1[1], buffer, BUFFER_SIZE) == -1) 
            {
                fprintf(stderr, "write error");
                exit(EXIT_FAILURE);
            }

            // Read modified data from the second pipe
            if (read(fd2[0], buffer, BUFFER_SIZE) == -1) 
            {
                fprintf(stderr, "read error");
                exit(EXIT_FAILURE);
            }

            // Write modified data to the file
            FILE *updated = fopen("updated.txt", "a");
            
            if (updated == NULL) 
            {
                fprintf(stderr, "file error");
                exit(EXIT_FAILURE);
            }

            fprintf(updated, "%s", buffer);
            fclose(updated);
        }

        // Close file and pipes
        fclose(file);
        close(fd1[1]);
        close(fd2[0]);

        // Wait for child process to exit
        wait(NULL);

        exit(EXIT_SUCCESS);
    } 
    
    else 
    {
        // Child process
        close(fd1[1]); // Close the write end of the first pipe
        close(fd2[0]); // Close the read end of the second pipe

        // Read data from the first pipe
        if (read(fd1[0], buffer, BUFFER_SIZE) == -1) 
        {
            perror("read error");
            exit(EXIT_FAILURE);
        }

        // Modify the data
        int len = strlen(buffer);
        for (int i = 0; i < len; i++) 
        {
            if (buffer[i] == '&' || buffer[i] == '@' || buffer[i] == '#' ||
                buffer[i] == '%' || buffer[i] == '*' || buffer[i] == '?' ||
                buffer[i] == '$' || buffer[i] == '"' || buffer[i] == '~') 
        	{
               	 buffer[i] = ' ';
	        }
        }

        // Write modified data to the second pipe
        if (write(fd2[1], buffer, BUFFER_SIZE) == -1) 
        {
            perror("write error");
            exit(EXIT_FAILURE);
        }

        // Close pipes
        close(fd1[0]);
        close(fd2[1]);

        exit(0);
    }

    return 0;
}
