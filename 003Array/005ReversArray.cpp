/*
    Reverse an array.
    2) without extra space.
*/

#include <iostream>
using namespace std; 

void printArray(int *arr,int n){
    for (int  i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}

int main(){

    int arr[] = {2,4,6,8,10,12,14,16,18,20};
    int n = sizeof(arr)/ sizeof(int);
    
    int start = 0, end = n-1;

    while (start < end)
    {
/*         int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp; */
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    
    printArray(arr, n);

    return 0;
}