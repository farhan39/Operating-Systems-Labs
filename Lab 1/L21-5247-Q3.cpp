#include<iostream>
#include<stdlib.h>
using namespace std;

int main (int n, char** values)
{
	int sum = 0, average = 0;
	for (int i = 1; i < n; ++i)
		sum += atoi(values[i]);
	cout << "Sum is " << sum;
	cout << "Average is " << float(sum/n);
	return 0;
}
