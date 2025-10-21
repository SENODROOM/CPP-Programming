#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double price, discount, total_price, user, total_discount;
	cout << "\t----------Discount Calculation on Basis of Price-----------" << endl;
	do{
	cout << "Enter price of your product: ";
	cin >> price;
	if (price < 0)
	{
	do
	{
	cout << "Enter Valid Input-------" << endl;
	cout << "Enter price of your product: ";
	cin >> price;
	} while (price < 0);
	}
	if (price < 100){
	discount = 0.05;
	}
	else if (price >= 100 && price <= 500)
	{
	discount = 0.1;
	}
	else
	{
	discount = 0.15;

	}

	total_discount = (price * discount);
	total_price = total_discount + price;
	cout << "\t\t \"Total Price\"" << endl;
	cout << "Price= $" << price << endl;
	cout << "Discount = $" << total_discount << endl;
	cout << "Total_price= $" << total_price << endl;
	cout << "If you want to quit  enter -1 otherwise enter any character : ";

	cin >> user;
	} while (user != -1);
	cout << "\t----------End----------"<<endl;
	return 0;
}