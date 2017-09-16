#include <iostream>
#include <string>
#include "simulation.h"

using namespace std; 


	Simulation::Simulation() 
	{

	}

	Simulation::~Simulation() 
	{

	}

	void Simulation::readFile( string config ) 
	{
		configFile.readIn(config) ;
	}