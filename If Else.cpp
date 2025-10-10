#include<iostream>
using namespace std;
int main() {
    int age;
    cin >> age;
    if (age >= 18)
        cout << "eligible for vote";
    else
        cout << "not eligible for vote";
}