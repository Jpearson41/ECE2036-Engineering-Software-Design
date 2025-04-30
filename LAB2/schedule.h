#include <string>
#include "maps.h"
#ifndef SCHEDULE_H
#define SCHEDULE_H

using namespace std;

class Schedule
{
public:
	Schedule();
	Schedule(string name1);
	MapLocation toDoList[NUM_LOCATIONS];
	MapLocation routeLocations[NUM_LOCATIONS];
	
	void generateRoute();
	//Getters/Setters
	void getToDoList(Map map1);
	string getName();
	void setName(string);
	int getNumLoc();
	void setNumLoc(int);
	MapLocation getRouteLocs();
	void setRouteLocs(MapLocation);
	
private:
	//Variables
	string name;
	int numLoc;
	
	//Utility Functions
	float calcTotalDistance(MapLocation[]);
	void swap(MapLocation[], int x1, int y1);
	void createInitialRoute();
	void greedyOptimization();
	void SAOptimization();
	float calcDistance(MapLocation x1, MapLocation y1);

};

#endif
