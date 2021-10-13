// BOSCH Academy entry assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Atbash.hpp"

int main()
{
	string command, txt;
	Atbash body;
	do
	{
		cout << "Command:" << endl;
		getline(cin, command, '\n');
		if ((command == "encode") || (command == "decode"))
		{
			cout << "Atbash." << command << ":";
			getline(cin, txt, '\n');
			body.encode(txt);
		}
		else if (command == "cypher")
		{
			body.cypher();
		}
	} while (command != "end");
	return 0;
}
