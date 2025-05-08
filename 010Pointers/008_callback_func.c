#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

void greetHello(){
    printf("Hello user ...\n");
}

void greetGoodbye(int (*fptr)(int, int)){
    greetHello();
    printf("Sum is: %d\n", (*fptr)(5, 3));   
    printf("Goodbye user ...\n");
}

int main(){


    int (*func_ptr)(int, int);  
    func_ptr = &sum;
    greetGoodbye(func_ptr);

    return 0;
}