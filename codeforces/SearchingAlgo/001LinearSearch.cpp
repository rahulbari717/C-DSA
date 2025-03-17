#include <iostream>
#include <bits/stdc++.h>    
using namespace std;
// Linear Search O(n) time complexity.

int linearSearch(int n, vector <int> &arr, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){

    int n; 
    cin >> n;

    vector <int> vec1 (n);

    for(int i=0; i<n; i++){
        cin >> vec1[i];
    }

    int target;
    cin >> target;

    cout << linearSearch(n, vec1, target) << endl;

    return 0;
}