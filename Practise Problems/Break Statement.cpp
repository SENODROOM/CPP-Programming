#include <iostream>
using namespace std;
int main() {
    int i = 1;
    while (i <= 10)
    {
        cout << i << endl;
        if(i==3)
            break;
        cout << "After" << endl;
        i++;
    }
    cout << "end";
}