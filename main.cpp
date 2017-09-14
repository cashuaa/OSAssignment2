#include <iostream>
#include <fstream>

using namespace std;


/*
S - OPERATING SYSTEM, USED WITH START AND END
A - PROGRAM APPLICATION, USED WITH START AND END
P - PROCESS USED WITH RUN
I - USED WITH INPUT OPERATION DESCRIPTORS SUCH AS HARD DRIVE, KEYOBARD, MOUSE
O - USED WITH OUTPUT OPERATION DESCRIPTORS SUCH AS HARD DRIVE, MONITOR, SPEAKER
M - MEMORY USED WITH BLOCK, ALLOCATE
*/

struct items
{
	string name ;
	char designater ;
//	int time ;
	string time ;
} ;

/*
bool stringCompare (string stringOne, string stringTwo)
{
	if(stringOne != stringTwo)
	{
		return 0 ;
	}
	return 1 ;
}
*/

int main()
{
	int count = 0 ;
	int itemsIndex = 0 ;
	bool fileFound = false ;
	bool end = false ;
	string newString ;
	string fileName ; 
	items myItem[8] ;
	ifstream fin ;


cout << "input name of file: " << endl ;
cin >> fileName ;
cout << "opening " << fileName << endl;
fin.open(fileName.c_str()) ;



// itterate through until end of config_1
while(newString != "End")
{
	fin >> newString ;

// input filename into string fileName
	if(newString == "Path:" && fileFound == false )
	{
		cout << "\n filename: " << fileName << endl ;
		fileFound = true ;
		fin >> newString ;
		fileName = newString ;
	}

	if(newString == "Processor")
	{
		myItem[itemsIndex].name = newString ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		myItem[itemsIndex].time = newString ;
		itemsIndex++ ;
	}
	
	if(newString == "Monitor")
	{
		myItem[itemsIndex].name = newString ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		myItem[itemsIndex].time = newString ;
		itemsIndex++ ;
	}	
	
	if(newString == "Hard")
	{
		myItem[itemsIndex].name = newString ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		myItem[itemsIndex].time = newString ;
		itemsIndex++ ;
	}

	if(newString == "Printer")
	{
		myItem[itemsIndex].name = newString ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		myItem[itemsIndex].time = newString ;
		itemsIndex++ ;
	}	

	if(newString == "Keyboard")
	{
		myItem[itemsIndex].name = newString ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		myItem[itemsIndex].time = newString ;
		itemsIndex++ ;
	}

	if(newString == "Memory")
	{
		myItem[itemsIndex].name = newString ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		myItem[itemsIndex].time = newString ;
		itemsIndex++ ;
	}

	if(newString == "Mouse")
	{
		myItem[itemsIndex].name = newString ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		myItem[itemsIndex].time = newString ;
		itemsIndex++ ;
	}
	
	if(newString == "Speaker")
	{
		myItem[itemsIndex].name = newString ;

		while(newString != "(msec):")
		{
			fin >> newString ;
		}
		fin >> newString ;
		myItem[itemsIndex].time = newString ;
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

	fin.close() ;

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

	return 0 ; 
}