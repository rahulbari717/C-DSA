#include <stdio.h>  


void printStr(char str[]){

    int i=0; 
    while(str[i] != '\0'){
        printf("%c", str[i]);
        i++;

    }

}

int main(){
    char str[100] = "Hello this is a string";

    printf("%s", str);
    printf("\n");
    printStr(str); 

    return 0; 
}