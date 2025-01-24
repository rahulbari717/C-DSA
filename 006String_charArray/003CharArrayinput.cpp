#include <iostream>
#include <string.h>

using namespace std;

int main(){
    
    // char word[30]; 
    // cin >> word;

    // cout << "your word was : " << word << endl;
    // cout << "length : " << strlen(word) << endl;

    char sentence[30];
    cin.getline(sentence,30,'r');

    cout << "your word was : " << sentence << endl;
    cout << "length : " << strlen(sentence) << endl;

    return 0;
}
