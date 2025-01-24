/*
    In linear search go to each and every index and search key.
*/

#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int key){
    for(int i=0;i<n;i++){
        if (arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {2,4,6,8,10,12,14,16,18,20};
    int n = sizeof(arr)/ sizeof(int);
    
    cout << linearSearch(arr, n, 15) << endl;
    return 0;
}