#include <iostream>
using namespace std;

int main(){
    int arr [] = {2,5,7,3,9};
    int n = sizeof(arr) / sizeof(int); 

    int max = arr[0]; 
    int min = arr[0]; 
    
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i]; 
            cout << "assigning value to max " << arr[i] << endl; 
        }
         if(arr[i] < min){
            min = arr[i]; 
            cout << "assigning value to min " << arr[i] << endl; 
        }
    }
    
    cout << "max = " << max <<endl; 
    cout << "min = " << min <<endl; 
    return 0;
}   
