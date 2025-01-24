/*
    Selection sort algoritham
    smallest element ko sort karna hai
*/

#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 4, 1, 3, 2, 4, 3, 7};
    sort(arr, arr+8);
    printArray(arr,8);
    return 0;
}