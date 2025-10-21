#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int integer ,  count = 0 ;
	cout << "\t----------Divisible by 3 and 5----------" << endl;
	do {
	cout << "Enter number ( to stop enter -999) : ";
	cin >> integer;
	if (integer % 5 == 0 && integer % 3 == 0)
	{
	count++;
	}

	} while (integer != -999);

	cout << "Numbers divisible by 3 and 5 = \"" << count <<"\"" << endl;
	cout << "\t ------------End------------" << endl;
	return 0;
}