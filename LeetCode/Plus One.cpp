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
        cout << "Enter arr[" << i << "]" << ": ";
        cin >> arr[i];
    }
    if (arr[user - 1] == 9)
    {
        if (user == 1)
        {
            cout << "[1,0]";
        }
        else
        {
            cout<<"[";
            for (int i = 0; i < user; i++)
            {
                if (i < (user - 2))
                {
                    cout << arr[i] << ",";
                }
                else
                {
                    cout<<arr[user-2]+1<<",0";
                    break;
                }
            }
            cout<<"]";
        }
    }
    else
    {
        cout<<"[";
        for (int i = 0; i < user; i++)
        {
            if (i==user-1)
            {
                cout <<arr[i]+1;
            }else{
                cout <<arr[i]<<",";
            }
        }
        cout<<"]";
    }
}