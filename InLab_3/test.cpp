#include <iostream>

#include "parser.h"

using std::cout;
using std::cin;

int main( void )
{
	char Expression[100];
	bool Run = true;

	while( Run )
	{
		cout<<"Enter an expression: ";
		cin>>Expression;
		cin.ignore();

		if( Expression != "exit" )
		{
			try
			{
				cout<<Expression<<" = "
					<<eval( Expression )<<"\n";
			}
			catch( std::exception &Error )
			{
				cout<<Error.what()<<"\n"; cout.flush();				
				return 1;
			}
		}
		else
		{
			Run = false;
		}
	}

	return 0;
}
