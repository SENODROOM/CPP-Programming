#include <iostream>
using namespace std;
int search(int arr[], int s,int element)//linear
{
    int index=-1;
    for (int i = 0; i < s; i++)
    {
        if (element == arr[i]) {
            index = i;
            break;
        }
    }
    return index;
}
int main(){
    int marks[] = { 13,5,4,6};//{6,4,5,13}
    int size=sizeof(marks) / sizeof(int);
    int flag = search(marks, size, 14);
    if (flag != -1)
        cout << "Found at index " << flag << endl;
    else
        cout << "Not found";

   
}