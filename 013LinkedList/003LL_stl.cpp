#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList (list<int> ll) {
    list <int> :: iterator itr;

    for (itr = ll.begin(); itr != ll.end(); itr++) {
        cout << (*itr)  << " --> ";
    }
    cout << "NULL" <<endl;
}

int main(){

    list<int> ll;       

    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_back(40);
    ll.push_back(50);

    printList(ll);
    // cout << "Size of LL : " << ll.size()<<endl;
    //cout << "Head  : " << ll.front() << endl;
    //cout << "Tail  : " << ll.back() << endl;

    return 0;
}