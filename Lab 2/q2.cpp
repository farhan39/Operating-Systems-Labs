#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fstream>

using namespace std;

int main()
{
	pid_t pid;
	pid = fork();
	
	if (pid == 0)
	{
		ifstream fin;
		fin.open("inputFile.txt");
		
		ofstream fout;
		fout.open("outputFile.txt");
		
		int n;
		while (!fin.eof())
		{
			fin >> n;
			if (n > 48 && n < 57)
				fout << n;
		}
		
		fin.close();
		fout.close();
	}
	
	else if (pid > 0)
	{
		wait(NULL);
		
		ifstream fin1;
		fin1.open("outputFile.txt");
		
		int n = 0, sum = 0, average = 0, count = 0;
		
		while (!fin1.eof())
		{
			fin1 >> n;
			sum += n;
			++count;
		}
		
		fin1.close();
		
		cout << "Sum = " << sum;
		cout << "\nAverage = " << sum/count << endl;
	}
	
	return 0;
}
