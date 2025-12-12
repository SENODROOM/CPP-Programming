#include <iostream>
using namespace std;
void swap(int arr[], int user, int num)
{
    int newnum = user - (user % num);
    for (int i = 0; i < newnum; i = i + num)
    {
        int left = 0;
        int right = num - 1;
        do
        {
            int temp;
            temp = arr[left + i];
            arr[left + i] = arr[i + (right)];
            arr[i + (right)] = temp;
            left++;
            right--;
        } while (left < right);
    }

    cout << "[";
    for (int i = 0; i < user; i++)
    {
        cout << arr[i];
        if (i != user - 1)
            cout << ",";
    }
    cout << "]";
}
int main()
{
    int arr[100];
    int user, num;
    cout << "Enter total elements: ";
    cin >> user;
    cout << "Enter pair : ";
    cin >> num;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter element no " << i + 1 << ": ";
        cin >> arr[i];
    }
    swap(arr, user, num);
}