#include <iostream>
using namespace std;

int main(){
    // Bitwise AND Operator
    cout << (3 & 5) <<endl; // 011 & 101 = 001 = 1 
    // Bitwise OR Operator
    cout << (3 | 5) <<endl; // 011 | 101 = 111 = 7
    // Bitwise XOR Operator // if same 0; diff = 1;
    cout << (3 ^ 5) <<endl; // 011 ^ 101 = 110 = 6

    // One's compliment ==> not operator ~ 
    cout << (~6) <<endl;    // (~110) = 001 = 6 ==> ans is -7 below is explaination.
    
    // 6 dec = 0000 0110 = (~) 
    // ==> (1111 1001) this is 1's complement
    // (1111 1001) msb is 1 so its -ve,  remaining 7 bit is magnitude
    // 1's complement (1111 1001) ==> (~) ==> 0000 0110 
    // 2's cmplent (0000 0110) +1 ==> 7

    cout << (~0) <<endl;//  ==> -1 

    // Binrary shift Operator 
    // left shift    <<
    cout << (7 << 2) <<endl; // 0000 0111 ==>  0001 1100 ==> 28 
    // a<<b ==> a*2^b.

    // right shift   >>
    cout << (7 >> 2) <<endl; // 0000 0111 ==>  0000 0001 ==> 1
    // a>>b ==> a/2^b.
    
    return 0;
}

// Q) Output of (~4)? ==> 0000 0100 ==> 1111 1011 (-ve) ==> 0000 0100 1's complent +1 ==> -5 

// Q) Output of 8 >> 1 ? ==> 0000 1000 ==> 0000 0100==> 4 