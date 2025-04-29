/*
   What is a Union in C
    - Unions are a user defined data types in C
    - The difference between structure and union is that in structure, 
        each member has its own storage location, 
        but in union, all members share the same storage location.
*/

#include <stdio.h>
#include <string.h>

// typedef struct Student {
//     int id; 
//     int marks;
//     char fav_char;
//     char name[34];
// }s1; 

typedef union Student {
    int id; 
    int marks;
    char fav_char;
    char name[34];
}s1; 

int main(){

    s1 student;
    student.id = 1;
    student.marks = 45;
    student.fav_char = 'u';
    strcpy(student.name, "rahul");
    
    printf("Student ID: %d\n", student.id);
    printf("Student Marks: %d\n", student.marks);
    printf("Student Favorite Character: %c\n", student.fav_char);
    printf("Student Name: %s\n", student.name);    
    return 0; 
}