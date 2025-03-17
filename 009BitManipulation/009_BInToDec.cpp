
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void BinToDec(int n) {
    int ans = 0;
    int power = 0;
    
    while(n > 0) {
        int rem = n % 10;
        ans += rem * pow(2, power);
        power++;
        n = n / 10;
    }
    
    cout << ans << endl;
}

int main(){
    int n;
    cin >> n;
    BinToDec(n);
    return  0;
}