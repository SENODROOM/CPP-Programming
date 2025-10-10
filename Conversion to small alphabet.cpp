#include<iostream>
using namespace std;
int main() {
    char letter;
    cout << "enter upper case letter"<<endl;
    cin >> letter;
    letter = letter + 32;
    cout << letter;
    return 0;
}