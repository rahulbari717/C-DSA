/**
 * File: astronaut.h
 * Description: Header file for astronaut structure and functions
 * Author: Rahul Bari
 * Date: April 29, 2025
 */

 #ifndef SMMCS_ASTRONAUT_H
 #define SMMCS_ASTRONAUT_H
  
 /* Macros and Preprocessor Directives */
 #define MAX_NAME_LENGTH 50
 #define MAX_ID_LENGTH 10
 #define MAX_SPECIALIZATION_LENGTH 100
 
 /* Enumeration for Roles */
 typedef enum {
     ROLE_PILOT = 1,
     ROLE_SCIENTIST = 2
 } AstronautRole;
  
 /* Structure and Union Definitions */
 typedef struct {
     char name[MAX_NAME_LENGTH];    /* Astronaut's name */
     int age;                       /* Astronaut's age */
     char id[MAX_ID_LENGTH];        /* Unique identifier (e.g., A001) */
     AstronautRole role;            /* Using enum for role */
     
     /* Union for role-specific details - Memory Management optimization */
     union {
         int flightHours;                         /* For Pilots */
         char specialization[MAX_SPECIALIZATION_LENGTH];  /* For Scientists */
     } roleDetails;
 } Astronaut;
  
 /* Function prototypes */
 Astronaut* allocateAstronautMemory(int count);
 void getAstronautDetails(Astronaut** astronauts, int* count);
 void displayAllAstronauts(Astronaut* astronauts, int count);
 void searchAstronauts(Astronaut* astronauts, int count);
 void searchAstronautById(Astronaut* astronauts, int count);
 void searchAstronautByName(Astronaut* astronauts, int count);
 void searchAstronautByRole(Astronaut* astronauts, int count);
 void freeAstronautMemory(Astronaut* astronauts);
 
 /* New validation function prototypes */
 int isValidID(const char* id);
  
 #endif /* SMMCS_ASTRONAUT_H */