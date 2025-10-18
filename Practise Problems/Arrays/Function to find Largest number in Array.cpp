#include <iostream>
using namespace std;

int findlargest(int arr[] , int n){
    int largest = arr[0];
    for(int i=0; i<n ; i++){
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }

    return largest;
}
int main(){

    int arr[5] = {3,2,5,1,4};
    int n = sizeof(arr)/sizeof(int);
    cout <<"Largest of Array: " << findlargest(arr , n);

    return 0;
}