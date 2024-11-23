/*
Question: Print all binary strings of size n without consecutive 1's

*/
#include <iostream>
#include <string>
using namespace std;

void binnaryString(int n, int lastPlace, string ans) {
    if (n == 0) {
        cout << ans << endl;
        return;
    }

    if(lastPlace != 1){
        binnaryString(n-1, 0, ans + "0");
        binnaryString(n-1, 1, ans + "1");
    }
    else {
        binnaryString(n-1, 0, ans + "0");
    }
}

int main () {
    string ans = "";
    binnaryString(3, 0, ans);
    return 0;
}