#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    float a = 12.324325,b=7.555;
    cout <<setprecision(4)<<a<<endl;
    cout <<fixed <<setprecision(4)<< b;
}