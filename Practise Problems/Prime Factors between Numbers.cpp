#include<iostream>
#include<iomanip>
using namespace std;

bool primeCheck(int num, bool check) 
{
    if (num < 2)
        return check = false;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return check = false;
        }
    }
    return check = true;
}

int main()
{
    int N;
    bool check = true;

    cout << "\t--------Prime Numbers Finder---------" << endl;
    cout << "Enter an integer N: ";
    cin >> N;

    if (N < 2) {
        do{
        cout << "No prime numbers exist below 2." << endl;
        }while(N <2);
    } 
    
        cout << "Prime numbers from 1 to " << N << " are: ";
        for (int i = 2; i <= N; i++) {
            if (primeCheck(i, check))
                cout << i << " ";
        }
    

    cout << "\n\t---------End---------";
    return 0;
}
