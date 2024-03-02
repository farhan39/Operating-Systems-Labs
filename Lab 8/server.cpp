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
	char data[size];
	int id = shmget(key, size, 0);
	void* ptr = shmat(id, NULL, 0);
	
	char* ptr1 = (char*)ptr;
	strncpy(data, ptr1, size);
	
	cout << "\nExtracted numbers are: \n";
	for (int i = 0; i < size; ++i)
		cout << data[i] << " ";
	
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += int(data[i] - 48);
	}
		
	cout << "\nSum: " << sum;
	cout << "\nAverage: " << sum/size;
	
	return 0;
}
