#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "config.h"

using namespace std;

	
//CONSTRUCTOR / DESTRUCTOR//

	Config::Config()
	{
		string version ;
		string filePath = "EMPTY";
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





//VERSION//

	string const Config::getVersion() 
	{
		return version ;
	}
	void Config::setVersion(const string newVersion) 
	{
		version = newVersion ;
		cout << "Version set to " << version << endl ;
	}







//FILE PATH//

	string const Config::getFilePath() 
	{
		if(filePath[0] == ' ')
		{
			filePath.erase(filePath.begin()) ;
		}
		return filePath ;
	}
	void Config::setFilePath(const string newFilePath) 
	{
		filePath = newFilePath ;
		cout << "File path set to " << filePath << endl ;
	}







//LOGGING//	

	string const Config::getLogging() 
	{
		return logging ;
	}
	string const Config::getLoggingPath()
	{
		return loggingPath ;
	}
	void Config::setlogging(const string newLogging) 
	{
		logging = newLogging ;
		cout << "Logging instructions: " << logging << endl ;
	}
	void Config::setLoggingPath(const string newLoggingPath)
	{
		loggingPath = newLoggingPath ;
		cout << "Logging path: " << loggingPath << endl;
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
		cout << "Processor: " << processor << endl ;
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
		cout << "Monitor: " << monitor << endl ;
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
		cout << "Harddrive: " << hardDrive << endl ;
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
		
		cout << "printer: " << printer << endl ;
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
		
		cout << "keyboard: " << keyboard << endl ;
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

		cout << "memory time: " << memory << endl;
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

		cout << "mouse time: " << mouse << endl;
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

		cout << "speaker time: " << speaker << endl;
	}


//NEWLINE//
	void Config::checkForNewLine( string& stringBuffer ) 
	{
		if(stringBuffer[0] == '\n')
		{
			stringBuffer.erase(stringBuffer.begin()) ;
		}
	}





//READ IN//

	void Config::readIn( string data ) 
	{
		string stringBuffer ;
		int intBuffer ;
		ifstream fin ;
		fin.open(data.c_str()) ;


		getline(fin, stringBuffer) ;
		cout << "Configuration File Data" << endl ;

		cout << stringBuffer << endl ;

		if (stringBuffer != "Start Simulator Configuration File")
			throw runtime_error ("Incorrect file path") ;
		else
		{
			getline(fin, stringBuffer, ':') ;
			if(stringBuffer == "Version/Phase" )
			{
				getline(fin, stringBuffer) ;
				setVersion(stringBuffer) ;
			}

			getline(fin, stringBuffer, ':') ;
			if(stringBuffer == "File Path" )
			{
				getline(fin, stringBuffer) ;				
				setFilePath(stringBuffer) ;
			}

			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;
			if(stringBuffer == "Processor cycle time (msec)" )
			{
				fin >> intBuffer ;
				setProcessor(intBuffer) ;
			}


			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;
			if(stringBuffer == "Monitor display time (msec)" )
			{
				fin >> intBuffer ;
				setMonitor(intBuffer) ;		
			}

			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;		
			if(stringBuffer == "Hard drive cycle time (msec)" )
			{
				fin >> intBuffer ;
				setHardDrive (intBuffer) ;
			}

			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;
			if(stringBuffer == "Printer cycle time (msec)" )
			{
				fin >> intBuffer ;
				setPrinter(intBuffer) ;
			}

			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;
			if(stringBuffer == "Keyboard cycle time (msec)" )
			{
				fin >> intBuffer ;
				setKeyboard(intBuffer) ;
			}

			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;
			if(stringBuffer == "Memory cycle time (msec)" )
			{
				fin >> intBuffer ;
				setMemory(intBuffer) ;
			}

			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;
			if(stringBuffer == "Mouse cycle time (msec)" )
			{
				fin >> intBuffer ;
				setMouse(intBuffer) ;
			}
	
			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;
			if(stringBuffer == "Speaker cycle time (msec)" )
			{
				fin >> intBuffer ;
				setSpeaker(intBuffer) ;
			}	

			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer )  ;
			if(stringBuffer == "Log" )
			{
				getline(fin, stringBuffer) ;
				setlogging(stringBuffer) ;
			}	
			
			getline(fin, stringBuffer, ':') ;
			checkForNewLine(stringBuffer) ;
			if(stringBuffer == "Log File Path" || stringBuffer == "Monitor" || stringBuffer == "Monitor only")
			{
				getline(fin, stringBuffer) ;
				setLoggingPath(stringBuffer) ;
			}
			getline(fin, stringBuffer) ;
			if(stringBuffer == "End Simulator Configuration File")
			{
				cout << "Config file read to completion \nMoving to MetaData file" << endl;
			}

		}

	}
