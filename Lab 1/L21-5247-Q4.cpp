#include<iostream>
#include<fstream>
using namespace std;

void removeNonAlphabets(char* inputfile, char* outputfile)
{
	ifstream fin;
	fin.open(inputfile);
	
	ofstream fout;
	fout.open(outputfile);

	char c;
	while(!fin.eof())
	{
		fin >> c;
		if (c > 47 && c < 58)
			fout << c << " ";
	}
	
	fout.close();
	fin.close();
}

int main (int n, char** args)
{
	removeNonAlphabets(args[1], args[2]);
	
	return 0;
}
