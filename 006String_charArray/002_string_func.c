#include <stdio.h>
#include <string.h>

void reverseStr(char *str) {
   int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

int main(){
    char str1[100] = "Hello rahul how are you ?";
    char str2[] = "rahul";
    char str3[] = "yogesh";

    // puts(strcat(str2, str3));
    // printf("%s \n", str2); 
    // printf("The length of str2 is %d \n", strlen(str2));
    // printf("The length of str2 is %d \n", strlen(str3));
    printf("The reverse of str2 is : ");
    reverseStr(str2);
    puts(str2); 
    return 0;
}

