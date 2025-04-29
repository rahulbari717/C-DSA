/**
 * File: fileio.c
 * Description: Implementation of file I/O operations
 * Author: Your Name
 * Date: April 29, 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fileio.h"

/**
 * Exports astronaut data to text and PDF-like formatted text file
 * File Handling in C
 * @param astronauts Array of astronauts
 * @param count Number of astronauts
 */
void exportAstronautData(Astronaut *astronauts, int count)
{
    FILE *txtFile, *pdfFile;
    time_t currentTime;
    char timestamp[300];
    char txtFilename[500];
    char pdfFilename[500];

    /* Get current time for filename */
    time(&currentTime);
    strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", localtime(&currentTime));

    /* Create filenames with timestamp */
    snprintf(txtFilename, sizeof(txtFilename), "astronaut_data_%s.txt", timestamp);

    snprintf(pdfFilename, sizeof(pdfFilename), "astronaut_report_%s.txt", timestamp);
    /* PDF-like formatted text */

    /* Open files for writing - File I/O operations */
    txtFile = fopen(txtFilename, "w");
    if (txtFile == NULL)
    {
        fprintf(stderr, "Error: Could not create export file %s\n", txtFilename);
        return;
    }

    pdfFile = fopen(pdfFilename, "w");
    if (pdfFile == NULL)
    {
        fprintf(stderr, "Error: Could not create report file %s\n", pdfFilename);
        fclose(txtFile); /* Clean up first file */
        return;
    }

    /* Write data to text file - Simple format */
    fprintf(txtFile, "ASTRONAUT DATA EXPORT\n");
    fprintf(txtFile, "Generated: %s\n\n", ctime(&currentTime));
    fprintf(txtFile, "Total Astronauts: %d\n\n", count);

    for (int i = 0; i < count; i++)
    {
        fprintf(txtFile, "--- Astronaut %d ---\n", i + 1);
        fprintf(txtFile, "ID: %s\n", astronauts[i].id);
        fprintf(txtFile, "Name: %s\n", astronauts[i].name);
        fprintf(txtFile, "Age: %d\n", astronauts[i].age);

        if (astronauts[i].role == ROLE_PILOT)
        {
            fprintf(txtFile, "Role: Pilot\n");
            fprintf(txtFile, "Flight Hours: %d\n", astronauts[i].roleDetails.flightHours);
        }
        else
        {
            fprintf(txtFile, "Role: Scientist\n");
            fprintf(txtFile, "Specialization: %s\n", astronauts[i].roleDetails.specialization);
        }
        fprintf(txtFile, "\n");
    }

    /* Write data to PDF-like formatted text file */
    fprintf(pdfFile, "================================================\n");
    fprintf(pdfFile, "          SPACE MISSION CREW REPORT             \n");
    fprintf(pdfFile, "================================================\n\n");
    fprintf(pdfFile, "Generated: %s\n", ctime(&currentTime));
    fprintf(pdfFile, "Total Crew Members: %d\n\n", count);

    /* Stats section using bit manipulation for counting */
    int pilotCount = 0;
    int scientistCount = 0;
    int totalFlightHours = 0;

    for (int i = 0; i < count; i++)
    {
        pilotCount += (astronauts[i].role == ROLE_PILOT) ? 1 : 0; /* Bit operation equivalent */
        scientistCount += (astronauts[i].role == ROLE_SCIENTIST) ? 1 : 0;

        if (astronauts[i].role == ROLE_PILOT)
        {
            totalFlightHours += astronauts[i].roleDetails.flightHours;
        }
    }

    fprintf(pdfFile, "CREW STATISTICS:\n");
    fprintf(pdfFile, "-----------------\n");
    fprintf(pdfFile, "Pilots: %d (%.1f%%)\n", pilotCount, (float)pilotCount / count * 100);
    fprintf(pdfFile, "Scientists: %d (%.1f%%)\n", scientistCount, (float)scientistCount / count * 100);
    fprintf(pdfFile, "Average Pilot Flight Hours: %.1f\n\n", pilotCount > 0 ? (float)totalFlightHours / pilotCount : 0);

    /* Table header - Create a formatted table for the PDF-like output */
    fprintf(pdfFile, "CREW ROSTER:\n");
    fprintf(pdfFile, "-----------------------------------------------------------------\n");
    fprintf(pdfFile, "| %-6s | %-20s | %-3s | %-10s | %-15s |\n", "ID", "NAME", "AGE", "ROLE", "DETAILS");
    fprintf(pdfFile, "-----------------------------------------------------------------\n");

    /* Print each astronaut as a row in the table */
    for (int i = 0; i < count; i++)
    {
        char details[30] = {0}; /* Buffer for role-specific details */
        char roleStr[15] = {0}; /* Buffer for role string */

        /* Determine role string and details */
        if (astronauts[i].role == ROLE_PILOT)
        {
            strcpy(roleStr, "Pilot");
            sprintf(details, "%d hours", astronauts[i].roleDetails.flightHours);
        }
        else
        {
            strcpy(roleStr, "Scientist");
            /* Truncate specialization if too long for display */
            if (strlen(astronauts[i].roleDetails.specialization) > 15)
            {
                strncpy(details, astronauts[i].roleDetails.specialization, 12);
                strcat(details, "...");
            }
            else
            {
                strcpy(details, astronauts[i].roleDetails.specialization);
            }
        }

        /* Print formatted row */
        fprintf(pdfFile, "| %-6s | %-20s | %-3d | %-10s | %-15s |\n",
                astronauts[i].id,
                astronauts[i].name,
                astronauts[i].age,
                roleStr,
                details);
    }

    fprintf(pdfFile, "-----------------------------------------------------------------\n\n");

    /* Add mission readiness assessment - Advanced report section */
    fprintf(pdfFile, "MISSION READINESS ASSESSMENT:\n");
    fprintf(pdfFile, "----------------------------\n");

    /* Calculate mission readiness based on crew composition */
    int missionReady = 1;                /* Boolean flag for mission readiness */
    char readinessNotes[3][100] = {{0}}; /* Array to store readiness notes */
    int noteCount = 0;                   /* Counter for notes */

    /* Check minimum requirements for mission */
    if (pilotCount < 1)
    {
        missionReady = 0;
        strcpy(readinessNotes[noteCount++], "CRITICAL: At least one pilot required");
    }

    if (scientistCount < 1)
    {
        missionReady = 0;
        strcpy(readinessNotes[noteCount++], "CRITICAL: At least one scientist required");
    }

    if (count < 3)
    {
        missionReady = 0;
        strcpy(readinessNotes[noteCount++], "WARNING: Recommended minimum crew size is 3");
    }

    /* Print readiness status */
    fprintf(pdfFile, "Status: %s\n\n", missionReady ? "READY" : "NOT READY");

    /* Print any readiness notes */
    if (noteCount > 0)
    {
        fprintf(pdfFile, "Notes:\n");
        for (int i = 0; i < noteCount; i++)
        {
            fprintf(pdfFile, "- %s\n", readinessNotes[i]);
        }
    }
    else
    {
        fprintf(pdfFile, "All mission requirements satisfied.\n");
    }

    /* Add document footer */
    fprintf(pdfFile, "\n================================================\n");
    fprintf(pdfFile, "              END OF REPORT                     \n");
    fprintf(pdfFile, "================================================\n");

    /* Clean up - close file handles */
    fclose(txtFile);
    fclose(pdfFile);

    printf("Export complete. Files created:\n");
    printf("1. %s (Raw Data)\n", txtFilename);
    printf("2. %s (Formatted Report)\n", pdfFilename);
}