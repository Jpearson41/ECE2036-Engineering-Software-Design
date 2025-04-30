#include <vector>
#include <iostream>

using namespace std;

class CrazyCharacters
{
    public:
        CrazyCharacters(char v);
        CrazyCharacters(const CrazyCharacters & toCopy);
        CrazyCharacters & operator=(const CrazyCharacters & RHS);
        CrazyCharacters operator+(const char & RHS);
        CrazyCharacters & operator++(); //prefix
        CrazyCharacters & operator+(int);  //postfix
        void print();
    private:
        vector <char> clown;
};
//Constructor
CrazyCharacters::CrazyCharacters(char v) {
    this->clown.push_back(v);
}
//Copy constructor
CrazyCharacters::CrazyCharacters(const CrazyCharacters & toCopy) {
    int size = toCopy.clown.size();
    for (int i = 0; i < size; i++) {
        clown[i] = toCopy.clown[i];
    }
    clown.push_back('_');
}

CrazyCharacters & CrazyCharacters::operator=(const CrazyCharacters & RHS) {
    int size = RHS.clown.size();
    for (int i = 0; i < size; i++) {
        clown[i] = RHS.clown[i];
    }
    this->clown.push_back('!');
    return (*this);
}
CrazyCharacters CrazyCharacters::operator+(const char & RHS) {
    CrazyCharacters char1;
    vector <char> temp = clown;
    temp.push_back(RHS);
    return temp;
}
CrazyCharacters & CrazyCharacters::operator++() {
    char toCopy = this->clown.back();
    clown.push_back[toCopy];
    return (*this);
}
CrazyCharacters & CrazyCharacters::operator++(int) {
    char toCopy = this->clown.front();
    clown.push_back[toCopy];
    return (*this);
}
void CrazyCharacters::print() {
    for (vector <char>::iterator it = clown.begin(); it < clown.end(); it++) {
        cout << *it <<endl;
    }
}

int main()
{
    CrazyCharacters BuzzLightYear('b');
    CrazyCharacters Slinky('s');
    CrazyCharacters DrDecode('d');
    BuzzLightYear = BuzzLightYear + 'u';
    Slinky = Slinky + 'I';
    DrDecode = DrDecode + 'r';
    Slinky++;
    ++Slinky;
    CrazyCharacters BeardedClone(DrDecode);
    BuzzLightYear.print();
    DrDecode.print();
    BeardedClone.print();
}
