#include <iostream>
#include <iomanip>
using namespace std;
const float PI = 3.14;
float calculatearea(float rad) {
    float area;
    area = PI * rad * rad;
    return area;
}
int main()
{
    cout <<calculatearea(2) ;
}