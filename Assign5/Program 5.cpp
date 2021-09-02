/***************************************************************
CSCI 240         Program 5     Fall 2018

Programmer: Jeff Byerly

Section: 1 

Date Due: 10/12/2018

Purpose: This program generates three sets of random numers and counts how many fall into a particular range
***************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
//declare constants here
const int LOWERBD=50;
const int UPPERBD=100;
const int NUMBERSGEN=10;
int main()
{
	//seeds random num generator and declares varialbes
	srand(1);
	int num,i,hundredCt=0,ninetyCt=0,eightyCt=0,seventyCt=0,sixtyCt=0,fiftyCt=0;
	int hundreds,nineties,eighties,seventies,sixties,fifties,tally=0;
	
	//Begin set 1 here
	cout << "Set 1" << endl;
	for(i=0;i<NUMBERSGEN;i++)
	{
	
		num=LOWERBD+(rand() % (UPPERBD-LOWERBD+1));    //generates random numbers and then increases the count based off of which category it lands
		cout << num << "  ";
		if (num>=50 and num<60)
			fiftyCt++;
		else if (num>=60 and num<70)
			sixtyCt++;
		else if (num>=70 and num<80)
			seventyCt++;
		else if (num>=80 and num<90)
			eightyCt++;
		else if (num>=90 and num<100)
			ninetyCt++;
		else
			hundredCt++;
		
	}
	// displays the total for each bracket
	cout << endl << "100 count: " <<hundredCt << "  90s count: " << ninetyCt << "  80s count: " << eightyCt << "  70s count: " << seventyCt << "  60s count: " << sixtyCt << "  50s count: " << fiftyCt;
	hundreds=hundredCt,nineties=ninetyCt,eighties=eightyCt,seventies=seventyCt,sixties=sixtyCt,fifties=fiftyCt; //begins counting total number of each bracket
	
	//Begin set 2 here
	cout << endl << endl << "Set 2" << endl;
	i=0,hundredCt=0,ninetyCt=0,eightyCt=0,seventyCt=0,sixtyCt=0,fiftyCt=0;
	while (i<NUMBERSGEN)
	{
		num=LOWERBD+(rand() % (UPPERBD-LOWERBD+1));        //generates random numbers and then increases the count based off of which category it lands
		cout << num << "  ";
		if (num>=50 and num<60)
			fiftyCt++;
		else if (num>=60 and num<70)
			sixtyCt++;
		else if (num>=70 and num<80)
			seventyCt++;
		else if (num>=80 and num<90)
			eightyCt++;
		else if (num>=90 and num<100)
			ninetyCt++;
		else
			hundredCt++;
		i++;
		
	}
	//displays the total for each bracket
	cout << endl << "100 count: " <<hundredCt << "  90s count: " << ninetyCt << "  80s count: " << eightyCt << "  70s count: " << seventyCt << "  60s count: " << sixtyCt << "  50s count: " << fiftyCt;
	hundreds+=hundredCt,nineties+=ninetyCt,eighties+=eightyCt,seventies+=seventyCt,sixties+=sixtyCt,fifties+=fiftyCt; //adds total number from each bracket to total number from Set 1
	
	//Begin set 3 three
	cout << endl << endl << "Set 3" << endl;
	i=0,hundredCt=0,ninetyCt=0,eightyCt=0,seventyCt=0,sixtyCt=0,fiftyCt=0;
	do
	{
		num=LOWERBD+(rand() % (UPPERBD-LOWERBD+1));    //generates random numbers and then increases the count based off of which category it lands
		cout << num << "  ";
		if (num>=50 and num<60)
			fiftyCt++;
		else if (num>=60 and num<70)
			sixtyCt++;
		else if (num>=70 and num<80)
			seventyCt++;
		else if (num>=80 and num<90)
			eightyCt++;
		else if (num>=90 and num<100)
			ninetyCt++;
		else
			hundredCt++;
		i++;
	}
	while (i<NUMBERSGEN);
	//displays the total for each bracket
	cout << endl << "100 count: " <<hundredCt << "  90s count: " << ninetyCt << "  80s count: " << eightyCt << "  70s count: " << seventyCt << "  60s count: " << sixtyCt << "  50s count: " << fiftyCt;
	hundreds+=hundredCt,nineties+=ninetyCt,eighties+=eightyCt,seventies+=seventyCt,sixties+=sixtyCt,fifties+=fiftyCt; //adds totals from this set to the previous set
	
	//extra credit to display overall counts with table aligned
	cout << endl << endl << "Overall Counts" << endl << left << setw(3)<< "100 count:   " <<left << setw(3)<< hundreds << "  ";
	for (tally=0;tally<hundreds;tally++)
		{
		cout << "*";
		}
	cout << endl << "90s count:   " <<left << setw(3)<< nineties << "  ";
	for (tally=0;tally<nineties;tally++)
		{
		cout << "*";
		}
	cout << endl << "80s count:   " << left << setw(3)<<eighties << "  ";
	for (tally=0;tally<eighties;tally++)
		{
		cout << "*";
		}
	cout << endl << "70s count:   " <<left <<setw(3)<< seventies << "  ";
	for (tally=0;tally<seventies;tally++)
		{
		cout << "*";
		}
	cout << endl <<"60s count:   " <<left << setw(3)<< sixties << "  ";
	for (tally=0;tally<sixties;tally++)
		{
		cout << "*";
		}
	cout << endl << "50s count:   " <<left << setw(3)<< fifties << "  ";
	for (tally=0;tally<fifties;tally++)
		{
		cout << "*";
		}
	return 0;
	
}
