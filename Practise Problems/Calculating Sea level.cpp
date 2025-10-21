#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
float  sea_lvl, new_lvl, change;
int key;
do{
cout << "\t----------Sea Level----------" << endl;
cout << "Enter current sea level in feets : " ;
cin >> sea_lvl;
if (sea_lvl < 0)
{
do {
cout << "Invalid....... \nEnter again : ";
cin >> sea_lvl;
} while (sea_lvl < 0);
}
new_lvl = (sea_lvl *2 *(0.015)) + sea_lvl;
cout << "Sea level after 2 years : " << new_lvl << endl;
change = new_lvl - sea_lvl;
cout <<"Increase in sea level is :" << change << endl;
cout<<"If you want to repeat press 1 and for exit press any key :";
cin>>key;}while (key == 1);
cout<<"\t----------End---------"<<endl;
return 0;
}