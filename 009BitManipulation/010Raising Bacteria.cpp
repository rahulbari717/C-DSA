/*
    A. Raising Bacteria
time limit per test1 second
memory limit per test256 megabytes
You are a lover of bacteria. You want to raise some bacteria in a box.

Initially, the box is empty. Each morning, you can put any number of bacteria into the box. And each night, every bacterium in the box will split into two bacteria. You hope to see exactly x bacteria in the box at some moment.

What is the minimum number of bacteria you need to put into the box across those days?

Input
The only line containing one integer x (1 ≤ x ≤ 109).

Output
The only line containing one integer: the answer.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long countSetBits(long long n){
    long long count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;

}

int main(){
    long long x;
    cin >>x; 
    cout << countSetBits(x) << endl;
    return 0; 
}