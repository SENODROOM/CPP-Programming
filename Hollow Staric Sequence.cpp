#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int num;
    cout<<"\t--------Pattern---------"<<endl;
    cout<<"Enter number : ";
    cin>>num;

    if (num < 0) {
        do{
        cout << "Invalid input! Please enter a non-negative number." << endl;
        cin>> num;
        }while(num < 0);
    } 
    for (int i = 1 ; i <= num ; i ++)
    {
        if( i == 1 || i == num)
        {
            for(int j = 1 ; j <= num ; j ++)
            cout<<"*";
        cout<<"\n";
        }
        if (i != 1 && i != num){
            for(int k = 1 ; k <= 2 ; k++)
            {
                cout<<"*";
                for(int l = 1 ; l < (num-1) ; l++)
                 cout<<" ";
               
            }
            cout<<"\n";
        }
    }
}