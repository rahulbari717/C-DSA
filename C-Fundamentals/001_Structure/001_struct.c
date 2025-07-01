// Q) create a struct and print data 

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[50];
    int price;
    int model;
    char color[50];
    int speed; 

}car;

typedef struct
{
    int rollno;
    char name[50];
    int marks;
    int age;

}Student;

int main()
{
    car BMW = {
        .name = "BMW",
        .price = 10000,
        .model = 2022,
        .color = "Black",
        .speed = 200
    };

    Student rahul, yogesh; 

    rahul.rollno = 1;
    // rahul.name = "Rahul";
    strcpy(rahul.name, "Rahul");
    rahul.marks = 100;
    rahul.age = 20;
    
    yogesh.rollno = 2;
    // yogesh.name = "Yogesh";
    strcpy(yogesh.name, "Yogesh");
    yogesh.marks = 90;
    yogesh.age = 21;
    printf("Name: %s\n", rahul.name);   
    printf("Name: %s\n", yogesh.name);

    printf("Roll No: %d\n", rahul.rollno);
    printf("Roll No: %d\n", yogesh.rollno);

    printf("Marks: %d\n", rahul.marks);
    printf("Marks: %d\n", yogesh.marks);

    printf("Age: %d\n", rahul.age);
    printf("Age: %d\n", yogesh.age);

    printf("Name: %s\n", BMW.name);
    printf("Price: %d\n", BMW.price);
    printf("Model: %d\n", BMW.model);
    printf("Color: %s\n", BMW.color);
    printf("Speed: %d\n", BMW.speed);

    return 0;
}