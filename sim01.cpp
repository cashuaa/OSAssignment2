#include <iostream>
#include <fstream>
#include "simulation.h"

using namespace std;


/*
S - OPERATING SYSTEM, USED WITH START AND END
A - PROGRAM APPLICATION, USED WITH START AND END
P - PROCESS USED WITH RUN
I - USED WITH INPUT OPERATION DESCRIPTORS SUCH AS HARD DRIVE, KEYOBARD, MOUSE
O - USED WITH OUTPUT OPERATION DESCRIPTORS SUCH AS HARD DRIVE, MONITOR, SPEAKER
M - MEMORY USED WITH BLOCK, ALLOCATE
*/


int main( int argc, char * argv[] )
{

	ifstream fin ;
	string newString ;
	string fileName ;
	fin.open(argv[1]) ;
	cout << "opening " << argv[1] << endl;


/*
// itterate through until end of config_1
while(newString != "End")
{
	fin >> newString ;

// input filename into string fileName
	if(newString == "Path:" )
	{
		cout << "\n filename: " << fileName << endl ;
		fin >> newString ;
		fileName = newString ;
	}

	if(newString == "Processor")
	{
		setProcessor(newString) ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		itemsIndex++ ;
	}
	
	if(newString == "Monitor")
	{

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		itemsIndex++ ;
	}	
	
	if(newString == "Hard")
	{
		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		itemsIndex++ ;
	}

	if(newString == "Printer")
	{

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		itemsIndex++ ;
	}	

	if(newString == "Keyboard")
	{

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		itemsIndex++ ;
	}

	if(newString == "Memory")
	{

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		itemsIndex++ ;
	}

	if(newString == "Mouse")
	{

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		itemsIndex++ ;
	}
	
	if(newString == "Speaker")
	{

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		itemsIndex++ ;
	}

	if(newString == "Both")
	{
		cout <<"\nlogging to both\n" << endl ;
	}
}

	for(int index = 0 ; index < 8 ; index++)
	{
		cout << myItem[index].name << myItem[index].time << endl;
	}


	fin.open(fileName.c_str()) ;

	newString = "clear" ;
	while(newString != "Code" && end != true)
	{

		if(newString == "End")
		{
			end = true ;
		}
		cout << endl;

		fin >> newString ;
		cout << newString ;
	
	}
	cout << "\n" ;
*/
	fin.close() ;
	return 0 ; 
}