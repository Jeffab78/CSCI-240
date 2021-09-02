/***********************************************************************
CSCI 240         Program 9     Fall 2018

Programmer: Jeff Byerly

Section: 1

Date Due: 12/7/18

Purpose: This program takes in texts files of numbers and see if they fit the criteria for the Lo Shu Magic Square
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>


using namespace std;

//Place the class definition after this line
class LoShuMagicSquare
{
	public:
	LoShuMagicSquare();
	int nums[3][3];
	
	void printSquare();
	void fillSquare(const char[]);
	bool isMagic();
};


int main()
{
//Create a LoShuMagicSquare object that will be used to test the 4 puzzles
LoShuMagicSquare puzzle;


//Display the initial puzzle, which should be all 0s
cout << "Starting Puzzle values:" << endl << endl;

puzzle.printSquare();


//Puzzle 1 using loshu_puzzle1.txt. The object will be filled, displayed,
//and then tested to see if it is a valid solution

cout << endl << endl << "Puzzle 1:" << endl << endl;

puzzle.fillSquare( "loshu_puzzle1.txt");

puzzle.printSquare();

cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;


//Puzzle 2 using loshu_puzzle2.txt. The object will be filled, displayed,
//and then tested to see if it is a valid solution

cout << "Puzzle 2:" << endl << endl;

puzzle.fillSquare( "loshu_puzzle2.txt");

puzzle.printSquare();

cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;


//Puzzle 3 using loshu_puzzle3.txt. The object will be filled, displayed,
//and then tested to see if it is a valid solution

cout << "Puzzle 3:" << endl << endl;

puzzle.fillSquare( "loshu_puzzle3.txt");

puzzle.printSquare();

cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;


//Puzzle 4 using loshu_puzzle4.txt. The object will be filled, displayed,
//and then tested to see if it is a valid solution

cout << "Puzzle 4:" << endl << endl;

puzzle.fillSquare( "loshu_puzzle4.txt");

puzzle.printSquare();

cout << endl << "Is it magic? " << ( puzzle.isMagic() ? "Yes": "No" ) << endl << endl << endl;


return 0;
}

//Code the methods below this line
/****************************Constructor and Functions***************************************************/
//constructor to set to 0
LoShuMagicSquare::LoShuMagicSquare()
{
	for (int rowSub=0;rowSub<3;rowSub++)
{
	for (int colSub=0;colSub<3;colSub++)
	{
		 nums[rowSub][colSub]=0;
	}
	
}
}

/*
Method: printSquare
Use: Displays the two dismensional array
Arguments: takes in no arguments
Returns: returns nothing.
*/
void LoShuMagicSquare::printSquare()
{
	for (int rowSub=0;rowSub<3;rowSub++)
{
	for (int colSub=0;colSub<3;colSub++)
	{
		 cout << nums[rowSub][colSub] << " ";
	}
	cout << endl;
}
}
/*
Method: fillSquare
Use: This opens the file that is passed in as the argument and stores the values into the array
Arguments: takes in an array of constant characters from the file
Returns: returns nothing.
*/
void LoShuMagicSquare::fillSquare(const char filename[])
{
	ifstream inputfile;
	inputfile.open(filename);
	if (inputfile.fail())
	{
	cout << "file did not open";
	exit(-1);
	}
	char numFromFile;
	inputfile >> numFromFile;
	while(inputfile)
	{
				for (int rowSub=0;rowSub<3;rowSub++)
	{
	for (int colSub=0;colSub<3;colSub++)
	{
		 nums[rowSub][colSub]=numFromFile-48;
		 inputfile >> numFromFile;
	}
	
	} 
}	
}
/*
Method: isMagic
Use: This determines if the two-dimensional array contains a valid Lo Shu Magic Square
Arguments: takes in no arguments
Returns: returns a boolean whether or not it is a magic square
*/
bool LoShuMagicSquare::isMagic()
{
	//first part checks to make sure there are no duplicate numbers being used.
for (int testRow=0;testRow<3;testRow++)
{
	for (int testCol=0;testCol<3;testCol++)
	{
	
		for (int rowSub=testRow+1;rowSub<3;rowSub++)
		{
			for (int colSub=testCol;colSub<3;colSub++)
		{
			if (nums[testRow][testCol]==nums[rowSub][colSub])
				return false;
		}
	
	}}}
	//this part adds up all the rows and columns.
int sumRow1,sumRow2,sumRow3,sumCol1,sumCol2,sumCol3,sumDiag1,sumDiag2;
	sumRow1=(nums[0][0]+nums[0][1]+nums[0][2]);
	sumRow2=(nums[1][0]+nums[1][1]+nums[1][2]);
	sumRow3=(nums[2][0]+nums[2][1]+nums[2][2]);
	sumCol1=(nums[0][0]+nums[1][0]+nums[2][0]);
	sumCol2=(nums[0][1]+nums[1][1]+nums[2][1]);
	sumCol3=(nums[0][2]+nums[1][2]+nums[2][2]);
	sumDiag1=(nums[0][0]+nums[1][1]+nums[2][2]);
	sumDiag2=(nums[0][2]+nums[1][1]+nums[2][0]);

//returns true or false whether or not all columns, rows, and diag sections are equal.
if (sumRow1==sumRow2&&sumRow3&&sumCol1&&sumCol2&&sumCol3&&sumDiag1&&sumDiag2)
	return true;
else
	return false;

}

