#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  int type, price, number_of_cups, user, id = 1, sugar, cream, cappuccino = 250, espresso = 230, latte = 150, extra_sugar = 30, whipped_cream = 50;
  float tax = 0.2, total_price;
  do
  {
    cout << "\t\tFAST Hub\t\t" << endl;
    cout << "\t\t\"Menu\"" << endl;
    cout << "Coffee Name\tPrices\n";
    cout << "1.Cappuccino \tRs." << cappuccino << "\n";
    cout << "2.Espresso \tRs." << espresso << "\n";
    cout << "3.Latte \tRs." << latte << "\n";
    cout << "Extra Sugar \tRs." << extra_sugar << "\n";
    cout << "Extra Whipped Cream \tRs." << whipped_cream << "\n";
    cout << "Order:\n";
    cout << "Coffee number you want to order: ";
    cin >> type;
    if (type < 0 || (type != 1 && type != 2 && type != 3))
    {
      do
      {
        cout << "Invalid Entry\n";
        cout << "Coffee number you want to order :";
        cin >> type;
      } while (type < 0 || (type != 1 && type != 2 && type != 3));
    }
    cout << "Total number of coffee cups: ";
    cin >> number_of_cups;
    if (number_of_cups < 0)
    {
      do
      {
        cout << "Invalid Entry\n";
        cout << "Total number of coffee cups: ";
        cin >> number_of_cups;
      } while (number_of_cups < 0);
    }
    cout << "For extra sugar press 1 other wise enter 0: ";
    cin >> sugar;
    if (sugar != 0 && sugar != 1)
    {
      do
      {
        cout << "Invalid Entry\n";
        cout << "For extra sugar press 1 other wise enter 0: ";
        cin >> sugar;
      } while (sugar != 0 && sugar != 1);
    }
    cout << "For extra whipped cream press 0 other wise enter 1: ";
    cin >> cream;
    if (cream != 0 && cream != 1)
    {
      do
      {
        cout << "Invalid Entry\n";
        cout << "For extra  whipped cream enter 0 other wise enter 1: ";
        cin >> cream;

      } while (cream != 0 && cream != 1);
    }
    cout << "Billing:\n";
    cout << "Coustmer Id: " << id << endl;
    cout << "Product\t\tPrice\tQuantity\n";
    if (type == 1)
    {
      price = espresso;
      cout << "Espresso \tRs." << price << "\t " << number_of_cups << endl;
    }
    else if (type == 2)
    {
      price = cappuccino;
      cout << "Cappuccino \tRs." << price << "\t " << number_of_cups << endl;
    }
    else
    {
      price = latte;
      cout << "Latte \t\tRs." << price << "\t " << number_of_cups << endl;
    }
    if (sugar == 0)
    {
      price += extra_sugar;
      cout << "Extra Sugar \tRs." << extra_sugar << endl;
    }
    if (cream == 0)
    {
      price += whipped_cream;
      cout << "Whipped Cream \tRs." << whipped_cream << endl;
    }
    price = price * number_of_cups;
    total_price = price + (price * tax);
    cout << "Service Tax \tRs." << (price * tax) << endl;
    cout << "Total Price\tRs." << total_price << endl;
    cout << "For more order press 1 otherwise enter any key to exit: ";
    cin >> user;
    id++;
  } while (user == 1);
  return 0;
}