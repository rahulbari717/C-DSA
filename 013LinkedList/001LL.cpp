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

    ~Node() {                   // destructor
        // cout << "~Node () for data ==> " << data << endl;
        if (next != NULL){
            delete next;
            next = NULL;
        }
        // cout << "Deleting " << data << endl;
    }
};

class List {
    
    Node* head;
    Node* tail;

public:
    
    List() {                // constructor  
        head = NULL;
        tail = NULL;
    }

    ~List (){               // destructor
        // cout << "~List ()\n ";
        if(head != NULL) {
            delete head;
            head = NULL;
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

    void pop_back() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node * temp = head;
        while (temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    void insert (int val, int pos){
        Node * newNode = new Node(val);
        Node * temp = head;
        for (int i=0;i<pos-1;i++){
            if (temp == NULL) {
                cout << "Invalid Position\n";
                return;
            }
            temp = temp -> next;
        }
        // temp is now at pos-1 i.e the node before the pos
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
  
    int searchItr (int key){
        Node * temp = head;
        int idx = 0;

        while (temp != NULL) {
            if (temp -> data == key) {
                cout << "Found at index " << idx << endl;
                return idx;
            }
            temp = temp -> next;
            idx++;
        }
        cout << "Not Found\n";
        return -1;
    }  

    int helper(Node * temp, int key){
        
        if (temp == NULL) {
            return -1;
        }
        if(temp ->data == key){
            return 0;
        }

        int idx = helper(temp -> next, key);

        if (idx == -1) {
            return -1;
        }
        return idx + 1;

    }

    int searchRec (int key){

        return helper(head, key);
    }

    void printList() {
        Node * temp = head;
        while (temp != NULL) {
            cout << temp -> data << " ==> ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};

int main() {
    // cout << "Hello World!" << endl;
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(10);

    ll.printList();

    // ll.pop_front();  
    // ll.pop_back();
    // ll.insert(100, 2);
    // ll.insert(100, 25);
    // cout << ll.searchItr(2) << endl;
    // ll.printList();
    // cout << ll.searchItr(100) << endl;

    // ll.printList();

    // cout << ll.searchRec(4) << endl;

    return 0;
}
