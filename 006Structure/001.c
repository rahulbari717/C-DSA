/*
   What is a Structure in C
    - Structures are a user defined data types in C
    - It allows to combine data of different types toggether.
    - It is used to create a complex data type which contains diverse information.
    - They are similar to array but structure can store any type of data.

    - Syntax:
        struct structure_name {
            data_type member1;
            data_type member2;
            ...
        };
*/

#include <stdio.h>
#include <string.h>

// Define a structure
struct Student {
    int rollNo;
    float marks;
    char name[50];
};

int main() {
    // Declare a structure variable
    struct Student rahul, harry, rohan;
    
    // Initialize structure members
    rahul.rollNo = 1;
    harry.rollNo = 2;
    rohan.rollNo = 3;

    rahul.marks = 95.5;
    harry.marks = 88.0;
    rohan.marks = 92.5;

    strcpy(rahul.name, "Rahul Bari");
    strcpy(harry.name, "Harry Potter");


    printf("rahul got %.2f marks \n", rahul.marks); 
    printf("harry got %.2f marks \n", harry.marks);
    printf("rohan got %.2f marks \n", rohan.marks);

    printf("rahul's name is %s \n", rahul.name);
    printf("harry's name is %s \n", harry.name);
    
    
    return 0;
}
