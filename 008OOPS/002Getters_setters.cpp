
#include<iostream>
#include<string>
using namespace std;

class Student{
    // Properties 
    string name;
    float cgpa;

public:
    // methods 
    void getPercentage(){
        cout<<"Percentage is : "<<(cgpa*10);
    }

    // setters
    void setName(string nameVal){
        name = nameVal;
    }

    void setCGPA(float cgpaVal){
        cgpa = cgpaVal;
    }

    // getters
    string getName(){
        return name;
    }

    float getCGPA(){
        return cgpa;
    }

};

int main(){
    Student s1; // object
    // cout<< sizeof(s1) <<endl;

    s1.setName("Rahul");
    s1.setCGPA(9.5);

    cout << s1.getName() << endl;
    cout << s1.getCGPA() << endl;
    
    return 0;
}