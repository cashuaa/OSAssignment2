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
		void displayAll() ;
		void displayConfig( ) ;
		void displayMeta(  ) ;
		void calculate() ;


		Config configFile ;
		MetaData meta ;
} ;