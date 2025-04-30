#include "schedule.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;
//Function Implementation
////Default Constructor
Schedule::Schedule()
{
	name = "Unknown";
	numLoc = 0;
}
//1 Param Constructor
Schedule::Schedule(string name1)
{
	name = name1;
	numLoc = 0;//size of locations array in Map class;
}
//getToDoList Implementation
void Schedule::getToDoList(Map map1)
{
	cout <<"Good Morning " << name << "!!!" <<endl;
	cout <<"Please list the locations that you need to visit today" <<endl;
	cout <<"(input 0 to end your list)" << endl;
	cout << " " << endl;
	cout <<"1(Scranton Office Branch)"<<endl;

	//Take input values
	
	int counter2 = 1;
	//Put starting point as Dunder Mifflin
	toDoList[0] = map1.locations[0];
	int input = -1;
	while (input != 0) 
	{
		cin >> input;
		if (input != 0) {
			MapLocation needMapLoc = map1.locations[input-1];
			//Making routeLocations
			toDoList[counter2] = needMapLoc;
			counter2 ++;
		}else {
			break;
		}
	}
	//Set Number of Locations 
	toDoList[counter2] = map1.locations[0];
	setNumLoc(counter2+1);

}	
//generateRoute Implementation	
void Schedule::generateRoute()
{
//generate and print all specified routes
	//ToDolist 
	ofstream outFile("my_output.txt", ios::out);
	outFile << "Todo list from worker" <<endl;
	outFile << "---------------------------" << endl;

	//Must input first and last spots 

	int num = getNumLoc();
	

	for (int i = 0; i < num-1; i++) 
	{
		int ID1 = toDoList[i].getIDNum();
		string name1 = toDoList[i].getName();
		int ID2 = toDoList[i+1].getIDNum();
		string name2 = toDoList[i+1].getName();
		outFile << name1 <<"(" << ID1 << ")" << "to " << name2 << "(" <<ID2 <<")"<< " = " << calcDistance(toDoList[i], toDoList[i+1]) <<endl;
		outFile << " " << endl;
		
	}
	outFile << "TOTAL DISTANCE:" << calcTotalDistance(toDoList) << endl;
	outFile << " " << endl;


	outFile << "Create inital Path with nearest neighbor" <<endl;
	outFile << "---------------------------" << endl;
	//Now create initial Path
	createInitialRoute();
	//Print result
	for (int i = 0; i < num-1; i++) 
	{
		int ID1 = routeLocations[i].getIDNum();
		string name1 = routeLocations[i].getName();
		int ID2 = routeLocations[i+1].getIDNum();
		string name2 = routeLocations[i+1].getName();
		outFile << name1 <<"(" << ID1 << ")" << "to " << name2 << "(" <<ID2 <<")"<< " = " << calcDistance(toDoList[i], toDoList[i+1]) <<endl;
		outFile << " " << endl;
		
	}
	outFile << "TOTAL DISTANCE:" << calcTotalDistance(routeLocations) << endl;
	outFile << " " << endl;

	outFile << "Greedy algorithm with random swapping" <<endl;
	outFile << "---------------------------" << endl;

	greedyOptimization();
	//Print result
	for (int i = 0; i < num-1; i++) 
	{
		int ID1 = routeLocations[i].getIDNum();
		string name1 = routeLocations[i].getName();
		int ID2 = routeLocations[i+1].getIDNum();
		string name2 = routeLocations[i+1].getName();
		outFile << name1 <<"(" << ID1 << ")" << "to " << name2 << "(" <<ID2 <<")"<< " = " << calcDistance(toDoList[i], toDoList[i+1]) <<endl;
		outFile << " " << endl;
		
	}
	outFile << "TOTAL DISTANCE:" << calcTotalDistance(routeLocations) << endl;
	outFile << " " << endl;

	outFile << "Simulated annealing (SA) algorithm with random swapping" <<endl;
	outFile << "---------------------------" << endl;

	SAOptimization();
	for (int i = 0; i < num-1; i++) 
	{
		int ID1 = routeLocations[i].getIDNum();
		string name1 = routeLocations[i].getName();
		int ID2 = routeLocations[i+1].getIDNum();
		string name2 = routeLocations[i+1].getName();
		outFile << name1 <<"(" << ID1 << ")" << "to " << name2 << "(" <<ID2 <<")"<< " = " << calcDistance(toDoList[i], toDoList[i+1]) <<endl;
		outFile << " " << endl;
		
	}
	outFile << "TOTAL DISTANCE:" << calcTotalDistance(routeLocations) << endl;
	outFile << " " << endl;
	outFile.close();
}

