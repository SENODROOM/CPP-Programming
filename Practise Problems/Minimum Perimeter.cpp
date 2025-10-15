#include <iostream>
using namespace std;
int sum(int a, int b=100, int c=10)
{
    cout << "a= " << a << " b= " << b << " c= " << c << endl;
    return a + b + c;
}
int main()
{
    // sum();//error
    sum(2);
    sum(3, 4);
    sum(2, 3, 4);
   
}