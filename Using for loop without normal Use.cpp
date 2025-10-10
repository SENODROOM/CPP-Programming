#include <iostream>
using namespace std;
int main() {
    int s, e;
    cin >> s >> e;
    int i=s;
    for (; ; )
    {
        if (i <= e)
        {
            if (i % 2 == 0)
                cout << i << ",";
        }
        else
            break;
        i++;
    }
   
 
}