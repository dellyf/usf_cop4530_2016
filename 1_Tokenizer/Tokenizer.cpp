#include <iostream>
#include <string.h>
#include <list>
#include "Tokenizer.h"

//tokenizes the given input string based on given delimitier

void tokenizer(const string input, const string delimitier, list<string> &tokenList)
{
	 string::size_type cur = 0, prev = 0;
	 string phrase;

	//extracts words from given input string and pushes them into string list

	while ((cur = input.find(delimitier, cur)) != string::npos)
	{
		phrase = input.substr(prev, cur - prev);
		tokenList.push_back(phrase);
		prev = cur++;
   	prev = prev + delimitier.length();
	}

  phrase = input.substr(prev, input.length());
	tokenList.push_back(phrase);
}
