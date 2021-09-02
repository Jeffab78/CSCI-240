/***************************************************************
CSCI 240         Program 4     Fall 2018

Programmer: Jeff Byerly

Section: 1 

Date Due: 9/28/2018

Purpose: This program randomly generates numbers as if a player was to be rolling dice in a game of Craps
***************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int craps2=2, craps3=3,craps12=12;
int main()
{
	
	//initializes the random number generator
	srand(22);
	int num1,num2,sum1,point;
	num1=1+(rand()%6);
	num2=1+(rand()%6);
	sum1=num1+num2;
	
	//display results of numbers generated 
	cout << "Player rolled: " << num1 << "+" << num2 << "=" << sum1;
	
	if (sum1==7 || sum1==11)
		cout << "\nYou won!";
	else if (sum1==craps2 || sum1==craps3 || sum1==craps12)
		cout << "\nCraps! You lost!";
	else
		{
			point=sum1;
			cout << "\nThe point is now " << point;	
		
		//now that the point is set, rolls until win or lose
		do
		{
			num1=1+(rand()%6);
			num2=1+(rand()%6);
			sum1=num1+num2;
			cout << "\nPlayer rolled: " << num1 << "+" << num2 << "=" << sum1;
		}
		while (sum1!=7 && sum1!=point);
	
		//after the loop, display whether the player won or lost depending on how the loop ended
		if (sum1==point)
		cout << "\nYou rolled your point! You won!";
		else if (sum1==7)
		cout << "\nYou seven'd out and lost!";

}
	
}
