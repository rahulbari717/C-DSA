/*
Question: In a program, input the side of a square. You have to output the area 
            of the square.

            (Hint: area of a square is (side x side))
*/

#include<iostream>
using namespace std;

int main() {
    int side;
    cout<<"Enter side of square: ";
    cin>>side;
    cout<<"Area of square is: "<<side*side<<endl;
    return 0;
}