#include <iostream>
using namespace std;
int main() {
    int num,d;
    cin >> num;
    (num % 2 == 0) ? (d=10,cout << "even" << endl, cout << "True case" << endl) :(d=20, cout << "odd" << endl, cout << "false case" << endl);
    cout << d;
    return 0;
}