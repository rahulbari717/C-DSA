#include <iostream>
using namespace std;

int main(){
    int arr[] = {7,5,6,9,12};
    int max = arr[0];
    int min = arr[0];
    int n = sizeof(arr) / sizeof(int);
    for (int i=0; i<n; i++)
    {
        if ( arr[i] > max)
        {
            max = arr [i];
            // cout << "assigning value "<< max << " to max \n";
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }      
    }
    
    cout << "large no. of array is ==> " << max << endl;
    cout << "small no. of array is ==> " << min << endl;
    return 0;
}