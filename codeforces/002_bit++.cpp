#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkstatement(string statement){
    // increment = true, decrement = false
    if(statement == "++X" || statement == "X++"){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;      // number of statements 
    cin>>n;

    int x = 0;  // x is the variable
    
    for(int i=0; i<n; i++){
        string statements;
        cin>>statements;

        if(checkstatement(statements)){
            x++;
        }
        else{
            x--;
        }
    }
    cout<<x<<endl;

    return 0;
}