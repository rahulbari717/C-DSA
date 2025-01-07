/*
Question: Question3:BuildaSimpleInterestCalculator.
            Take the principal amount, rate of interest and time period from the user and 
            calculate the Simple Interest.
          
*/

#include<iostream>
using namespace std;

int main() {
    float principal, rate, time;
    cout<<"Enter Price of principal amount: \n"; 
    cin>>principal;
    cout<<"Enter Price of rate: \n";
    cin>>rate;
    cout<<"Enter Price of time: \n";
    cin>>time;
    cout<<"Simple Interest is: "<<(principal*rate*time)/100<<endl;

    return 0;
}