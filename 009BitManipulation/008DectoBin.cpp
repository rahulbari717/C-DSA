#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void DecToBin(int n){
    int ans = 0;

    while(n>0){
        int rem = n%2;
        ans = ans*10 + rem;
        n = n/2;
    }
    cout << ans << endl;
}   

int main(){
    int n;
    cin >> n;

    DecToBin(n);

    return  0;
}