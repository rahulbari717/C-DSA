#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, i =0;
    int *i2;
    while(i<45545){
        printf("Welcome ...\n");
        i2 = (int *) malloc(344445555555 * sizeof(int));
        if(i%100 == 0){
            getchar();
        }
        i++;
        free(i2); // Without this we will see a memory leak of 344445555555 integers
    }

    return 0;

}