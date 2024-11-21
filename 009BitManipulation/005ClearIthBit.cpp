// Clear ith bit of position 

#include <iostream>
using namespace std;

int ClearIthBit (int num, int i){
    int bitMask = ~(1 << i);
    return (num & bitMask); 
}

int main(){
    cout << ClearIthBit(6, 1) << endl;
    
    return 0;
}