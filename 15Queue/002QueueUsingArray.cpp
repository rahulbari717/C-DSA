#include<iostream>
using namespace std;

class Queue{
    int * arr;
    int capacity;
    int currSize;

    int f,r;
public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;

        f = 0; 
        r = -1;
    }

    void push(int data){
        if(currSize == capacity){
            cout << "Queue is Full\n";
            return;

        }
        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void pop(){
        if(empty()){
            cout << "Queue is Empty\n";
            return;
        }
        f = (f + 1) % capacity;
        currSize--;

    }

    int front(){
        if(empty()){
           cout << "Queue is Empty\n";
           return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }

    void printRear(){
        cout<< "Rear : " << arr[r] << endl;
    }
};

int main(){
    Queue q(4);
    q.printRear();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.printRear();
    cout<< "Front : " << q.front() << endl;
    q.pop();
    q.pop();
    cout<< "Front : " << q.front() << endl;
    q.printRear();
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    cout<< "Front : " << q.front() << endl;
    q.pop();
    q.pop();
    cout<< "Front : " << q.front() << endl; 
    q.printRear();
    return 0;
}