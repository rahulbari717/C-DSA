#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << left << setw(5) << "Dec" << setw(25) << "Char" << setw(5) << "Dec" << setw(25) << "Char" 
         << setw(5) << "Dec" << setw(25) << "Char" << setw(5) << "Dec" << setw(25) << "Char" << endl;
    cout << string(92, '-') << endl; // Separator line

    for (int i = 0; i < 128; i++) {
        if (i < 32) {
            // Print non-printable characters as descriptions
            cout << left << setw(5) << i << setw(25) << "N/A" << flush; // Placeholder for non-printable characters
        } else {
            // Print printable characters normally
            cout << left << setw(5) << i << setw(25) << (char)i;
        }

        // Print every 32 characters in a row
        if ((i + 1) % 32 == 0) {
            cout << endl;
        }
    }

    // Print remaining characters if not a complete row
    if (128 % 32 != 0) {
        cout << endl;
    }

    return 0;
}
