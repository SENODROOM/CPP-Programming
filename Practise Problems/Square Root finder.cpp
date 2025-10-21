#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int num = 1;
    cout << "Square roots of the first 25 odd positive integers:" << endl;
    while (count < 25) {
        double x = num;
        double y = 1;   
        double eps = 0.00001; 

        while (x - y > eps) {
            x = (x + y) / 2;
            y = num / x;
        }

        cout << "√(" << num << ") = " << x << endl;

        num += 2; 
        count++;
    }
    return 0;
}