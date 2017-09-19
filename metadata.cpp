#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "metadata.h"

using namespace std; 


	MetaData::MetaData() 
	{

	}

	MetaData::~MetaData() 
	{
		
	}




//NEWLINE//
	void MetaData::checkForNewLine( string& stringBuffer ) 
	{
		if(stringBuffer[0] == '\n' || stringBuffer[0] == ' ')
		{
			stringBuffer.erase(stringBuffer.begin()) ;
		}
	}








	void MetaData::readIn(string data) 
	{
		
		/*
		S - OPERATING SYSTEM, USED WITH START AND END
		A - PROGRAM APPLICATION, USED WITH START AND END
		P - PROCESS USED WITH RUN
		I - USED WITH INPUT OPERATION DESCRIPTORS SUCH AS HARD DRIVE, KEYOBARD, MOUSE
		O - USED WITH OUTPUT OPERATION DESCRIPTORS SUCH AS HARD DRIVE, MONITOR, SPEAKER
		M - MEMORY USED WITH BLOCK, ALLOCATE
		*/
		int intBuffer ;
		meta structBuffer ;
		string stringBuffer ;
		ifstream fin ;

		fin.open(data.c_str()) ;

		getline(fin, stringBuffer) ;

		if(stringBuffer != "Start Program Meta-Data Code:")
		{
			throw runtime_error("Bad file.") ;
		}


		getline(fin, stringBuffer, '(') ;

		if(stringBuffer[0] != 'S')
		{
			throw runtime_error("Bad file.") ;
		}
		else
		{		
			structBuffer.code = stringBuffer[0] ;
		}

		getline(fin, stringBuffer, ')') ;
		structBuffer.descriptor = stringBuffer ;

		fin >> intBuffer ;
		structBuffer.cycles = intBuffer ;

		metaQueue.push(structBuffer) ;


		while((structBuffer.code == 'S' || structBuffer.code != 'S') && structBuffer.descriptor != "end")
		{

			getline(fin, stringBuffer, '(') ;

				while(stringBuffer[0] != 'S' || stringBuffer[0] != 'A' 
					||stringBuffer[0] != 'P' ||stringBuffer[0] != 'I' 
					||stringBuffer[0] != 'O' || stringBuffer[0] != 'M' )
				{
					cout << "stuck on " << stringBuffer << endl;
					stringBuffer.erase(stringBuffer.begin()) ;
				}

			checkForNewLine(stringBuffer) ;

			structBuffer.code = stringBuffer[0] ;
			getline(fin, stringBuffer, ')') ;
			structBuffer.descriptor = stringBuffer ;

			fin >> intBuffer ;
			structBuffer.cycles = intBuffer ;

			metaQueue.push(structBuffer) ;

//			getline(fin, stringBuffer, ';') ;
		}
		
		structBuffer.code = 'S';
		structBuffer.descriptor = "end";
		structBuffer.cycles = 0;

		//Push onto Queue
		metaQueue.push(structBuffer);

		fin.close();
	}