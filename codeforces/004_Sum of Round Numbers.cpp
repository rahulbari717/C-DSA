#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> rounds;
    vector<int> v = {10,100,1000,10000,100000};

    for(auto & it:v){
        if(n%it != 0){
            rounds.push_back(n%it);
            n -= (n%it);
        }
    }
    cout<<rounds.size()<<endl;
    for(auto & it:rounds){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}