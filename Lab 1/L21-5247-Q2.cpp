#include<iostream>
using namespace std;
int main (int argc, char** argv)
{
cout << "Welcome to BSCS operatig systems lab " << endl;
for (int i = 1; i < argc; ++i)
	cout << argv[i] << " ";
return 0;
}
