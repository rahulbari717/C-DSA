#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpan(vector<int> stock, vector<int> &span) {
    stack<int> s;
    s.push(0); 
    span[0] = 1;

    for (int i = 1; i < stock.size(); i++) {
        int currentPrice = stock[i];
        while (!s.empty() && currentPrice >= stock[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            // If stack is empty, span is the entire range up to the current day
            span[i] = i + 1;
        } else {
            // Top of the stack gives the index of the previous higher price
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
        s.push(i);
    }

    // Print the spans (Optional, depending on requirement)
    for (int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};

    stockSpan(stock, span);
    return 0;
}
