/*
Question: Print the sum of the using while loop.
*/

#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter number: ";
    cin>>n;

    int sum=0, lastDigit;
    while(n>0) {
        lastDigit = n%10;
        cout<<lastDigit<<" ";
        // if(lastDigit%2!=0) {     // if only odd digit sum is required
        //     cout<<"Odd"<<endl;
        //     sum += lastDigit;
        // }
        sum += lastDigit;
        n = n/10;
    }
    cout<<"Sum of digits is: "<<sum<<endl;
    return 0;
}