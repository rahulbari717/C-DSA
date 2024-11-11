/*
 * main.c
 *
 *  Created on: Oct 25, 2024
 *      Author: Rahul B.
 */
#include <stdio.h>
#include <stdint.h>

struct carModel
{
    uint32_t carNumber;
    uint32_t carPrice;
    uint16_t carMaxSpeed;
    float carWeight;
};

int main(){
	
    struct carModel carBMW = {2021,15000,220,1330}; 
    struct carModel carFord = {.carMaxSpeed = 400,.carNumber = 500};

    // printf("\n Details of car BMW as follows \n");
    // printf("carNumber = %u\n",carBMW.carNumber);

    printf("size of struct carModel us %lu \n ", sizeof(carBMW));

	printf("Press 'Enter' to exit this application");
	getchar();
	return 0;
}