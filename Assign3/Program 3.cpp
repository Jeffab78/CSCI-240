/***************************************************************
CSCI 240         Program 3     Fall 2018

Programmer: Jeff Byerly

Section: 1 

Date Due: 9/21/2018

Purpose: This program calculates a customers phone bill based off the plan they selected and how many minutes they used.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
	{
		// declare variables
		char package;
		int minutes;
		double totalCost;
		
		// get input from user for variables
		cout << "Which package do you have (A, B, or C)? ";
		cin >> package;
		cout << "\nHow many minutes did you use? ";
		cin >> minutes;
		
		// Have customer enter a valid number of minutes if they did not
		if (minutes<=0)
			{
			cout << "Please enter a valid number of minutes: ";
			cin >> minutes;
		}
		
		// calculate the customers bill based off input
		
		if (package == 'A')
			{
			if (minutes<=300)
				totalCost=29.99;
			else
				totalCost=(minutes-300)*.32+29.99;
			}
		else if (package == 'B')
			{
			if (minutes <=750)
				totalCost=49.99;
			else
				totalCost = (minutes-750)*.28+49.99;
			}
		else 
			totalCost=59.99;
			
		// prints out the bill for the customer
			
		cout << "The bill is $" << fixed << setprecision(2) << totalCost;
		
		
		
	}
