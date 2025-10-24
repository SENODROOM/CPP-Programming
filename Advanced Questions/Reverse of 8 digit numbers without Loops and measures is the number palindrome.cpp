#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout << "Enter a 8-digit number: ";
    cin >> num;

    int a, b, c, d, e, f, g, h;
    if (num > 9999999 && num < 100000000)
    {
        a = (num / 10000000) % 10;
        b = (num / 1000000) % 10;
        c = (num / 100000) % 10;
        d = (num / 10000) % 10;
        e = (num / 1000) % 10;
        f = (num / 100) % 10;
        g = (num / 10) % 10;
        h = num % 10;

        cout << "Reverse: ";
        cout << h << g << f << e << d << c << b << a << endl;

        int num2 = (h * 10000000) + (g * 1000000) + (f * 100000) + (e * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;
        
        if(num == num2){
            cout << "Number is a palindrome";
        }
    }

    return 0;
}
