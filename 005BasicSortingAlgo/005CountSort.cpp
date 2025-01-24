#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int arr[], int n){
    int freq[100000];       //range
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i=0; i<n; i++){
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    // step 1 
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    // step 2
    for(int i=minVal, j=0; i<=maxVal; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
        // freq[i] += freq[i-1];
    }

}

int main(){
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    printArray(arr, 8);
    countSort(arr, 8);
    printArray(arr, 8);
    return 0;
}