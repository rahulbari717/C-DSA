#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
    string color;
    
    void eat(){
        cout << "Eating..." << endl;
    }
    void sleep(){
        cout << "Sleeping..." << endl;
    }
    void breathe(){
        cout << "Breathing..." << endl;
    }
    
};

class Fish : public Animal {
public:
    int fins;

    void Swim(){
        cout << "Swimming..." << endl;
    }
};

int main(){
    Fish f1;
    f1.fins = 2;
    cout << f1.fins << endl;
    f1.eat();
    f1.Swim();
    return 0;
}