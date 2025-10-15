#include <iostream>
using namespace std;
int sum(int a, int b) { cout << "int,int" << endl; return a + b; }
int sum(int a, int b, int c) { cout << "int,int,int" << endl; return a + b + c; }
float sum(int a, float b) { cout << "int,float" << endl; return a + b; }
float sum(float a, float b, float c) { cout << "float" << endl; return a + b + c; }
float sum(float a, float b) { cout << "float,float" << endl; return a + b; }
double sum(double a, double b) { cout << "double,double" << endl; return a + b; }
int main()
{
    cout << sum(2, 3) << endl;
    cout << sum(2, 3,7) << endl;
    cout << sum(2, 3.5f) << endl;
    cout << sum(2.4f, 3.5f,12.0f) << endl;
    cout << sum(2.5f, 3.5f) << endl;
    cout << sum(2.5, 3.5) << endl;
   
     
}