#include <iostream>
#include <string>
#include "config.h"
#include "metadata.h"

using namespace std;

class Simulation 
{
	public:
		Simulation() ;
		~Simulation() ;

		void readFile( string ) ;
		void readMetaData ( string ) ;


		Config configFile ;
		MetaData meta ;
} ;