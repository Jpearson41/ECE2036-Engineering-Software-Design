#include "schedule.h"
//#include "maps.h"
#include <iomanip>
#include <fstream>
#include <iostream>


//MapLocation Implementation
//Default Constructor
MapLocation::MapLocation() 
{
	IDNum = 0;
	nameOfLoc = "OG";
	x = 0.0;
	y = 0.0;
}
//4 Param Constructor
MapLocation::MapLocation(int Id, string name, float x1, float y1)
{
	IDNum = Id;
	nameOfLoc = name;
	x = x1;
	y = y1;
}

//Map Implementation
//InitializeMap Implementation
void Map::initializeMap(string file)
{
	int num = 0;
	int tempID;
	string tempString;
	float tempX;
	float tempY;
	ifstream inputMap(file.c_str(), ios::in);
	//Add MapLocations into locations array
	
	while(inputMap>>tempID>>tempString>>tempX>>tempY)
	{
		MapLocation map = MapLocation(tempID,tempString,tempX,tempY);
		locations[num] = map;
		numOfLocations +=1;
		num++;
	}
}
//Setters & Getters
//ID setter
void MapLocation::setIDNum(int z)
{
	IDNum = z;
}
//Name setter
void MapLocation::setName(string name)
{
	nameOfLoc = name;
}
//X setter
void MapLocation::setX(float x1)
{
	x = x1;
}
//Y setter
void MapLocation::setY(float y1)
{
	y = y1;
}
//ID getter
int MapLocation::getIDNum()
{
	return(IDNum);
}
//Name getter
string MapLocation::getName()
{
	return(nameOfLoc);
}
//X getter
float MapLocation::getX()
{
	return(x);
}
//Y getter
float MapLocation::getY()
{
	return(y);
}

