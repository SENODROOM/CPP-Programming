#include <iostream>
using namespace std;
int sum(int , int );
int sum(int , int , int );
float sum(int , float );
int main()
{
    cout << sum(2, 3) << endl;
    cout << sum(2, 3,7) << endl;
    cout << sum(2, 3.5f) << endl;
   
     
}
int sum(int a, int b) { cout << "int,int" << endl; return a + b; }
int sum(int a, int b, int c) { cout << "int,int,int" << endl; return a + b + c; }
float sum(int a, float b) { cout << "int,float" << endl; return a + b; }