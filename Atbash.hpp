#pragma once
#include <string>
#include <iostream>
#include "Cache.hpp"
using namespace std;

class Atbash : private Cache
{
private:
	unsigned int wordCount = 0;
	unsigned int stringLength;
	char letter;
	string codedText;
	char atbashLetter(char startLetter, char endLetter, char currentLetter)
	{
		char atbLetter;
		atbLetter = (char)(startLetter + (endLetter - currentLetter));
		return atbLetter;
	}
	string atbashFunction(const string& text)
	{
		codedText.clear();
		stringLength = size(text);
		for (size_t i = 0; i < stringLength; ++i)
		{
			letter = text[i];
			if (letter == NULL)
				break;
			else
			{
				if ((letter < 'a' || letter > 'z') && (letter < 'A' || letter > 'Z'))
					codedText += text[i];
				else
				{
					if (letter >= 'A' && letter <= 'Z')
						codedText += atbashLetter('A', 'Z', letter);
					else if (letter >= 'a' && letter <= 'z')
						codedText += atbashLetter('a', 'z', letter);
				}
			}
		}
		cout << "->" << codedText << endl;
		return codedText;
	}
public:
	void encode(const string& text)
	{
		atbashFunction(text);
		addNewText(text, codedText);
	}
	void decode(const string& text)
	{
		atbashFunction(text);
		addNewText(text, codedText);
	}
	void cypher()
	{
		string value, code;
		ifstream readValue("Value.txt", fstream::in);
		ifstream readCode("Code.txt", fstream::in);
		while ((readValue.peek() != EOF) || (readCode.peek() != EOF))
		{
			getline(readValue, value, '\n');
			cout << value << " > ";
			getline(readCode, code, '\n');
			cout << code << endl;
		}
		readValue.close();
		readCode.close();
	}
};

