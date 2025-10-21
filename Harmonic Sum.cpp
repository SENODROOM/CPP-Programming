#include<iostream>
#include<iomanip>
using namespace std;

float harmonicSum(int N) 
{
    float sum = 0;
    for (float i = 1; i <= N; i++) {
        sum =  sum +(1 / i);
    }
    return sum;
}

int main()
{
    int N;
    float result;

    cout << "\t--------Harmonic Sum Calculator---------" << endl;
    cout << "Enter a number: ";
    cin >> N;

    if (N <= 0) {
        do{
        cout << "Invalid input! Please enter a positive integer." << endl;
        cin>> N;
        }while( N<= 0);
    } 
    
        result = harmonicSum(N);
       
        cout << "Sum = " << result << endl;
    

    cout << "\t---------End---------";
    return 0;
}