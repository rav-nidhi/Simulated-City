#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include "residential.h"
#include "industrial.h"
#include "commercial.h"
#include "pollution.h"
#include "functions.h"
#include "readwrite.h"
#include "zoom.h"
using namespace std;

int main()
{
    string config;
    vector<vector<char>> cells;		// 2d vector to represent cells

    cout << "Input name of configuration file: ";	// prompt for config file name
	getline(cin, config);
    
    string regFile;			// region file name
	string maxSteps;		// max time steps of simulation
	string refRate;			// refresh rate

    regFile = readFile(config,0);
   	maxSteps = readFile(config,1);
    refRate = readFile(config,2);
    cells = readVector(regFile);
	
	int max = stoi(maxSteps);		// max time steps after conversion
	int rate = stoi(refRate);		// refresh rate after conversion
	
	//initialize reference zones
	vector<vector<char>> zones = zoneInit(cells);
	int timeStep = 0;	//keeps track of current time step
	int availWorkers = 0;	//tracks available workers
	int availGoods = 0;		//tracks available goods

	PollutionManager pol(cells);		//pollution tracker
	
	//grow city
	while(timeStep <= max) {		//while max time steps has not been reached
		system("clear");		//clear screen for animation
		//output layout for each time step
		cout << "Time Step: " << timeStep << endl;
		for(unsigned i=0; i<cells.size(); i++) {
			for(unsigned j=0; j<cells[i].size(); j++) {
				cout << cells[i][j] << " ";
			}
			cout << endl;
		}
		cout << "Available Workers: " << availWorkers << endl;
		cout << "Available Goods: " << availGoods << endl;
		
		writeFile("log.txt", cells, timeStep);		// log
		updateRes(cells, zones, availWorkers);		//update residential zones if possible
		updateCom(cells, zones, availWorkers, availGoods); 		//update commercial zones if possible
		updateInd(cells, zones, availWorkers, availGoods);		//update ind zones if possible
		timeStep++;		//increment time step
		//sleep(1);		//for animation
	}
	
	pol.spreadAirPol(zones, cells);		//update pollution
	pol.spreadLightPol(zones, cells);	
	pol.spreadSoundPol(zones, cells);

	cout << endl << "*************************" << endl;
	cout << "Pollution Counts: " << endl;
	cout << "Air: " << pol.getAirPol() << endl;
	cout << "Light: " << pol.getLightPol() << endl;
	cout << "Sound: " << pol.getSoundPol() << endl;
	cout << "*************************" << endl << endl;

	while (timeStep != -1){				//while to look at specific timestep
		int xS;
		int yS;	// start x, y
		int xE;
		int yE;	// end x, y

		vector<vector<char>> zoomZone;
		vector<vector<char>> newZone;

		cout << "Enter time step you want to observe (-1 to exit): " << endl;
		cin >> timeStep;
		readLog("log.txt", timeStep);			// read map at timestep from log
		cout << endl;

		if (timeStep != -1) {
			cout << "Want to take a closer look? Insert the coordinates (formatted as x y)!" << endl;
			cout << "Start Coords (top left corner of area): ";
			cin >> xS;
			cin >> yS;

			cout << "End Coords (bottom right corner of area): ";
			cin >> xE;
			cin >> yE;

			zoomZone = zoomLog(xS,yS,xE,yE,timeStep);
			newZone = zoomCells(xS,yS,xE,yE,zones);

			PollutionManager polZoom(zoomZone);

			polZoom.spreadAirPol(newZone, zoomZone);		//update pollution
			cout << "Air Pollution: " << polZoom.getAirPol() << endl;
			
			// is this an ok amount of pollution?
			// compare it to average pollution
		}

	
	}

	return 0;
}



