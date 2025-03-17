#include <iostream>
#include <bits/stdc++.h>    
using namespace std;

int search(vector<int>& nums, int target) {
    int i =0;
    int j = nums.size()-1;

    while(i<=j){
        int mid = i+(j-i)/2;
        if(nums[mid]==target) return mid;
        else if(target>nums[mid]) i = mid+1;
        else j = mid-1; 
    }
    return -1; 
}

// lowerbound codes 

class Solution {
    public:
        int lowerBoud(vector<int>& nums, int n, int target) {
            int i=0;
            int j= nums.size()-1;
    
            int ans = n;
    
            while(i<=j){
                int mid = i+(j-i)/2;
                if(nums[mid]>=target) {
                    ans = min(ans, mid);
                    j = mid -1;         // left
                } 
                else {
                    i = mid+1;          // right
                }
            }
            return ans; 
        }
        int searchInsert(vector<int>& nums, int target) {
            int n = nums.size(); 
    
            int lb = lowerBoud(nums, n, target);
            return lb; 
        }
    };


int main(){

    int n; 
    cin >> n;

    vector <int> vec1 (n);

    for(int i=0; i<n; i++){
        cin >> vec1[i];
    }

    int target;
    cin >> target;

    
    return 0;
}