#include <iostream>
using namespace std;

int main(){
    int n; 
    int arr[n]; 
    cout << "Enter size of array \n"; 
    cin >> n;
    
    // int n = sizeof(arr) / sizeof(int)
    for(int i=0; i<n; i++){
        cout << "Enter each element of array ==> \n"; 
        cin >> arr[i]; 
    }

    // output
    for(int i=0; i<n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl; 

    return 0;
}   
