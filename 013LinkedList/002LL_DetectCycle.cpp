#include <iostream>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

    Node (int val) {            // constructor
        data = val;
        next = NULL;
    }   

};

class List {
public:   
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front (int val){
        // to create a new node

        Node * newNode = new Node(val);   

        // new is used because its allocating memory dynamically after 
        // funcrtion call its still existing

        if (head == NULL) {
            head = tail = newNode;

        }else {
            newNode -> next = head;
            head = newNode;
        }
    }

    void push_back (int val){
        Node * newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }
        Node * temp = head;
        head = head -> next;

        temp -> next = NULL;
        delete temp;
    }

    void printList( Node * head) {
        Node * temp = head;
        while (temp != NULL) {
            cout << temp -> data << " ==> ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};

bool isCycle(Node * head){
    Node * slow = head;
    Node * fast = head;

    while (fast != NULL and fast -> next != NULL) {
        slow = slow -> next;                //  +1
        fast = fast -> next -> next;        // +2 

        if (slow == fast) {
            cout << "Cycle is present ...\n";
            return true;
        }
    }
    cout << "Cycle is not present ...\n";
    return false;
}

int main(){
    List ll;

    ll.push_front(10);
    ll.push_front(9);
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // ll.tail -> next = ll.head;
    isCycle(ll.head);
    return 0;
}