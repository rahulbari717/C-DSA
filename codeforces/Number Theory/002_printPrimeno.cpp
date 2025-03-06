#include <iostream>
using namespace std;

bool CheckprimeNo(int n){
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
        // cout<<"Prime Number"<<endl;
        return true;
    }else{
        // cout<<"Not Prime Number"<<endl;
        return false;
    }
}

int main(){
    int n;
    
    cout<<"Enter number: ";
    cin>>n;

    for(int i=0;i<=n; i++){
        if(CheckprimeNo(i)){
            cout<<i <<" ";
        }
    }
        
    return 0;
}