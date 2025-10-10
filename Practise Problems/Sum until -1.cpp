#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    for (int i = 1; i != -1; sum += i)
    {
        cout << "Enter i" << endl;
        cin >> i;
    }
    cout << sum+1;
}