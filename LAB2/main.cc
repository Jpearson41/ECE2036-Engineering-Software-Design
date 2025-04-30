#include "maps.h"
#include "schedule.h"


using namespace std;

int main()

{

   system("clear");
   srand(2020);

//get input for coordinates and store in an internal array
//For simplicity you may assume that this is fixed at 24 locations

   Map ScrantonMapCoordinates;
   ScrantonMapCoordinates.initializeMap("ScrantonMapCoordinates.txt");

//Now instantiate a DwightSchruteSchedule object and get the locations
//that he needs to visit today. Remember he needs to
//begin and end at the Scranton Office Branch.

   Schedule DwightShruteSchedule("Dwight Schrute");
   DwightShruteSchedule.getToDoList(ScrantonMapCoordinates);
   DwightShruteSchedule.generateRoute();

}
