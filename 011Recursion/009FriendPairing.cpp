/*
Q) find total ways in which n friends can remain single or can be paired up.
   Each friend can be paired only once.
   
   f(n) ==> single or pair 
   if 
*/

#include <iostream>
using namespace std;

int friendPairing(int n) {
    if (n == 1 || n == 2) {
        return n;
    }

    return friendPairing(n-1) + (n-1) * friendPairing(n-2);
}

int main (){
    int n = 4;
    cout << friendPairing(n) << endl;
    return 0;
}
