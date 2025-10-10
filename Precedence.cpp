#include<iostream>
using namespace std;
int main() {
    int a = 12,b=7;
    int c = 23 / 4 - (3 - 4) / 6 + 5;
    // 23 / 4 - (-1) / 6 + 5
    // 23 / 4 + 1 / 6 + 5
    // 5 + 0 + 5
    // 10
    cout << c;
}