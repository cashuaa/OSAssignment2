#include <iostream>
#include <string>
#include <queue>

using namespace std ;



/*
S - OPERATING SYSTEM, USED WITH START AND END
A - PROGRAM APPLICATION, USED WITH START AND END
P - PROCESS USED WITH RUN
I - USED WITH INPUT OPERATION DESCRIPTORS SUCH AS HARD DRIVE, KEYOBARD, MOUSE
O - USED WITH OUTPUT OPERATION DESCRIPTORS SUCH AS HARD DRIVE, MONITOR, SPEAKER
M - MEMORY USED WITH BLOCK, ALLOCATE
*/

struct meta
{
	char code;
	string descriptor;
	int cycles;
};


	class MetaData
	{

	public:
		MetaData() ;
		~MetaData() ;

		queue<meta> metaQueue;

/*
		void operatingSystem(int) ;
		void programApp(int) ;
		void runProcess(int) ;
		void inputOperation(int) ;
		void outputOperation(int) ;
		void memoryAlloc(int) ;
*/

		void checkForNewLine( string& ) ;
		void readIn(string) ;


	private:

//		int dataMember ;
//		int dataBuffer ;


	} ;