#include<iostream>
#include<string>
using namespace std;

class Car {
    public:
        string name;
        string color;
        int *milege;

    Car (string name, string color){
        cout << "Constructor is called. object being created ...\n " << endl;
        this->name = name;
        this->color = color;
        milege = new int;       // Dynamic memory allocation
        *milege = 12;
    }

    Car (Car &original){
        cout << "Copying original to new... \n " << endl;
        this->name = original.name;
        this->color = original.color;
        
        // deep copy    
        milege = new int;
        *milege = *original.milege;

    }
};

int main(){
    Car c1("BMW", "Black");

    Car c2(c1);

    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.milege << endl;

    *c2.milege = 10;

    cout << *c1.milege << endl;
    return 0;
}