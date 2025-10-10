// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, b, c, d, e;
//     cout << "Enter a number: ";
//     cin >> a;
//     cout << "Enter a number: ";
//     cin >> b;
//     cout << "Enter a number: ";
//     cin >> c;
//     cout << "Enter a number: ";
//     cin >> d;
//     cout << "Enter a number: ";
//     cin >> e;

//     int first, second, third, fourth, fifth;\

    
//     // Initialize all variables
//     first = a;
//     second = a;
//     third = a;
//     fourth = a;
//     fifth = a;

//     // Find first (largest)
//     if (b > first)
//     {
//         first = b;
//     }
//     if (c > first)
//     {
//         first = c;
//     }
//     if (d > first)
//     {
//         first = d;
//     }
//     if (e > first)
//     {
//         first = e;
//     }

//     // Find fifth (smallest)
//     fifth = a;
//     if (b < fifth)
//     {
//         fifth = b;
//     }
//     if (c < fifth)
//     {
//         fifth = c;
//     }
//     if (d < fifth)
//     {
//         fifth = d;
//     }
//     if (e < fifth)
//     {
//         fifth = e;
//     }

//     // Find second largest
//     second = fifth;
//     if (a > second && a < first)
//     {
//         second = a;
//     }
//     if (b > second && b < first)
//     {
//         second = b;
//     }
//     if (c > second && c < first)
//     {
//         second = c;
//     }
//     if (d > second && d < first)
//     {
//         second = d;
//     }
//     if (e > second && e < first)
//     {
//         second = e;
//     }

//     // Find fourth (second smallest)
//     fourth = second;
//     if (a < fourth && a > fifth)
//     {
//         fourth = a;
//     }
//     if (b < fourth && b > fifth)
//     {
//         fourth = b;
//     }
//     if (c < fourth && c > fifth)
//     {
//         fourth = c;
//     }
//     if (d < fourth && d > fifth)
//     {
//         fourth = d;
//     }
//     if (e < fourth && e > fifth)
//     {
//         fourth = e;
//     }

//     // Find third (middle value)
//     int total = a + b + c + d + e;
//     third = total - first - second - fourth - fifth;

//     cout << "Sorted in Ascending Order: " << endl;
//     cout << fifth << fourth << third << second << first << endl;
//     cout << "Sorted in Descending Order: " << endl;
//     cout << first << second << third << fourth << fifth << endl;

//     return 0;
// }


/*
    NOTE: This logic works well but
    there is a bug in it that if the 
    user enters identical numbers then
    it does not sort correctly.
*/







#include <iostream>
using namespace std;

int main() {
    int first, second, third, fourth, fifth;
    cout << "Enter a number: ";
    cin >> first;
    cout << "Enter a number: "; 
    cin >> second;
    cout << "Enter a number: "; 
    cin >> third;
    cout << "Enter a number: "; 
    cin >> fourth;
    cout << "Enter a number: "; 
    cin >> fifth;

    int temp;

    if (first > second) {
        temp = first; 
        first = second; 
        second = temp; 
    }
    if (first > third) { 
        temp = first; 
        first = third; 
        third = temp; 
    }
    if (first > fourth) { 
        temp = first; 
        first = fourth; 
        fourth = temp; 
    }
    if (first > fifth) { 
        temp = first; 
        first = fifth; 
        fifth = temp; 
    }

    if (second > third) { 
        temp = second; 
        second = third; 
        third = temp; 
    }
    if (second > fourth) { 
        temp = second; 
        second = fourth; 
        fourth = temp; 
    }
    if (second > fifth) { 
        temp = second; 
        second = fifth; 
        fifth = temp; 
    }

    if (third > fourth) { 
        temp = third; 
        third = fourth; 
        fourth = temp; 
    }
    if (third > fifth) { 
        temp = third; 
        third = fifth; 
        fifth = temp; 
    }

    if (fourth > fifth) { 
        temp = fourth; 
        fourth = fifth; 
        fifth = temp; 
    }

    cout << "Sorted in Ascending Order: "
         << first << " " << second << " " << third << " " << fourth << " " << fifth << endl;

    cout << "Sorted in Descending Order: "
         << fifth << " " << fourth << " " << third << " " << second << " " << first << endl;

    return 0;
}