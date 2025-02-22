#include <iostream>
using namespace std;

int main(){
    int n;          // size of array or length of array
    cout <<"Enter length of array : ";
    cin >> n;

    int arr[n]; 
    // input array 
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }

    // output array 
    for (int i=0;i<n;i++){
        cout << arr[i] << " ,";
    }
    cout <<endl;
    return 0;
}