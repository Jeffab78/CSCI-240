/***************************************************************
CSCI 240         Program 2     Fall 2018

Programmer: Jeff Byerly

Section: 1 

Date Due: 9/14/2018

Purpose: This program calculates the number of singles, total bases, and slugging percentage for a baseball player.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
	{
		int numOfSingles, numOfDoubles, numOfTriples, numOfHomeRuns, numOfHits, totalBases, atBats;
		double slugPercent;                                                                                  
	
	          //Begins prompting for input of variables
		cout << "Enter the number of hits: ";                   
		cin >> numOfHits;
		cout << endl << "Enter the number of doubles: ";
		cin >> numOfDoubles;
		cout << endl << "Enter the number of triples: ";
		cin >> numOfTriples;
		cout << endl << "Enter the number of home runs: ";
		cin >> numOfHomeRuns;
		cout << endl << "Enter the number of at bats: ";
		cin >> atBats;                                            
		
				//next three lines are the calculations
		numOfSingles = numOfHits - numOfDoubles - numOfTriples - numOfHomeRuns;                         
		totalBases = numOfSingles + (numOfDoubles * 2) + (numOfTriples * 3) + (numOfHomeRuns * 4);
		slugPercent = ((double)totalBases / atBats);         //typecasts to consider totalBases a double for this calculation
	
			//This cout displays the results based off the inputs and calculations made
		cout << endl << endl                   
			 << "Singles: " << numOfSingles << "  Doubles: " << numOfDoubles << "  Triples: " << numOfTriples << "  Home Runs: " << numOfHomeRuns << endl << endl
			 << "Total Bases: " << totalBases << endl << endl
			 << "Slugging Percentage: " << fixed << setprecision(3) << slugPercent;         //sets the number of decimal place to 3
		
		return 0;
		
	}
