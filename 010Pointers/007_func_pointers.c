#include <stdio.h>

/*
Notes : 

🔹 What is a Function Pointer?
A function pointer is a variable that can store the address of a function, 
just like how an int* stores the address of an int.

So instead of calling sum() directly, you can call it via its address using a 
pointer to the function.

*/



int sum(int a, int b) {
    return a + b;
}

int main() {

    // Function pointer
    int (*func_ptr)(int, int);

    // Point it to the sum function
    func_ptr = &sum;                // creating a function pointer  
    int a = (*func_ptr)(5, 3);      // (deref value) calling the function via the pointer

    printf("Sum is: %d\n", a);      // 
    return 0;
}
