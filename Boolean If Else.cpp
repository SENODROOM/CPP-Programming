#include<iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    bool flag = num % 5;
    if (flag)
        cout << "not divisible" << endl;
    else
        cout << "divisible" << endl;
   
}