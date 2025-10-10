#include <iostream>
using namespace std;
int main() {
    int s, e;
    cin >> s >> e;
    int i;
    for (i = s; i <= e; i++)
    {
        if (i % 2 == 0)
            cout << i<<",";
    }
   
 
}