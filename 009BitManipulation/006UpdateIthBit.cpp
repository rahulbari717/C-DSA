// update ith bit of position 

#include <iostream>
using namespace std;

int updateIthBit (int num, int i, int val){
    num = num & ~(1<<i); // clear the ith bit.
    num = num | (val << i);
    cout << num << endl;
}

int main(){
   //  cout << updateIthBit(7, 2, 0) << endl;
     cout << updateIthBit(7, 3, 1) << endl;
    return 0;
}