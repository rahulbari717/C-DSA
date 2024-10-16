/*
    Binary Search algoritham
*/

#include <iostream>
using namespace std; 

int binSearch(int *arr, int n, int key){
    int start = 0; int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end)/2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid+1;
        }
        else{
            end = mid -1;
        }
        
    }
    return -1;
}

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
    
    cout << binSearch(arr, n, 12);
    
    // printArray(arr, n);

    return 0;
}