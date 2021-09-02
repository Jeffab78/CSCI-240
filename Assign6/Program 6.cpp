/***************************************************************
CSCI 240         Program 6     Fall 2018

Programmer: Jeff Byerly

Section: 1 

Date Due: 10/26/2018

Purpose: This program reads an encoded message from a text file and decodes it.
***************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
//declare prototypes of functions
bool isspecial(char);
bool isspace(char);
char changeLowerToUpper(char);
char changeUpperToLower(char);
char changePunctToDigit(char);
char changeDigitToPunct(char);
char changeSpecialToSpace(char);
//variables for EC
int chars=0,alphs=0,digits=0,puncts=0,specials=0;

int main()
{
// Here is where the file is opened and an error message is displayed if it does not.
	ifstream inputfile;
inputfile.open("encoded_quotes.txt");
if (inputfile.fail())
	{
	cout << "file did not open";
	exit(-1);
	}
char charFromFile;
//Here the first character from the file is stored in the variable.
inputfile >> charFromFile;
while (inputfile) 
{
	//Here the program checks to see what the varible is holding and uses the correct decoding function.
	if (islower(charFromFile))
		{
			charFromFile=changeLowerToUpper(charFromFile);
		}
	else if (isupper(charFromFile))
		{
			charFromFile=changeUpperToLower(charFromFile);
		}
	else if (ispunct(charFromFile))
		{
			charFromFile=changePunctToDigit(charFromFile);
		}
	else if (isdigit(charFromFile))
		{
			charFromFile=changeDigitToPunct(charFromFile);
		}
	else if (isspecial(charFromFile))
		{
			charFromFile=changeSpecialToSpace(charFromFile);
		}
//This is the EC that tallies up the total number of each character type.
chars++;
if (isalpha(charFromFile))
	alphs++;
else if (isdigit(charFromFile))
	digits++;
else if (ispunct(charFromFile))
	puncts++;
else if (isspace(charFromFile))
	specials++;

//These next two lines output the decoded character and then store the next encoded character into the variable to repeat the loop.
cout <<charFromFile;
inputfile>>charFromFile;

}
inputfile.close();
//Here is the EC formatted to display the total number of each character type.
cout << endl << endl << endl << "The file contains " << chars << " characters." << endl;
cout <<left << setw(15)<< "Alphabetic: " << alphs <<
	endl << left << setw(15) << "Digits: " << digits <<
	endl << left << setw(15) << "Punctuation: " << puncts <<
	endl << left << setw(15) << "Whitespace: " << specials;
//This is for EC part 2. I love this movie!
cout << endl<< endl<<"The message is from the classic movie A Christmas Story!";
}


//*********************Everything below here are the functions***********************************

/*
Function: changeLowerToUpper
Use: changes any lower case letter to upper case
Arguments: takes in a character variable
Returns: It returns the upper case version of the input

*/
char changeLowerToUpper(char c)
{
	if (c!='z')
		c=c-31;
	else
		c=c-57;
	return c;
}
/*
Function: changeUpperToLower
Use: changes an upper case letter to lower case
Arguments: takes in a character variable
Returns: It returns the lower case version of the input
*/
char changeUpperToLower(char c)
	{
		if (c!='A')
			c=c+31;
		else
			c=c+57;
		return c;
	}
/*
Function: changePunctToDigit
Use: changes a punctuation symbol to a number
Arguments: takes in a character variable
Returns: returns the decoded number version of the punctuation
*/
char changePunctToDigit(char c)
	{
		switch(c)
		{
			case ')':
				c=48;
				break;
			case '!':
				c=49;
				break;
			case '@':
				c=50;
				break;
			case '#':
				c=51;
				break;
			case '$':
				c=52;
				break;
			case '%':
				c=53;
				break;
			case '^':
				c=54;
				break;
			case '&':
				c=55;
				break;
			case '*':
				c=56;
				break;
			case '(':
				c=57;
				break;
		}
		return c;
	}
/*
Function:changeDigitToPunct
Use: changes a number to its associated punctuation symbol
Arguments: takes in a chracter variable
Returns: It returns the decoded punctuation instead of the number
*/
char changeDigitToPunct(char c)
	{
		switch(c)
		{
			case '1':
				c='.';
				break;
			case '2':
				c=')';
				break;
			case '3':
				c='(';
				break;
			case '4':
				c=96;
				break;
			case '5':
				c='?';
				break;
			case '6':
				c=';';
				break;
			case '7':
				c='!';
				break;
			case '8':
				c='"';
				break;
			case '9':
				c=',';
				break;
			case '0':
				c='-';
				break;
		}
		return c;
	}
/*
Function: changeSpecialToSpace
Use: changes the two special values to either spaces or new lines
Arguments: takes in a character variable
Returns: It returns either a space or new line character depending on what the special character is
*/
char changeSpecialToSpace(char c)
	{
		if (c==20)
			c=10;
		else if (c=22)
			c=32;
		return c;	
	}
/*
Function: isspecial
Use: determines if the character is one of the two special values
Arguments: takes in a character value
Returns: returns a boolean of whether or not it does match those specific values
*/
bool isspecial(char c)
	{
		if (c==20 or c==22)
			return true;
		else
			return false;
	}
/*
Function: isspace
Use: determines if the character is a space or new line for Extra credit
Arguments: takes in a character value
Returns: returns a boolean of whether or not the varaible is a space or new line 
*/
bool isspace(char c)
{
	if (c==10 or c==32)
		return true;
	else
		return false;
}

