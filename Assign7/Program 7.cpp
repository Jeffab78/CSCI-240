/***************************************************************
CSCI 240         Program 7     Fall 2018

Programmer: Jeff Byerly

Section: 1 

Date Due: 11/2/2018

Purpose: This program reads a text file of Stanley Cup winners and builds an array of the names. The user then types in the team they want to search for and it displays how many times that team has won and in what year.
***************************************************************/
#include <iostream>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;
const int MAXTEAMS=100;
const int MAXPERLINE=6;

//prototype functions
int buildArray(string[]);
int numWins(string[],int,string);
void displayYears(string[],int,string);

int main()
{
//declare variables
string team_array[MAXTEAMS];
int numTeams,timesWon;
string teamName;

//Call buildArray function and store the number of teams
numTeams=buildArray(team_array);

cout << "There are " << numTeams << " entries in the input file." << endl << endl << "Team? ";

//Asks the user for a team to search for
getline(cin,teamName);

//searches the array and finds how many times the team has won
timesWon=numWins(team_array,numTeams,teamName);

//outputs the results and displays not awarded correctly
if (teamName=="Not Awarded")
	cout << "\n\nThe Stanley Cup was not awarded " << timesWon << " time(s)." << endl << endl;
else
	cout << "\n\nThe " << teamName << " have won the Stanley Cup "<< timesWon << " time(s)." << endl << endl;
	
//Extra Credit function to display the years the team won.
displayYears(team_array,numTeams,teamName);

}


/************************Functions*******************************/

/*
Function: buildArray
Use: reads the text file and builds the array by storing the team names into the string
Arguments: takes in a string array
Returns: returns an integer of how many teams were stored into the array

*/
int buildArray(string team_array[])
{
ifstream inputfile;
inputfile.open("stanley_cup.txt");
if (inputfile.fail())
	{
	cout << "file did not open";
	exit(-1);
	}
string teamFromFile;
int sub=0;

getline(inputfile,teamFromFile);
while (inputfile)
{
	
	team_array[sub]=teamFromFile;
	getline(inputfile,teamFromFile);
	sub++;

}

inputfile.close();
	return sub;
}

/*
Function: numWins
Use: Searches the array and tallies up the number of times a team has won.
Arguments: takes in a string array, an integer of how many teams to search, and a string of the team to search for.
Returns: Returns an integer of how many times the searched for team has won.
*/
int numWins(string team_array[],int numTeams, string search_team)
{
	int timesWon=0;
	for (int i=0;i<numTeams;i++)
		{
			if (team_array[i]==search_team)
				{
					timesWon++;
				}
		}
	return timesWon;
}

/*
Function: displayYears
Use: Searches for when the team won the cup based off the first year being 1927 and displays the years.
Arguments: takes in a string array, an integer of how many teams to search, and a string of the team to search for.
Returns: Doesn't return anything since it is only used to display output.
*/
void displayYears(string team_array[],int numTeams,string search_team)
{
	int year=1927,numPerLine=0;
	for (int i=0;i<numTeams;i++)
	{
		if (team_array[i]==search_team)
			{
				cout << year;
				numPerLine++;
			
			if (numPerLine<MAXPERLINE)
			cout << " ";
			else
				{
				cout << "\n";
				numPerLine=0;
				}
			}
		year++;
	}
}

