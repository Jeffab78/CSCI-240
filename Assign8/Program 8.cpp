/***************************************************************
CSCI 240         Program 8     Fall 2018

Programmer: Jeff Byerly

Section: 1 

Date Due: 11/20/2018

Purpose: This program uses the class Die to play a game of craps
***************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
//constants for craps game
const int craps2=2, craps3=3,craps12=12;

//Class definition for Die
class Die
{
	private:
		int sideUp;
		static const int NUM_SIDES;
	public:
		Die();
		void roll();
		int getValue();
		
};
const int Die::NUM_SIDES=6; //sets constant for the number of sides

int main()
{

	//initializes the random number generator
	srand(35);
	//create 2 Die objects and then variables
	Die die1, die2;
	int sum, firstDie, secondDie, point;
	
	for (char play='Y'; toupper(play)=='Y';) //keeps playing as long as the user enters a 'Y'
	{
		die1.roll();
		die2.roll();
		firstDie=die1.getValue();
		secondDie=die2.getValue();
		sum=firstDie+secondDie;
		
		cout << "Player rolled: " << firstDie << " + " << secondDie << " = " << sum;
		
		if (sum==7 || sum==11)
			cout << "\nYou won!";
		else if (sum==craps2 || sum==craps3 || sum==craps12)
			cout << "\nCraps! You lost!";
		else
		{
			point=sum;
			cout << "\n\nThe point is now " << point << endl;	
		
		//now that the point is set, rolls until win or lose
		do
		{
			die1.roll();
			die2.roll();
			firstDie=die1.getValue();
			secondDie=die2.getValue();
			sum=firstDie+secondDie;
		
			cout << "\nPlayer rolled: " << firstDie << " + " << secondDie << " = " << sum;
		}
		while (sum!=7 && sum!=point);
	
		//after the loop, display whether the player won or lost depending on how the loop ended
		if (sum==point)
		cout << "\n\nYou rolled your point! You won!";
		else if (sum==7)
		cout << "\n\nYou seven'd out and lost!";
	}
		
		cout << endl << endl << "Would you like to play again? (Y for yes) ";
		cin >> play;
		cout << endl;
	
}

return 0;
}

/*****************************constructor and methods****************************************************************/
/*
Method: roll()
Use: rolls a random number and stores it in the sideUp variable
Arguments: takes in no arguments
Returns: returns nothing.
*/
void Die::roll()
{
	 sideUp= rand()%NUM_SIDES+1;
	
}

/*
Method: getValue()
Use: gets the value stored in the current sideUp which shows what the dice rolled
Arguments: takes no argument
Returns: Returns an integer 
*/
int Die::getValue()
{
return sideUp;
}

// Die Constructor
Die::Die()
{
	roll();
}
