// count no. of 1's.  
// num = 10 ==> 0000 1010 ==> 2 

#include <iostream>
using namespace std;

int countSetBits (int num){
    int count = 0;
    while (num > 0){
        int lastDig = num & 1;
        count += lastDig;
        num = num >> 1;
    }
    cout << count << endl; 
    return count; 
}

int main(){
    countSetBits(10);
    return 0;
}