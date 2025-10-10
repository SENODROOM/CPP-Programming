#include <iostream>
using namespace std;
int main() {
    int f=0, s=1,sum,num;
    cin >> num;
    cout << f << "," << s << ",";
    for(int i=3;i <= num; i++)
    {
        sum = f + s;
        cout << sum << ",";
        f = s;
        s = sum;
    }
}