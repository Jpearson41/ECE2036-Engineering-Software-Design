#include <iostream>
#include <string>
#define MAX 3
#define TRUE 1
#define FALSE 0
using namespace std;

class Taco 
{
	Public:
	Taco():cheese(FALSE), meat(TRUE), lettuce(FALSE), owner ("Burdell") {}
	Taco(string o):cheese(FALSE), meat(TRUE), lettuce(FALSE), owner(o) {}
	string getData()
	{ return( owner + ": Taco:"+ "c:"+ to_string(cheese)
		+ " m:" + to_string(meat) + "l:" + to_string(lettuce));
    }

	private:
	string owner;
	bool cheese;
	bool lettuce;

};
class Dinner
{
	public:
	void printOrder();
	private:
	Taco T_list[MAX];
};
void Dinner::printOrder()
{
	int i;
	for (i = 0; i < MAX-1; i++)
		cout<<T_list[i].getData() << endl;
}

int main()
{
	Dinner TuesdayNight;
	TuesdayNight.printOrder();
}