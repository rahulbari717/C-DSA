/*
Notes:
    - Dynamic memory allocation is a way in which the size of a data structure can be
    changed during runtime.
    - Dynamic memory allocation is done using the malloc(), calloc(), realloc() and free() functions.

    Memory assinged to a program in a typical architecture can be broken down into four segments:
    1. Code : This segment contains the program instructions.
    2. Static/global variables : This segment contains the global variables.
        data segment and bss segment
        data segment contains the initialized global variables and static variables.
        bss segment contains the uninitialized global variables and static variables.

    3. Heap: This segment contains the memory that is allocated during runtime. (dynamic memory allocation)
    4. Stack: This segment contains the local variables.

    We have four functions to deal with dynamic memory allocation:
    1. malloc() : This function allocates a block of memory of the specified size and returns a pointer
        to the beginning of the block.
    2. calloc() : This function allocates a block of memory of the specified size and initializes all bytes
        in the block to zero.
    3. realloc() : This function changes the size of the memory block pointed to by ptr.
    4. free() : This function frees the memory block pointed to by ptr.


    malloc() : stands for memory allocation.
    - It reserves a block of memory with the given amount of bytes.
    - The return value is a void pointer to the allocated space.
    - therefore the void pointer needs to be casted to the appropriate type as per the requirement.
    - However, the memory is insufficient, then the function returns a NULL pointer.
    - All the values are initialized to garbage values.

    syntax :
        ptr = (ptr_type*) malloc(size_in_bytes);


    calloc() : stands for contiguous allocation.
    - It reserves n blocks of memory of the specified size and initializes all bytes in the block to zero.
    - All the values are initialized to 0 values.

    syntax :
        ptr = (ptr_type*) calloc(n, size_in_bytes);

    realloc() : stands for reallocation.
    - It changes the size of the memory block pointed to by ptr.

    syntax :
        ptr = (ptr_type*) realloc(ptr, size_in_bytes);

    free() : stands for free.
    - It frees the memory block pointed to by ptr.

    syntax :
        free(ptr);

*/
// Dynamic Memory Allocation
/*
ABC pvt ltd. manages employee records of other companies.
The employee id can be of any length employees id as input you have to take employee id as an
input and as output print.abort

store the employee id in a character array which is dynamically allocate memory to store the
you have to create only one character array dynamically.

Example:
 Employee 1 :
 Enter no. of characters in your EID
 45
 Dynamic Memory allocation for character array
 take input from user

 Employee 2 :
 Enter no. of characters in your EID
 4
 Dynamic Memory allocation for character array
 take input from user


 print all the above mentioned character arrays
*/

#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for Employee ID
char *allocateEID(int length)
{
    char *eid = (char *)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    if (eid == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    return eid;
}

// Function to input Employee ID
void inputEID(char *eid)
{
    scanf("%s", eid);
}

// Function to display Employee ID
void displayEID(const char *eid)
{
    printf("The entered EID is: %s\n", eid);
}

int main()
{
    int numEmployees, length;
    char *eid; // Single pointer for one employee at a time

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    for (int i = 0; i < numEmployees; i++)
    {
        printf("\nEmployee %d:\n", i + 1);

        printf("Enter the number of characters in your EID: ");
        scanf("%d", &length);

        // Allocate memory
        eid = allocateEID(length);

        printf("Enter your EID: ");
        inputEID(eid);

        // Display the EID
        displayEID(eid);

        // Free allocated memory
        free(eid);
    }

    return 0;
}
