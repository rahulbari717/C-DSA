/*
Q) write a program to find all subsets of a given set
Input: "abc" 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printSubsets (string str, string subset){

    if (str.size() == 0){
        cout << subset << "\n";
        return;
    }
    char ch = str[0];

    // yes choice 
    printSubsets(str.substr(1, str.size()-1), subset+ch);
    // no choice
    printSubsets(str.substr(1, str.size()-1), subset);
}

int main (){
    string str = "abc";
    string subset = "";

    printSubsets(str, subset);

    return 0;
}