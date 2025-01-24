#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string st1, string st2){
    if (st1.length()!= st2.length()){
        cout << "not valid anagram";
        return false;
    }

    int count[26] = {0};
    for (int i=0;i<st1.length();i++){
        int idx = st1[i] - 'a';
        count[idx]++;
    }

    for (int i=0;i<st2.length();i++){
        int idx = st2[i] - 'a';
        if (count[idx]==0){
            cout << "not valid anagram";
            return false;
        }
        count[idx]--;
    }
    cout << "valid anagram";
    return true;
}

int main(){
    string str1 = "anagram";
    string str2 = "nagaram";

    isAnagram(str1, str2);
    return 0;
} 