#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int user, count;
    cout << "\t----------Digit Counter----------" << endl;
    cout << "Enter digit : ";
    cin >> user;
    if (user < 0)
    {
        do
        {
            cout << "Enter Valid Input-------" << endl;
            cout << "Enter digit : ";
            cin >> user;
        } while (user < 0);
    }
    for (count = 0; user != 0; count++)
    {
        user = user / 10;
    }
    cout << "Total numbers of digit are \"" << count << "\"" << endl;
    cout << "\t ------------End------------" << endl;
    return 0;
}