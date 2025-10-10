#include<iostream>
using namespace std;
int main() {
    char letter;
    cout << "enter upper case letter"<<endl;
    cin >> letter;
    letter = letter + 32;
    cout << letter << endl;
    char letter2;
    cin >> letter2;
    cout << letter2;
    return 0;
}