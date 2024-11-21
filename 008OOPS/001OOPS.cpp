/**
 * Defines a `Student` class with properties for name and CGPA, and a method to calculate the percentage.
 * 
 * The `Student` class is used to represent a student with a name and CGPA (Cumulative Grade Point Average).
 * The `getPercentage()` method calculates and prints the percentage based on the CGPA.
 * 
 * Example usage:
 * 
 * Student s1;
 * s1.name = "Rahul";
 * s1.cgpa = 9.5;
 * s1.getPercentage(); // Prints "Percentage is : 95"
 * 
 */

#include<iostream>
using namespace std;

class Student{
public:
    // Properties 
    string name;
    float cgpa;
    
    // methods 
    void getPercentage(){
        cout<<"Percentage is : "<<(cgpa*10);
    }
};

int main(){
    Student s1; // object
    // cout<< sizeof(s1) <<endl;

    s1.name = "Rahul";
    cout<<s1.name<<endl;
    
    s1.cgpa = 9.5;
    s1.getPercentage();

    return 0;
}