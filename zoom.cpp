#include <iostream>
#include <vector> 
#include "zoom.h"
#include "readwrite.h"

using namespace std;

vector<vector<char>> zoomLog(int xS, int yS, int xE, int yE, int step) {
    vector<vector<char>> cells;
    string temp;
    xS = (xS*2);
    xE = xE*2;

    cells = readVectorLog("log.txt", step);

	int c, l;	//column, row

	for(l = 0; l < cells.size(); l++)
	{			
        if (l >= (yS) && l <= (yE)){	
            for(c=0; c < cells[l].size(); c++) 
            {
                if (c >= (xS) && c <= (xE+1)) temp += cells[l][c];
            }
            cout<< temp << endl;
            temp.clear();
        }
    }
    return cells;
}


vector<vector<char>> zoomCells(int xS, int yS, int xE, int yE, vector<vector<char>> zones) {
    vector<vector<char>> newZones;
    vector<char> temp;

    int c, l;	//column, row

    for(l = 0; l < zones.size(); l++)
	{			
        if (l >= yS && l <= yE){	
            for(c=0; c < zones[l].size(); c++) 
            {
                if (c >= (xS) && c <= (xE)) {
                    temp.push_back(zones[l][c]);
                }
            }
            newZones.push_back(temp);
            temp.clear();
        }
    }

    return zones;
}