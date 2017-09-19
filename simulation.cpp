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
		configFile.readIn( config ) ;
		readMetaData( configFile.getFilePath() ) ;
	}
	void Simulation::readMetaData ( string metaLocation )
	{
		meta.readIn( metaLocation.c_str() ) ;
	}


	void Simulation::displayAll()
	{
		displayConfig() ;

		//calculate() ;

		displayMeta() ;

	}

	void Simulation::displayConfig(  )
	{
		cout << "Configuration File Data" << endl;
		cout << "Processor = " << configFile.getProcessor()  << " ms/cycle" << endl;
		cout << "Monitor = " << configFile.getMonitor() << " ms/cycle" << endl ;
		cout << "Hard Drive = " << configFile.getHardDrive() << " ms/cycle" << endl ;
		cout << "Printer = " << configFile.getPrinter() << " ms/cycle" << endl ;
		cout << "Keyboard = " << configFile.getKeyboard() << " ms/cycle" << endl ;
		cout << "Memory = " << configFile.getMemory() << " ms/cycle" << endl ;
		cout << "Mouse = " << configFile.getMouse() << " ms/cycle" << endl ;
		cout << "Speaker = " << configFile.getSpeaker() << " ms/cycle" << endl ;
		cout << "Logged to: " << configFile.getLogging() << endl << endl;
	}

	void Simulation::displayMeta(  )
	{
		for(int i = 0; i < 2; i++)
		{
			meta.metaQueue.pop() ;
		}

		while(!meta.metaQueue.empty() && meta.metaQueue.front().cycles != 0)
		{
			cout << meta.metaQueue.front().code << "(" << meta.metaQueue.front().descriptor << ")"
			<< meta.metaQueue.front().cycles << " - " ;

			calculate() ;

			cout << meta.metaQueue.front().cycles << " ms" << endl;
			meta.metaQueue.pop() ;
		}

		/*
		cout << "Configuration File Data" << endl;
		cout << "Processor = " << configFile.getProcessor()  << " ms/cycle" << endl;
		cout << "Monitor = " << configFile.getMonitor() << " ms/cycle" << endl ;
		cout << "Hard Drive = " << configFile.getHardDrive() << " ms/cycle" << endl ;
		cout << "Printer = " << configFile.getPrinter() << " ms/cycle" << endl ;
		cout << "Keyboard = " << configFile.getKeyboard() << " ms/cycle" << endl ;
		cout << "Memory = " << configFile.getMemory() << " ms/cycle" << endl ;
		cout << "Mouse = " << configFile.getMouse() << " ms/cycle" << endl ;
		cout << "Speaker = " << configFile.getSpeaker() << " ms/cycle" << endl ;
		cout << "Logged to: " << configFile.getLogging() << endl;
		*/
	}


	void Simulation::calculate()
	{
		if(meta.metaQueue.front().descriptor == "run")
		{
			meta.metaQueue.front().cycles = (meta.metaQueue.front().cycles * configFile.getProcessor() ) ;
		}
		else if(meta.metaQueue.front().descriptor == "allocate" || meta.metaQueue.front().descriptor == "block")
		{
			meta.metaQueue.front().cycles = (meta.metaQueue.front().cycles * configFile.getMemory () ) ;
		}
		else if(meta.metaQueue.front().descriptor == "monitor")
		{
			meta.metaQueue.front().cycles = (meta.metaQueue.front().cycles * configFile.getMonitor() ) ;
		}
		else if(meta.metaQueue.front().descriptor == "hard drive")
		{
			meta.metaQueue.front().cycles = (meta.metaQueue.front().cycles * configFile.getHardDrive() ) ;
		}
		else if(meta.metaQueue.front().descriptor == "mouse")
		{
			meta.metaQueue.front().cycles = (meta.metaQueue.front().cycles * configFile.getMouse() ) ;
		}
		else if(meta.metaQueue.front().descriptor == "printer")
		{
			meta.metaQueue.front().cycles = (meta.metaQueue.front().cycles * configFile.getPrinter() ) ;
		}
		else if(meta.metaQueue.front().descriptor == "speaker")
		{
			meta.metaQueue.front().cycles = (meta.metaQueue.front().cycles * configFile.getSpeaker() ) ;
		}
		else if(meta.metaQueue.front().descriptor == "keyboard")
		{
			meta.metaQueue.front().cycles = (meta.metaQueue.front().cycles * configFile.getKeyboard() ) ;
		}


	}