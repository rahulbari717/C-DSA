// Problem Statement: This program calculates the number of ways to tile a 2xn rectangle using 1x2 dominoes.
// Given an integer n, representing the length of the rectangle, the function tillingProblem(n) is called
// to compute the total number of distinct arrangements of the dominoes.

#include <iostream>
using namespace std;

int tillingProblem (int n){             // 2xn 
    if (n == 0 || n == 1) {
        return 1;
    }
    
    return tillingProblem(n-1) + tillingProblem(n-2);
 }

int main () {
    
    int n = 3;
    cout << tillingProblem(n) <<endl;
    return 0;
}