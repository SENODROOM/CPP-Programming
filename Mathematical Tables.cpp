#include <iostream>
#include<iomanip>
using namespace std;
int main() {
    int s, e, n;
    cin >> s >> e >> n;
    while (s <= e)
    {
        cout <<setw(3)<< n << "x" <<setw(3) <<s << "=" <<setw(5)<< n * s << endl;
        s++;
    }
}