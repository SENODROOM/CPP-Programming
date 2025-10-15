#include <iostream>
#include <iomanip>
using namespace std;
void printthis(string s)
{
    cout << "inside printthis" << endl;
    cout << "hello " << s << endl;
}
void print()
{
    cout << "inside print" << endl;
    printthis("Ali");
    cout << "After print this" << endl;
}
int main()
{
    cout << "before print" << endl;
    print();
    cout << "after print" << endl;
}