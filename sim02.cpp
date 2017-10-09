#include <iostream>
#include <fstream>
#include "simulation.h"

using namespace std;

/*
	PCB INILTALIZATION
*/

struct PCB
{
	bool processState ;
	bool start ;
	bool ready ;
	bool running ;
	bool wait ;
	bool intExit ;
};


int main( int argc, char * argv[] )
{
	PCB buffer ;
	buffer.processState = true ;

	bool monitor = false ;
	bool file = false ;

	Simulation operatingSystem ;

	string fileName = "DEFAULT" ;

	if(argc < 2)
	{
		throw runtime_error ("Didn't specify configuration file") ;
	}
	else
	{
			fileName = argv[1] ;
	}

	operatingSystem.readFile(fileName) ;

	if(operatingSystem.configFile.getLogging() == "Log to Both" || operatingSystem.configFile.getLogging() == "Log to file" )
	{
		file = true ;
	}
	if(operatingSystem.configFile.getLogging() == "Log to Both" || operatingSystem.configFile.getLogging() == "Log to monitor" )
	{
		monitor = true ;
	}

	operatingSystem.toFile(monitor, file) ;
	

	return 0 ; 
}