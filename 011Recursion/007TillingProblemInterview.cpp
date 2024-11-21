#include <iostream>
using namespace std;

int tillingProblem (int n){     // 2xn 
    if (n == 0 || n == 1) {
        return 1;
    }
    // vertical 
    int ans1 = tillingProblem(n-1);     // 2xn-1

    // horizontal
    int ans2 = tillingProblem(n-2);     // 2xn-2
    return ans1 + ans2;


}

int main () {
    int n = 3;
    cout << tillingProblem(n) <<endl;
    return 0;
}