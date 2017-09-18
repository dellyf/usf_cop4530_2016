#include <string>
#include <list>
#include <iostream>
#include "Tokenizer.h"

using namespace std;
int main()
{
	//list to hold extracted strings
	list<string> tokenList;
     //int i;
    string delimitier;
    string input;
	
	
	cout << "Enter an input string: ";
	getline(cin, input);
	cout << "Enter the delimitier string: ";
	getline(cin, delimitier);
    
    
	tokenizer(input, delimitier, tokenList);
	//printing strings in list
  
  cout << "Tokens: " << endl;
  
	list<string>::iterator i;
	for (i = tokenList.begin(); i != tokenList.end(); i++)
		cout << *i << endl;
		
	cin.get();
  cin.get();
	return 0;

}
