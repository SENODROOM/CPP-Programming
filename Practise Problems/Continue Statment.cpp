#include <iostream>
using namespace std;
int main() {
    int i = 1;
    while (i <= 10)
    {
        cout << i << endl;
        i++;
        if(i==3 || i==7)
            continue;
        cout << "After" << endl;
    }
    cout << "end";
}