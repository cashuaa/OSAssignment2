#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "simulation.h"

using namespace std; 



	void* runner(void *param);



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




	void Simulation::toFile(bool monitor, bool file)
	{
		std::stringstream stream;
		string currentTime ;
		string verbage ;
		string outputStringForFile ;


		int cycleTime ; 
		int process = 1 ;



		simulationTimer.timer.start() ;
		currentTime = simulationTimer.getTime() + " - " ;
		cout << currentTime << "Simulator program starting" << endl ;

		outputStringForFile = currentTime + "Simulator program starting\n" ;



		ofstream outStream(configFile.getLoggingPath().c_str());



		if (configFile.getLogging() == "Log to Monitor")
		{
			outStream << "Logged to: monitor" << endl;
		}
		else if(configFile.getLogging() == "Log to File")
		{
			outStream << "Logged to: " << configFile.getLoggingPath() << endl;
		}
		else if (configFile.getLogging() == "Log to Both")
		{
			outStream << "Logged to: monitor and " << configFile.getLoggingPath() << endl;
		}
		else
		{
			outStream << "Logged to: " << configFile.getLogging() << endl;
		}


		if(monitor == true)
		{
			for (int i = 0; i < 2; i ++)
			{
				currentTime = simulationTimer.getTime() + " - " ;
				

				cout << currentTime ;
				outputStringForFile += currentTime ;


				if(meta.metaQueue.front().code == 'S')
				{
					cout << "OS: preparing process 1" << endl ;
					outputStringForFile += "OS: preparing process 1\n" ;
				}
				else if(meta.metaQueue.front().code == 'A')
				{
					cout << "OS: starting process 1" << endl ;
					outputStringForFile += "OS: starting process 1\n" ;
				}
				
				meta.metaQueue.pop();
			}




			while(!meta.metaQueue.empty() && meta.metaQueue.front().cycles != 0)
			{
				currentTime = simulationTimer.getTime() + " - " ;
				cout << currentTime << "Process " << process ;
				outputStringForFile += currentTime ;
				outputStringForFile += "Process 1" ;

				cycleTime = calculate( meta.metaQueue.front().code, meta.metaQueue.front().descriptor, meta.metaQueue.front().cycles ) ;


				if(meta.metaQueue.front().code != 'M')
				{
					cout << ": start " ; 
					outputStringForFile += ": start " ;
				}
				if(meta.metaQueue.front().code == 'M')
				{
					cout << ": " ;
					outputStringForFile += ": " ;
				}


				verbage = " empty verbage" ;

				if(meta.metaQueue.front().code == 'P')
				{
					verbage = "processing action";
					cout << verbage << endl ;
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;
				}
				else if(meta.metaQueue.front().code == 'M')
				{

					if(meta.metaQueue.front().descriptor == "allocate")
					{
						verbage = "allocating memory";
						cout << verbage << endl ;
						outputStringForFile += verbage ; 
						outputStringForFile += "\n" ;
					}
					else if (meta.metaQueue.front().descriptor == "block")
					{
						verbage = "blocking memory";
						cout << verbage << endl;
						outputStringForFile += verbage ;
						outputStringForFile += "\n" ;				
					}
				
				}


				else if(meta.metaQueue.front().code == 'O')
				{
					verbage = meta.metaQueue.front().descriptor + " output" ;
					cout << verbage << endl ;
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;		
					threadSim(cycleTime);	
				}


				else if(meta.metaQueue.front().code == 'I')
				{

					verbage = meta.metaQueue.front().descriptor + " input" ;
					cout << verbage << endl ;
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;
					threadSim(cycleTime);		
				
				}		
				else
				{
					cout << verbage << endl ;
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;
				}



				currentTime = simulationTimer.getTime() + " - " ;
				cout << currentTime << "Process " << process ;
				outputStringForFile += currentTime ;
				outputStringForFile += "Process 1" ;

				if(meta.metaQueue.front().code != 'M')
				{
					cout << ": end " << verbage << endl ;
					outputStringForFile += ": end " ;
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;
				}

				if(meta.metaQueue.front().code == 'M')
				{
					stream << "0x" << hex << allocateMemory(42949296);
					if(meta.metaQueue.front().descriptor == "allocate")
					{	
						cout << ": memory allocated at " << stream.str() << endl;
						outputStringForFile += ": memory allocated at 0x" ;
						outputStringForFile += stream.str() ;
						outputStringForFile += "\n" ;			
					}
					else if(meta.metaQueue.front().descriptor == "block")
					{
						cout << ": memory blocked" << endl;
						outputStringForFile += ": memory blocked" ;
						outputStringForFile += "\n" ;				
					}
				}
				meta.metaQueue.pop();	
			
			}


			currentTime = simulationTimer.getTime() + " - " ;
			cout << currentTime << "OS: removing process " << process << endl;
			outputStringForFile += currentTime ; 
			outputStringForFile += "OS: removing process " ;
			outputStringForFile += process ;
			outputStringForFile += "\n" ;

			
			currentTime = simulationTimer.getTime() + " - " ;
			cout << currentTime << "Simulator program ending" << endl;
			outputStringForFile += currentTime ;
			outputStringForFile += "Simulator program ending\n" ;

			if (file == true)
			{
				outStream << outputStringForFile ;
			}
			outStream.close();
		}

		else if(monitor == false)
		{
			for (int i = 0; i < 2; i ++)
			{
				currentTime = simulationTimer.getTime() + " - " ;
				
				outputStringForFile += currentTime ;


				if(meta.metaQueue.front().code == 'S')
				{
					outputStringForFile += "OS: preparing process 1\n" ;
				}
				else if(meta.metaQueue.front().code == 'A')
				{
					outputStringForFile += "OS: starting process 1\n" ;
				}
				
				meta.metaQueue.pop();
			}




			while(!meta.metaQueue.empty() && meta.metaQueue.front().cycles != 0)
			{
				currentTime = simulationTimer.getTime() + " - " ;
				outputStringForFile += currentTime ;
				outputStringForFile += "Process 1" ;

				cycleTime = calculate( meta.metaQueue.front().code, meta.metaQueue.front().descriptor, meta.metaQueue.front().cycles ) ;


				if(meta.metaQueue.front().code != 'M')
				{
					outputStringForFile += ": start " ;
				}
				if(meta.metaQueue.front().code == 'M')
				{
					outputStringForFile += ": " ;
				}


				verbage = " empty verbage" ;

				if(meta.metaQueue.front().code == 'P')
				{
					verbage = "processing action";
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;
				}
				else if(meta.metaQueue.front().code == 'M')
				{

					if(meta.metaQueue.front().descriptor == "allocate")
					{
						verbage = "allocating memory";
						outputStringForFile += verbage ; 
						outputStringForFile += "\n" ;
					}
					else if (meta.metaQueue.front().descriptor == "block")
					{
						verbage = "blocking memory";
						outputStringForFile += verbage ;
						outputStringForFile += "\n" ;				
					}
				
				}


				else if(meta.metaQueue.front().code == 'O')
				{
					verbage = meta.metaQueue.front().descriptor + " output" ;
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;		
					threadSim(cycleTime);	
				}


				else if(meta.metaQueue.front().code == 'I')
				{

					verbage = meta.metaQueue.front().descriptor + " input" ;
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;
					threadSim(cycleTime);		
				
				}		
				else
				{
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;
				}



				currentTime = simulationTimer.getTime() + " - " ;
				outputStringForFile += currentTime ;
				outputStringForFile += "Process 1" ;

				if(meta.metaQueue.front().code != 'M')
				{
					outputStringForFile += ": end " ;
					outputStringForFile += verbage ;
					outputStringForFile += "\n" ;
				}


				if(meta.metaQueue.front().code == 'M')
				{
					stream << "0x" << hex << allocateMemory(42942496);
					if(meta.metaQueue.front().descriptor == "allocate")
					{	
						outputStringForFile += ": memory allocated at " ;
						outputStringForFile += stream.str() ;
						outputStringForFile += "\n" ;			
					}
					else if(meta.metaQueue.front().descriptor == "block")
					{
						outputStringForFile += ": memory blocked" ;
						outputStringForFile += "\n" ;				
					}
				}
				meta.metaQueue.pop();	
			
			}


			currentTime = simulationTimer.getTime() + " - " ;
			outputStringForFile += currentTime ; 
			outputStringForFile += "OS: removing process " ;
			outputStringForFile += process ;
			outputStringForFile += "\n" ;

			
			currentTime = simulationTimer.getTime() + " - " ;
			outputStringForFile += currentTime ;
			outputStringForFile += "Simulator program ending\n" ;

			if (file == true)
			{
				outStream << outputStringForFile ;
			}
			outStream.close();
		}

	}


	int Simulation::calculate(char code, string descriptor, int cycles) 
	{

		if(descriptor == "run")
		{
			cycles = (cycles * configFile.getProcessor() ) ;
		}
		else if(descriptor == "allocate" || descriptor == "block")
		{
			cycles = (cycles * configFile.getMemory () ) ;
		}
		else if(descriptor == "monitor")
		{
			cycles = (cycles * configFile.getMonitor() ) ;
		}
		else if(descriptor == "hard drive")
		{
			cycles = (cycles * configFile.getHardDrive() ) ;
		}
		else if(descriptor == "printer")
		{
			cycles = (cycles * configFile.getPrinter() ) ;
		}
		else if(descriptor == "system memory")
		{
			cycles = (cycles * configFile.getSystemMemory() ) ;
		}
		else if(descriptor == "keyboard")
		{
			cycles = (cycles * configFile.getKeyboard() ) ;
		}
		return cycles ;
	}


	void Simulation::threadSim (int mSec)
	{
			simulationTimer.delay = mSec;
		
			pthread_t tid;
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_create(&tid, &attr, runner, &simulationTimer);
			pthread_join(tid, NULL);
	}		





		void* runner (void *param)
	{
			timerClass* runnerTimer = (timerClass*) param;
		 	runnerTimer->timer.delay(runnerTimer->delay);
			pthread_exit(0);	

	}	