/*
    Queue is a linear data structure which follows a particular order in which the operations
    are performed.
    The order is First In First Out (FIFO).
    Queue implementation using linked list

*/

#include <iostream>
using namespace std;

class Node{ 
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node * head;
    Node * tail;
public:
    Queue(){
        head =  tail = NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(empty()){
            cout << "Queue is Empty\n";
            return;

        }
        Node * temp = head;
        head = head->next;
        delete temp;

    }

    int front(){
        if(empty()){
            cout << "Queue is Empty\n";
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }

};

int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;        
}