/*
    Print Subarray 
*/

#include <iostream>
using namespace std; 

void printSubarrays(int *arr,int n){
    for (int  start = 0; start < n; start++){
        for (int end = start; end < n ; end++){
            // for index prints
            // cout << "(" << start << "," << end << ")  ";
            // for subarrays prints
            for (int i = start; i<end; i++){
                cout << arr[i];
            }
            cout << ", ";
        }
        cout << endl;
    }
}

int main(){

    int arr[] = {2,4,6,8,10,12,14,16,18,20};
    int n = sizeof(arr)/ sizeof(int);
    
    printSubarrays(arr, n);
   
    return 0;
}