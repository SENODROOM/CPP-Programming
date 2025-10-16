#include <iostream>
using namespace std;
void printsum(int marks[], int s)//by default by reference pass
{
    int sum = 0;
    for (int i = 0; i <= s - 1; i++)
    {
        sum=sum+marks[i];
        marks[i]++;
    }
    cout << sum << endl;
}
int main(){
   
    int marks[] = { 4,5,6};
    int size=sizeof(marks) / sizeof(int);
    cout << size << endl;
    int copy[3];
    for (int i = 0; i < size; i++)
    {
        copy[i] = marks[i];
    }
    printsum(copy, size);
    for (int i = 0; i <=size - 1; i++)
    {
        cout << copy[i] << endl;
    }
   
}