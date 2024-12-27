#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string str){
    string ans = "";
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }

    while (!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

}

int main(){
    string str = "Hello World";
    cout << "reverse string = "<<reverseString(str) << endl;
    return 0;
}