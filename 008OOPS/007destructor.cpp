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

    ~Car(){
        cout << "Destructor is called. object being deleted ...\n " << endl;
        if(milege != NULL){     
            delete milege;
            milege = NULL;  
        }
    }
};

int main(){
    Car c1("BMW", "Black");

    cout << c1.name << endl;
    cout << c1.color << endl;
    cout << *c1.milege << endl;

    return 0;
}