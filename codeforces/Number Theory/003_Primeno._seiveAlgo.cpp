/*
    Sieve of Eratosthenes : calculate prime numbers upto a given number
*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<bool> seive(int n){
    vector <bool> prime(n+1,true);
    
    prime[0]=false;
    prime[1]=false;

    for(int i=2;i*i<=n;i++){            // 2 to sqrt(n) 
        if(prime[i]==true){             // if true then make all multiple of i false
            for(int j=i*i;j<=n;j+=i){   // starting from i*i because numbers before i*i will be already marked by some other number
                prime[j]=false;         //  numbers before i*i will be already marked by some other number
            }
        }
    }
    return prime;   
}    

int main(){

    int n;
    cout<<"Enter number: ";
    cin>>n;

    vector<bool> prime = seive(n);

    for(int i=1;i<=n;i++){
        if(prime[i]){
            cout<<i <<"Prime Number"<<endl;
        }else{
            cout<<i <<"Not Prime Number"<<endl;
        }

    }

    return 0;
}