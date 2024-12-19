#include <iostream>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

    Node (int val) {                // constructor
        data = val;
        next = NULL;
    }   

    ~Node() {                       // destructor
        // cout << "~Node () for data ==> " << data << endl;
        if (next != NULL){
            delete next;
            next = NULL;
        }
        // cout << "Deleting " << data << endl;
    }
};

class List {
public:
    Node* head;
    Node* tail;


    
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

    void printList() {
        cout << "printing list ... \n";
        Node * temp = head;
        while (temp != NULL) {
            cout << temp -> data << " ==> ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};


Node * splitAtMid(Node * head){
    Node * slow = head;
    Node * fast = head;
    Node * prev = NULL; 

    while (fast != NULL && fast-> next != NULL){
        prev = slow;
        slow = slow-> next;
        fast = fast -> next -> next;
    }

    if(prev != NULL){
        prev->next = NULL;          // split at middle 

    }
    return slow;        // slow = rightHead


}

Node * merge(Node * left, Node * right){
    List ans; 
    Node * i = left;
    Node * j = right;

    while(i != NULL && j !=NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i-> next;
        }else{
            ans.push_back(j->data);
            j = j-> next;
        }
    }

    while (i!= NULL){
        ans.push_back(i->data);
        i = i->next;
    }

    while (j!= NULL){
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head; 
}

Node * mergeSort(Node * head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node * left  = mergeSort(head);                // left head
    Node * right = mergeSort(rightHead);           // right head 

    return merge(left, right);
}




int main() {
    // cout << "Hello World!" << endl;
    List ll;

    ll.push_front(50);
    ll.push_front(40);
    ll.push_front(30);
    ll.push_front(20);
    ll.push_front(10);

    ll.printList();

    ll.head = mergeSort(ll.head);
    
    ll.printList();

    return 0;
}
