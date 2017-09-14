#include <iostream>
#include <string>
#include "config.h"

using namespace std;

	

	Config::Config()
	{
		string version ;
		string filePath;
		string logging;

		processor = - 1 ;
		monitor = - 1 ;
		hardDrive = - 1 ;
		printer = - 1  ;
		keyboard = - 1 ;
		memory = - 1 ;
		mouse = - 1 ;
		speaker = - 1 ;
	}

	Config::~Config()
	{


	}

	string const Config::getVersion() 
	{
		return version ;
	}
	void Config::setVersion(const string newVersion) 
	{
		version = newVersion ;
	}

	string const Config::getFilePath() 
	{
		return filePath ;
	}
	void Config::setFilePath(const string newFilePath) 
	{
		filePath = newFilePath ;
	}
	
	string const Config::getLogging() 
	{
		return logging ;
	}
	void Config::setlogging(const string newLogging) 
	{
		logging = newLogging ;
	}


//PROCESSOR//
	int const Config::getProcessor ()
	{
		return processor ;
	}
	void Config::setProcessor (const int newProcessor) 
	{
		if (newProcessor <= 0)
			throw runtime_error("Invalid processor time.") ;
		else
			processor = newProcessor ;
	}

//MONITOR//	
	int const Config::getMonitor () 
	{
		return monitor ;
	}
	void Config::setMonitor (const int newMonitor) 
	{
		if (newMonitor <= 0)
			throw runtime_error("Invalid monitor time.") ;
		else
			monitor = newMonitor ;
	}

//HARD DRIVE//
	int const Config::getHardDrive () 
	{
		return hardDrive ;
	}
	void Config::setHardDrive (const int newHardDrive) 
	{
		if (newHardDrive <= 0)
			throw runtime_error("Invalid hard drive time.") ;
		else
			hardDrive = newHardDrive ;
	}

//PRINTER//
	int const Config::getPrinter () 
	{
		return printer ;
	}
	void Config::setPrinter (const int newPrinter) 
	{
		if ( newPrinter <= 0 )
			throw runtime_error("Invalid printer time") ;
		else
			printer = newPrinter ;
	}

//KEYBOARD//
	int const Config::getKeyboard() 
	{
		return keyboard ;
	}
	void Config::setKeyboard(const int newKeyboard) 
	{
		if ( newKeyboard <= 0 )
			throw runtime_error("Invalid keyboard time") ;
		else		
			keyboard = newKeyboard ;
	}

//MEMORY//
	int const Config::getMemory() 
	{
		return memory ;
	}
	void Config::setMemory(const int newMemory) 
	{
		if ( newMemory <= 0 )
			throw runtime_error("Invalid memory time") ;
		else		
			memory = newMemory ;
	}

//MOUSE//
	int const Config::getMouse() 
	{
		return mouse ;
	}
	void Config::setMouse(const int newMouse) 
	{
		if ( newMouse <= 0 )
			throw runtime_error("Invalid mouse time") ;
		else
			mouse = newMouse ;
	}

//SPEAKER//
	int const Config::getSpeaker() 
	{
		return speaker ;
	}
	void Config::setSpeaker(const int newSpeaker) 
	{
		if ( newSpeaker <= 0 )
			throw runtime_error("Invalid speaker time") ;
		else
			speaker = newSpeaker ;
	}
