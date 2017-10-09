#include <iostream>
#include <string>
#include "config.h"
#include "metadata.h"
#include "MemoryFunction.h"


//Written by Micheal Leverington
#include "SimpleTimer.h"

using namespace std;




class timerClass
{
	public:
		SimpleTimer timer ;
		unsigned int delay;

		string getTime() 
			{
				timer.getCurrentTime(totalTime) ;
				return totalTime ;
			}


	private:
		char totalTime[50] ;

} ;

class Simulation 
{
	public:

		//CONSTRUCTOR AND DESTRUCTOR
		Simulation() ;
		~Simulation() ;


		//READFILE READS IN CONFIG FILE PASSED VIA USER
		//THROUGH THE SECOND ARGUMENT
		void readFile( string ) ;


		//READ METADATA USED TO READ ALL INFORMATION 
		//IN THE META DATA FILE PROVED BY THE USER / CONFIG FILE
		void readMetaData ( string ) ;

		//USED TO CALCULATE TIMES
		//MULTIPLY READ IN METADATA BY CONFIG DATA
		int calculate( char, string, int ) ;


		//REQURED TO PRINT ANY DATA TO A FILE
		//ALSO USED TO DISPLAY OUT OF QUEUE TO PREVENT 
		void toFile(bool, bool) ;


		//THREAD CREATER
		//USED TO PAUSE / WAIT FOR I/O TO FINISH
		void threadSim(int);	

		//TWO DATATYPES, ONE FOR CONFIG WHERE ALL READ IN 
		//CONFIG DATA IS STORED
		//ONE FOR METADATA WHERE ALL READ IN METADATA IS STORED
		Config configFile ;
		MetaData meta ;
		timerClass simulationTimer ;

		
} ;