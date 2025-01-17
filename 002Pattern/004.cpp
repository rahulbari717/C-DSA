/*
Question:   
    1
    23
    456
    78910

*/

#include<iostream>
using namespace std;

int main(){

    int n;
    int num = 1;
    cout<<"Enter number: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num++ << " ";
        }
        cout<<endl;
    }
    return 0;
}