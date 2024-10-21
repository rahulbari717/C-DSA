#include <iostream>
#include <cstring>
using namespace std;

void toLower(char word[],int len){

    for(int i=0;i<len;i++){
        char ch = word[i];

        if (ch >= 'A' && ch <= 'Z') { // Check if the character is uppercase
            word[i] = ch + ('a' - 'A'); // Convert to lowercase
        }
    }
}
int main(){
    char word[] = "APPLE";
    toLower(word, strlen(word));
    cout << word <<endl;
    return 0;
}