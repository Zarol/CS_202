#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream read;
	ofstream write;

	read.open(argv[1]);
	write.open(argv[2]);

	if(read.is_open() == false)
		cout << "Cannot open: " << argv[1] << endl;
	if(write.is_open() == false)
		cout << "Cannot open: " << argv[2] << endl;

	char c;
	while(read.is_open())
	{
		while(write.is_open())
		{
			while(read.good())
			{
				c = read.get();
				write << c;
			}
			write.close();
		}
		read.close();
	}
}
