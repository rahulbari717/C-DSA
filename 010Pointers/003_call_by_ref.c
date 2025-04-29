#include <stdio.h>  

void swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
    printf("x = %d, y = %d\n", *x, *y);
}

int main(){
    int a = 10, b = 20;

    printf("a = %d, b = %d\n", a, b);   
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b); 
    return 0;
}
