#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    long long arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    long long ans = 0;
    ans += arr[n-1];
    long long int mx = arr[n-1]-1;
    for(int i=n-2; i>=0; i--){
        ans += min(arr[i], mx);
        mx = min(arr[i], mx)-1;
        if(mx <= 0){
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}