#include <iostream>
#include <iomanip>
using namespace std;
int globe = 10;
void calculatearea() {
    cout << globe++<<endl;
}
int main()
{
    int globe = 2;
    calculatearea();
    cout << ::globe++<<endl;    
    cout << ::globe;
}