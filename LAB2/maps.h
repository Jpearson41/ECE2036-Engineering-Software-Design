#ifndef MAPS_H
#define MAPS_H
#define NUM_LOCATIONS 28
#include <string>

using namespace std;

class MapLocation
{
public:
	MapLocation();
	MapLocation(int Id, string name, float x1, float y1);
	void setIDNum(int z);
	void setName(string name);
	void setX(float x1);
	void setY(float y1);
	int getIDNum();
	string getName();
	float getX();
	float getY();
private:
	int IDNum;
	string nameOfLoc;
	float x;
	float y;
};

class Map
{
public:
	void initializeMap(string file);
	MapLocation locations[NUM_LOCATIONS];
	int numOfLocations = 0;
};

#endif
