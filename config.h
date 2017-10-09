// HEADERS
#include <string>
#include <iostream>

using namespace std;


class Config 
{
public:

	Config() ;
	~Config() ;

//GETTERS//

	string const getVersion() ;
	string const getFilePath() ;
	string const getLogging() ;

	int const getProcessor() ;
	int const getMonitor() ;
	int const getHardDrive() ;
	int const getPrinter() ;
	int const getKeyboard() ; 
	int const getMemory() ;
	int const getMouse() ;
	int const getSpeaker() ;
	int const getSystemMemory() ;
	string const getLoggingPath() ;


//SETTERS//
	
	void setVersion( const string) ;
	void setFilePath( const string) ;
	void setlogging( const string) ;
	void setLoggingPath(const string) ;

	void setProcessor( const int) ;
	void setMonitor( const int) ;
	void setHardDrive( const int) ;
	void setPrinter( const int) ;
	void setKeyboard( const int) ; 
	void setMemory( const int) ;
	void setSystemMemory( const int) ;
	void setMouse( const int) ;
	void setSpeaker( const int) ;

	void readIn( string ) ;
	void checkForNewLine( string& ) ;

	void callMetaData( string ) ;


private:

	string version;
	string filePath;
	string logging;
	string loggingPath;

	int processor ;
	int monitor ;
	int hardDrive ;
	int printer ;
	int keyboard ;
	int memory ;
	int mouse ;
	int speaker ;
	int systemMemory ;


} ;