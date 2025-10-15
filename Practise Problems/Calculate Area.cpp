#include <iostream>
#include <iomanip>
using namespace std;
const float PI = 3.14;
void calculatearea() {
    float area,rad;
    cin >> rad;
    area = PI * rad * rad;
    cout<<area;
}
int main()
{
    calculatearea() ;
   
}