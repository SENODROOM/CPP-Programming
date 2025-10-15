#include <iostream>
using namespace std;
int sum(int a=500, int b=100, int c=10)
{
    cout << "a= " << a << " b= " << b << " c= " << c << endl;
    return a + b + c;
}
int main()
{
    cout<<sum()<<endl;
    cout<<sum(2) << endl;
    cout<<sum(3, 4) << endl;
    cout<<sum(2, 3, 4) << endl;
   
}