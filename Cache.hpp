#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Cache
{
private:
	string value;
	bool checkForIdenticalText(const string& text)
	{
		ifstream readValue("Value.txt");
		while (readValue.peek() != EOF)
		{
			getline(readValue, value, '\n');
			if (text == value)
			{
				return 1;
			}
		}
		readValue.close();
		ifstream readCode("Code.txt");
		while (readCode.peek() != EOF)
		{
			getline(readCode, value, '\n');
			if (text == value)
			{
				return 1;
			}
		}
		readCode.close();
		return 0;
	}

protected:
	void addNewText(const string& value, const string& code)
	{
		if (!(checkForIdenticalText(value)))
		{
			ofstream writeValue("Value.txt", /*fstream::ate |*/ fstream::app);
			writeValue << value;
			writeValue << endl;
			writeValue.close();
			ofstream writeCode("Code.txt", /*fstream::ate |*/ fstream::app);
			writeCode << code;
			writeCode << endl;
			writeCode.close();
		}
	}
};

