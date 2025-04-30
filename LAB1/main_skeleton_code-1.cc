#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

//In C/C++ use can use additional preprocessor directives
//which always start with a # to define constants.
//Later I will show you a C++ version that is better.

#define convertCubicFtToCubicMeter  0.02837262 //(2.54*12/100)^3

//Global Variable Declaration
//------------------------------------------

//This is not necessarily good programming practice,
//but I would like for you to understand 
//what a "global" variable is. Can you think
//why using a lot of global variables could
//cause problems?

float 	lengthOfRoomft= 0;
float   widthOfRoomft = 0;
float 	heightOfRoomft = 0; 
int 	durationOfEventInMins =0;
int 	numRepsOfEvent = 0;
float 	ventilationWithOutsideAir = 0;
float 	decayRateOfVirus = 0;
float	depositionToSurfaces =0;
float	additionalControlMeasures = 0;
int 	numPeoplePresent = 0;
float	numInfectedPeopleInRoom = 0;
float	fractionOfPopulationImmune = 0; 
float	breathingRateSusceptiblePeople =0;
float 	quantaExhalationRate_Infected = 0;
float	exhalationMaskEfficiency =0;
float 	fractionPeopleWearingMasks = 0;
float	inhalationMaskEfficiency =0;
float  	infectionRateInYourArea =0;


//Global Function Prototypes
//------------------------------------------

//You will need to provide the implementations after the 
//main function. For now, put all in one file.

void readInValues();
float volOfRoom();
void createDirectOutput();
float totalFirstOrderViralLossRate();
float numPeopleSusceptible();
float ventRatePerPerson();
float areaPerPersonInRoom();
float personsPerSquareMeter();
float volumePerPerson();
float netEmissionRateFromInfected();
float avgQuantaConcentration();
float quantaInhaledPerPerson();
float probabilityOfInfection_Conditional();
float avgNumCOVID_Cases_Conditional();
float numInfectedPeopleatBeginningInClassroom_RegionalRates();
float probabilityOfInfection_OneEvent_RegionalRates();
float numInfectedPeopleAfterEvent_RegionalRate();
float probabilityOfInfectionMultipleEvents_RegionalRates();
float numberOfCOVID_CasesOverTime_RegionalRate();
void  changeMaskWearingFraction();


int main()
{

	readInValues(); 
	createDirectOutput();
	changeMaskWearingFraction();

}

//For this assignment you can put all you global function implementations after main
//Later we will talk about multiple file implementations! 

void changeMaskWearingFraction()
{
	//place the data in a CSV format 
	//we will assume a regional rate here 

	ofstream outFile("mask_data.dat", ios::out);

	fractionPeopleWearingMasks = 0;

	while (fractionPeopleWearingMasks <= 1.0)
	{
		outFile << 100*fractionPeopleWearingMasks << "," << setprecision(5) << 
		100*probabilityOfInfectionMultipleEvents_RegionalRates() << endl;

		fractionPeopleWearingMasks += 0.01;
	}
}

void createDirectOutput()
{
	system("clear");

	string inputString;
	cout << "Please indicate output file name: " ;
	cin >> inputString;
	ofstream outFile(inputString.c_str(), ios::out);

	const int label_width = 85;
   	const int value_width = 15;

	outFile <<left<< setw(label_width) << "The volume of your room [cubic meters]:" 
             << right << setw(value_width) << setprecision(5) << volOfRoom() << endl;

	//You must complete the rest of the output to match the output file exactly! 
	//This will help the TA's grade you code a little faster! 

}//end createDirectOutput

float volOfRoom()
{
	return( lengthOfRoomft*widthOfRoomft*heightOfRoomft*convertCubicFtToCubicMeter);
}

//You will need to add all the functions listed in the function prototypes and in 
//lab specifications


void readInValues()
{

	ifstream inputFile("parameters.txt", ios::in);

	if (!inputFile) //is not valid
	{	
		cerr << "The file parameters.txt does not seem to exist!" << endl;
	}  // the file is good now read in values
	else
	{
		string trash; //this will read in the markers in the file
	
		inputFile >> lengthOfRoomft >> trash ;
		inputFile >> widthOfRoomft >> trash;
		inputFile >> heightOfRoomft >> trash;

		//you must do the rest!! 

	}


}

