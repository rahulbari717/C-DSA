#include <iostream>
using namespace std;

int fibonacci (int n){
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main () {
    cout << fibonacci(1) << endl;
    cout << fibonacci(2) << endl;   
    cout << fibonacci(3) << endl;
    cout << fibonacci(4) << endl;
    cout << fibonacci(5) << endl;
    cout << fibonacci(6) << endl;
    cout << fibonacci(7) << endl;
    cout << fibonacci(8) << endl;
    return 0;
}