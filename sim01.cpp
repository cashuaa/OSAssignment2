#include <iostream>
#include <fstream>
#include "simulation.h"

using namespace std;


int main( int argc, char * argv[] )
{

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
//		operatingSystem.displayAll() ;
		operatingSystem.toFile() ;
	}
	else
	{
		operatingSystem.displayAll() ;
	}

	return 0 ; 
}