#include<iostream>
#include<sys/shm.h>
#include<cstring>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>

#define key 5247
#define size 4

using namespace std;

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_RDONLY);
	
	char buff;
	string str;
	int i = 0;
	
	while (i < size)
	{
		read(fd,&buff,1);
		str[i]=buff;
		lseek(fd,1,SEEK_CUR);
		++i;
	}
	
	char arr[size];
	for (int j = 0; j < size; ++j)
		arr[j] = str[j];
	
	int id = shmget(key, size, 0666|IPC_CREAT);
	
	void* ptr = shmat(id, NULL, 0);
	char* ptr1 = (char*)ptr;
	
	strncpy(ptr1, arr, size);
	
	shmdt(ptr);
	shmctl(key, IPC_RMID, NULL);
	
	return 0;
}
