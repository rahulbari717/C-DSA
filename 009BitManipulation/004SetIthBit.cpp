// Set ith bit of position 

#include <iostream>
using namespace std;

int SetIthBit (int num, int i){
    int bitMask = 1 << i;
    return (num | bitMask);
}

int main(){
    cout << SetIthBit(6, 3) << endl;
    cout << SetIthBit(7, 5) << endl;
    return 0;
}