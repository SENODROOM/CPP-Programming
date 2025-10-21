#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    double n, x, fact = 1, pow = 1;
    float sum = 1, frac;
    cout << "x = ";
    cin >> x;
    cout << "n = ";
    cin >> n;

    cout << "1";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            fact = fact * j;
        }
        for (int k = 1; k <= i; k++)
        {
            pow = x * pow;
        }
        frac = ((pow) / fact);
        sum = sum + frac;
        cout << "+" <<(pow) << "/" << fact;
        pow = 1;
        fact = 1;
    }
    sum =sum -1;
    cout << " = " << fixed << sum;
    return 0;
}


// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     int x;
//     cout << "x = ";
//     cin >> x;

//     int n;
//     cout << "n = ";
//     cin >> n;
//     n= n-1;

//     double sum = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         double value = 1;
//         for (int j = 1; j <=i ; j++)
//         {
//             value = value*x;
//         }
//         double fact = 1;
//         for (int k = 1; k <= i; k++)
//         {
//             fact = fact * k;
//         }
//         sum = sum + (value/fact);
//     }
//     cout << sum;
// }

// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main()
// {
//     int x, n;
//     cout << "x = ";
//     cin >> x;
//     cout << "n = ";
//     cin >> n;

//     double sum = 1.0; // start with 1

//     for (int i = 1; i <= n - 1; i++) // go only up to n-1
//     {
//         double power = 1.0;
//         for (int j = 1; j <= i; j++)
//         {
//             power *= x; // compute x^i
//         }

//         double fact = 1.0;
//         for (int k = 1; k <= i; k++)
//         {
//             fact *= k; // compute i!
//         }

//         sum += power / fact;
//     }

//     cout << fixed << setprecision(4);
//     cout << "Sum = " << sum << endl;

//     return 0;
// }

