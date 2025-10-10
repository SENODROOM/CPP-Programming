#include <iostream>
using namespace std;
int main() {
    int i, j;
    for (i = 1, j = 10; i <= 10 && j >= 1; i++, j--)
    {
        cout << i << " " << j << endl;
    }
}