#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char word[],int len){

    for(int i=0;i<len;i++){
        char ch = word[i];
        if(ch>='A' && ch<='Z'){ // nothing to do.
            continue;
        }
        else{   // lowercase
            word[i] = ch - 'a'+'A';
        }
    }
}
int main(){
    char word[] = "apPle";
    toUpper(word, strlen(word));
    cout << word <<endl;
    return 0;
}