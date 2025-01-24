#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrom(char arr[], int len){
    int start = 0, end = len-1;
    while(start <=end){
        if(arr[start++]!= arr[end--]){ 
            cout << "not valid palindrom";
            return false;
        }
    }
    cout << "valid palindrom" <<endl;
    return true;
}

int main(){
    char word[]="racecar";
    isPalindrom(word, strlen(word));

    return 0;
}