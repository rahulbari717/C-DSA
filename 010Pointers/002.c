#include <stdio.h>

int main()
{
	int a = 10; 

	int *p;
	p = &a;

	printf("Value of a is ==> %d \n", a); 
	printf("Value of a is ==> %d \n", *p);	// dereferace operator used to get the value at given address
	
	
	printf("Address of a is ==> %p \n", &a);
	printf("Address of a is ==> %p \n", p);
	
	return 0; 
}
