#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int data){
    // base case
    if(s.empty()){
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s, data);
    s.push(temp);
    return;

}



int main(){
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    
    pushAtBottom(s, 4);
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}