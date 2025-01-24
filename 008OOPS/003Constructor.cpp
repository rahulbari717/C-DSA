#include<iostream>
#include<string>
using namespace std;

class Car {
    // Properties 
    string name;
    string color;

public:
    Car (){
        cout << "Constructor is called. object being created ...\n " << endl;
    }

    Car (string name, string color){
        cout << "Constructor is called. object being created ...\n " << endl;
        this->name = name;
        this->color = color;

    }

    void start(){
        cout << "Car is started ...\n " << endl;
    }
    void stop(){
        cout << "Car is stopped ...\n " << endl;
    }

    // void setName(string nameVal){
    //     name = nameVal;
    // }
    string getName(){
        return name;
    }
};


int main(){
    // Car c1;

    Car car1("BMW", "Black");

    cout << "car name : " << car1.getName() << endl;
   
    
    return 0;
}