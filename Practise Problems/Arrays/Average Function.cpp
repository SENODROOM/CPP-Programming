#include <iostream>
using namespace std;
float findAvg(int arr[], int s)//by default by reference pass
{
    float avg,sum=0;
    for (int i = 0; i <= s - 1; i++)
    {
        sum += arr[i];
    }
    avg = sum / s;
    return avg;
}
int main(){
    int marks[] = { 13,5,4,6};
    int size=sizeof(marks) / sizeof(int);
    cout << "avg = " << findAvg(marks, size);
   
}