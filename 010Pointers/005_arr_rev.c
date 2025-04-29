#include <stdio.h>

// to do : reverse the array    

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("The value at %d is %d \n", i, arr[i]);
    }
    printf("\n");
    return; 
}

void arrayReverse(int arr[], int size){
    int temp;
    for(int i=0; i < size/2; i++){
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
    return ; 
}

int main(){
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Before reversing the array \n");
    printArray(arr, len);

    arrayReverse(arr, len);
    printf("After reversing the array \n");
    printArray(arr, len);


    return 0;
}