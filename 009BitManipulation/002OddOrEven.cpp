#include <iostream>
using namespace std;

void oddOrEven(int num){
    if (!(num & 1)){
        cout << "Even no. \n ";
    }
    else{
        cout << "Odd no. \n";
    }
}

int main(){
    oddOrEven(0);
    oddOrEven(1);
    oddOrEven(2);
    oddOrEven(3);
    oddOrEven(4);
    oddOrEven(5);
    oddOrEven(6);

    return 0;
}