#include <stdio.h>

int printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("The value at %d is %d \n", i, arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, size);  
    return 0;


}