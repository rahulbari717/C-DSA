#include <iostream>
#include <vector>
using namespace std;

int firstOccur (vector<int> arr, int i, int target) {

    if (i == arr.size()) {
        return -1;
    }

    if(arr[i] == target) {
        return i;
    }

    return firstOccur(arr, i+1, target);
}

int lastOccur (vector<int> arr, int i, int target){
    if(i == arr.size()){
        return -1;
    }

    int idxFound = lastOccur(arr, i+1, target);

    if(idxFound == -1 && arr[i] == target){
        return i;
    }

    return idxFound;
}

int main() {
    
    vector<int> arr = {1,2,3,4,5,3,7,8,9,10};
    cout << firstOccur(arr, 0, 3) << endl;
    cout << lastOccur(arr, 0, 3) << endl;
    return 0;
}  
