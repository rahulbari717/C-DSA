#include <iostream>
using namespace std;

int main(){
    int n;
    bool isPrime=true;
    cout<<"Enter number: ";
    cin>>n;

    for(int i=2;i<=n-1;i++){
        if(n%i==0){
            isPrime=false;
            break;
        }
    }
    if(isPrime){
        cout<<"Prime Number"<<endl;
    }else{
        cout<<"Not Prime Number"<<endl;
    }
    return 0;
}