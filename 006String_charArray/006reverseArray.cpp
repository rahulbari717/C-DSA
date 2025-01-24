#include <iostream>
#include <cstring>
using namespace std;

void reverse(char arr[], int len){
    int start = 0, end = len-1;
    while(start <=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main(){
    char word[]="rahul";
    reverse(word, strlen(word));

    cout << "reverse = " << word << endl;
    return 0;
}