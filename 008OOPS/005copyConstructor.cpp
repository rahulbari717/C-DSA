#include<iostream>
#include<string>
using namespace std;

class Car {
    public:
        string name;
        string color;

    Car (string name, string color){
        cout << "Constructor is called. object being created ...\n " << endl;
        this->name = name;
        this->color = color;
    }

    Car (Car &original){
        cout << "Copying original to new... \n " << endl;
        this->name = original.name;
        this->color = original.color;

    }
};

int main(){
    Car c1("BMW", "Black");

    Car c2(c1);

    cout << c2.name << endl;
    cout << c2.color << endl;

    return 0;
}