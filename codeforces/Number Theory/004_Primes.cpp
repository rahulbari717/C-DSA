#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool CheckPrimeNo(int n){
    if(n == 0 || n == 1) return false;

    for(int i=2;i*i<=n;i++){    
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    // cout<<"Enter number: ";
    cin>>n;

  if(CheckPrimeNo(n-2)){
        cout<<"2 "<<n-2 <<endl;
    }else{
        cout<<"-1"<<endl;
    }
    return 0;
}