#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 128; i++) {  // Changed the condition to i < 128
        cout << "ASCII value: " << i << ", Character: " << (char)i << endl;
    }
    cout << endl;
    return 0;
}