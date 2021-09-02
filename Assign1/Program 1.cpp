/***************************************************************
CSCI 240         Program 1     Fall 2018

Programmer: Jeff Byerly

Section: 1 

Date Due: 9/7/2018

Purpose: This program calculates the number of singles and total
         number of bases for a baseball player.
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
	{
		int numOfSingles, numOfDoubles, numOfTriples, numOfHomeRuns, numOfHits, totalBases;
		cout << "Enter the number of hits: ";
		cin >> numOfHits;
		cout << endl << "Enter the number of doubles: ";
		cin >> numOfDoubles;
		cout << endl << "Enter the number of triples: ";
		cin >> numOfTriples;
		cout << endl << "Enter the number of home runs: ";
		cin >> numOfHomeRuns;
		
		numOfSingles = numOfHits - numOfDoubles - numOfTriples - numOfHomeRuns;
		totalBases = numOfSingles + (numOfDoubles * 2) + (numOfTriples * 3) + (numOfHomeRuns * 4);
	
		cout << endl << endl
			 << "Singles: " << numOfSingles << "  Doubles: " << numOfDoubles << "  Triples: " << numOfTriples << "  Home Runs: " << numOfHomeRuns << endl << endl
			 << "Total Bases: " << totalBases;
		
		return 0;
		
	}
