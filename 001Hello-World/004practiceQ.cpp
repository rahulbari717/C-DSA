/*
Question: Enter cost of 3 items from the user(usingfloatdatatype) -
          a pencil, a pen and an eraser.
          You have to output the total cost of the items back to the 
          user as their bill.

          (Addon:You can also try adding 18% GST tax to the items in the bill as an advanced problem)
*/

#include<iostream>
using namespace std;

int main() {
    float pencil, pen, eraser;
    cout<<"Enter Price of pencil: ";
    cin>>pencil;
    cout<<"Enter Price of pen: ";
    cin>>pen;
    cout<<"Enter Price of eraser: ";
    cin>>eraser;
    cout<<"Total cost is: "<<pencil+pen+eraser<<endl;
    
    // Addon:
    float total = pencil+pen+eraser;
    cout<<"Total cost after GST tax: "<<total+(total*0.18)<<endl;
    return 0;
}