#include <iostream>
using namespace std;
int main()
{
    int user;
    int arr[200];
    cout << "Enter the size of your array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr["<<i<<"]"<<": ";
        cin >> arr[i];
    }
    int find;
    cout << "Enter the target: ";
    cin >> find;
    bool check=true;
    for (int j = 0; j < user; j++)
    {
        if(arr[j]==find){
            cout<< j;
            check=false;
            break;
        }
        if (arr[j]>find)
        {
            cout<<j;
            check=false;
            break;
        }
    }
    if (check)
    {
        cout<<user;
    }
    
}