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
int cont = 1;

void zero() {    
    numMutex.lock();
    int randIndex = rand()%99;
    globalArray[randIndex] = 0;
    numMutex.unlock();
}
void unity() {
    numMutex.lock();
    int randIndex = rand()%99;
    globalArray[randIndex] = 1;
    numMutex.unlock();
}
void print() {
    for (int i = 0; i < 100; i+=10) {
        for (int k = i; k < 10+i && k < 100; k++) {
            cout << globalArray[k];
        }
        cout << endl;
    }
}
int main() {
    srand(time(0));
    thread t[2];
    //Ensure running throughout entire program
    t[0] = thread(zero);
    t[0].detach()
    t[1] = thread(unity);
    t[1].detach()
    

    while (cont == 1) {
        print();
        int input;
        cout << "Please enter 1 to continue and 0 to quit:"<<endl;;
        cin >> input;
        if (input == 1) 
            cont = 1;
        else if (input == 0) 
            cont = 0;
    }

}