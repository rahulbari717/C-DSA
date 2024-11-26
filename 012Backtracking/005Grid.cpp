/*
Question: find no. of ways to reach from (0,0) to (m-1, n-1) in a m x n grid
allowed moves: right and down

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gridWays (int r, int c, int n, int m){

    if (r == n-1 && c == m-1){  // reached destination based case.
        return 1;
    }

    if (r >= n || c >= m){
        return 0;
    }


    // right 
    int val1 = gridWays(r, c+1, n, m);
    // down 
    int val2 = gridWays(r+1, c, n, m);

    return val1 + val2;
}

int main (){
    int n = 3;
    int m = 3;      // 3x3 matrix 

    cout << gridWays(0, 0, n, m) << endl;

    return 0;

}