/*
    Max Subarray sum brute force 
*/

#include <iostream>
#include <limits.h>  // Include this header for INT_MIN
using namespace std; 

void maxSubarraySum1(int *arr, int n){
    // brute force aprroch
    int maxSum = INT_MIN;
    for (int  start = 0; start < n; start++){
        for (int end = start; end < n ; end++){
            int currSum = 0;
            for (int i = start;i<=end; i++){
                currSum += arr[i];
            }
            cout << currSum << ",";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
    }

    cout << "maximum subarray sum = " << maxSum <<endl;
}

void maxSubarraySum2(int *arr, int n){
    // optimized solution 
    int maxSum = INT_MIN;

    for (int  start = 0; start < n; start++){
        int currSum = 0;
        for (int end = start; end < n ; end++){
            currSum += arr[end];
            maxSum = max(maxSum, currSum);

        }
        cout << endl;
    }

    cout << "maximum subarray sum = " << maxSum <<endl;
}

void maxSubarraySum3(int *arr, int n){
    // Kadane's algoritham 
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i=0; i<n; i++){
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    cout << "maximum subarray sum = " << maxSum <<endl;
}

int main(){

    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/ sizeof(int);
    
    maxSubarraySum3(arr, n);
   
    return 0;
}