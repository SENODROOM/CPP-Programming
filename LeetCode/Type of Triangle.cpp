#include <iostream>
using namespace std;

string TypeOfTri(int arr[])
{
    int a = arr[0], b = arr[1], c = arr[2];

    if (a + b <= c || a + c <= b || b + c <= a)
        return "Not a valid triangle";

    if (a == b && b == c)
        return "Equilateral";

    if (a == b || b == c || a == c)
        return "Isosceles";

    return "Scalene";
}

int main()
{
    int arr[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter side " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Type of Triangle: " << TypeOfTri(arr);

    return 0;
}
