#include <iostream>
#include <string>
#include <fstream>
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
		displayMeta() ;

	}


void Simulation::toFile()
{
	ofstream outString(configFile.getLoggingPath().c_str());

	displayConfig() ;

	 outString << "Configuration File Data" << endl
	 << "Processor = " << configFile.getProcessor()  << " ms/cycle" << endl
	 << "Monitor = " << configFile.getMonitor() << " ms/cycle" << endl
	 << "Hard Drive = " << configFile.getHardDrive() << " ms/cycle" << endl
	 << "Printer = " << configFile.getPrinter() << " ms/cycle" << endl
	 << "Keyboard = " << configFile.getKeyboard() << " ms/cycle" << endl
	 << "Memory = " << configFile.getMemory() << " ms/cycle" << endl
	 << "Mouse = " << configFile.getMouse() << " ms/cycle" << endl
	 << "Speaker = " << configFile.getSpeaker() << " ms/cycle" << endl
	 << "Logged to: " << configFile.getLogging() << endl << endl ;


	if (configFile.getLogging() == "Log to Monitor")
	{
		outString << "Logged to: monitor" << endl;
	}
	else if(configFile.getLogging() == "Log to File")
	{
		outString << "Logged to: " << configFile.getLoggingPath() << endl;
	}
	else if (configFile.getLogging() == "Log to Both")
	{
		outString << "Logged to: monitor and " << configFile.getLoggingPath() << endl;
	}
	else
	{
		outString << "Logged to: " << configFile.getLogging() << endl;
	}


	outString << endl << endl;
	cout << "Meta-Data Metrics" << endl;
	outString << "Meta-Data Metrics" << endl;
	for (int i = 0; i < 2; i ++)
	{
		meta.metaQueue.pop();
	}

	while(!meta.metaQueue.empty() && meta.metaQueue.front().cycles != 0)
	{
		cout << meta.metaQueue.front().code << '(' << meta.metaQueue.front().descriptor
		<< ')' << meta.metaQueue.front().cycles << " - ";
		calculate();

		cout << meta.metaQueue.front().cycles << endl;
		outString << meta.metaQueue.front().code << '(' << meta.metaQueue.front().descriptor
		<< ')' << meta.metaQueue.front().cycles << " - " << meta.metaQueue.front().cycles << endl;

		meta.metaQueue.pop();	
	}

	outString.close();
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

		cout << "Meta-Data Metrics" << endl;
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