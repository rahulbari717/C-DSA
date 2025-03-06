#include <iostream>
using namespace std;

void CheckprimeNo(int n){
    bool isPrime=true;
    if(n == 0 || n == 1){
        isPrime=false;
    }
    for(int i=2;i*i<=n-1;i++){    
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
}

int main(){
    int n;
    
    cout<<"Enter number: ";
    cin>>n;

    CheckprimeNo(n);
    
    return 0;
}