//Private functions implementations
//Initial Route
void Schedule::createInitialRoute()
{
	//initial computation method
	//Add route to routeLocation

	float min;
	int min_index;
	routeLocations[0] = toDoList[0];
	int num = getNumLoc();
	for (int i = 0; i < num-1; i++) {
		min = 1000000000000000000;
		for(int k = 0; k < num-1; k++) {
			if (toDoList[k].getIDNum() != 1) {
				int dig = calcDistance(routeLocations[i], toDoList[k]);
				if (dig < min) {
					min = dig;
					min_index = k;
				}
			}
		} 

		routeLocations[i+1] = toDoList[min_index];
		toDoList[min_index].setIDNum(1);
	}
	routeLocations[numLoc-1] = toDoList[numLoc -1];
	

}
//Greedy Route
void Schedule::greedyOptimization()
{	
		//uses path created by nearest neighbor heuristic
	for (int i = 0; i < (numLoc)*100; i++) {
		//randomly pick two elements to swaps between
		// index 1 and numItemsToDo-1
		int pos1 = rand()%(numLoc-2)+1;
		int pos2 = rand()%(numLoc-2)+1;			
		float dist1 = calcTotalDistance(routeLocations);
		swap(routeLocations, pos1, pos2);
		float dist2 = calcTotalDistance(routeLocations);
		if (dist2 > dist1) {
			swap (routeLocations, pos1, pos2);
		}
	}
}
//Simulating Annealing 
void Schedule::SAOptimization()
{
	float prob;
	float throwDice;
	int numItemsToDo = getNumLoc();
	//this is a linear ramping down of the temperature
	for (float temp = 15.0; temp >=0; temp-=0.1)
	{
		for (int i = 0; i < (numItemsToDo)*100; i++)
		{
			//randomly pick two elements to swaps between
			// index 1 and numItemsToDo-1
			int pos1 = rand()%(numItemsToDo-2)+1;
			int pos2 = rand()%(numItemsToDo-2)+1;
			//I will allow pos1 and pos2 to be possibly equal for simplicity
			float dist1 = calcTotalDistance(routeLocations);
			swap(routeLocations, pos1, pos2);
			float dist2 = calcTotalDistance(routeLocations);
			dist2 < dist1 ? prob =1.0 : prob = exp(-(dist2 - dist1)/(0.5*temp));
			throwDice = static_cast<float>(rand())/RAND_MAX;
			if (throwDice > prob) //reject the swap .. i.e. swap back
			{
				swap(routeLocations,pos1,pos2);
			}
		}
	}//end temperature loop

}
//Total Distance
float Schedule::calcTotalDistance(MapLocation array[])
{
	//calc total distance in toDoList(Array)
	float totDistance = 0;
	for (int i = 0; i<numLoc-1; i++)
	{
		
		totDistance += calcDistance(array[i],array[i+1]);
	}
	return totDistance;
}
//swap
void Schedule::swap(MapLocation array[], int x1, int x2)
{
	//Swap 2 locations in an array
	MapLocation temp = array[x1];
	array[x1] = array[x2];
	array[x2] = temp;
      
}

//calcDistance between two MapLocations
float Schedule::calcDistance(MapLocation x1, MapLocation x2)
{
	int distance = 0;
	int Xloc1, Yloc1, Xloc2, Yloc2;
	Xloc1 = x1.getX();
	Yloc1 = x1.getY();
	Xloc2 = x2.getX();
	Yloc2 = x2.getY();
	distance = abs(Xloc2 - Xloc1) + abs(Yloc2 - Yloc1);
	return(distance);
}

//Getter & Setter

int Schedule::getNumLoc() {
	return numLoc;
}
void Schedule::setNumLoc(int x) {
	numLoc = x;
}
