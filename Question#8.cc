#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <stdlib.h>
#include <vector>


using namespace std;

int globalArray [100];
mutex numMutex;

void zero(){    
    while(globalArray)
    {
        numMutex.lock();
        int randIndex = rand()%99;
        globalArray[randIndex] = 0;
        numMutex.unlock();
    }
}
void unity(){
    while (globalArray)
    {
        numMutex.lock();
        int randIndex = rand()%99;
        globalArray[randIndex] = 1;
        numMutex.unlock();
    }
}
int main(){
    srand(time(0));
    // Option 1
    thread t[2];

    t[0] = thread(zero);
    t[1] = thread(unity);
    thread th1(zero);
    thread th2(unity);
    

    cout << "Please enter 1 to continue and 0 to quit:";
    int input;
    cin >> input;
    if (input == 1) 
        cout << array
    else if (input == 0) 
        break;

    for (int j = 0; j < 100; j++){
        th1.join();
        th2.join();
    }

}


