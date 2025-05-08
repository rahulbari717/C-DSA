/* main.c - Main program for ATS Resume Matcher */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "pdf_parser.h"
#include "keyword_extractor.h"
#include "matcher.h"

#define MAX_JOB_DESCRIPTION 10000
#define MAX_PATH_LENGTH 256

void print_welcome_message() {
    printf("\n");
    printf("*******************************************\n");
    printf("*     ATS RESUME MATCHER - PHASE 1       *\n");
    printf("*******************************************\n");
    printf("This program analyzes your resume against a job description\n");
    printf("to determine how well it matches the requirements.\n");
    printf("\n");
}

void print_instructions() {
    printf("Instructions:\n");
    printf("1. Enter the path to your resume (PDF format)\n");
    printf("2. Enter or paste the job description\n");
    printf("3. View your match results\n");
    printf("\n");
}

char* get_resume_path() {
    char* resume_path = malloc(MAX_PATH_LENGTH);
    if (!resume_path) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the path to your resume (PDF format): ");
    if (fgets(resume_path, MAX_PATH_LENGTH, stdin) == NULL) {
        free(resume_path);
        fprintf(stderr, "Error reading input\n");
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline
    size_t len = strlen(resume_path);
    if (len > 0 && resume_path[len-1] == '\n') {
        resume_path[len-1] = '\0';
    }

    // Validate that file exists and is accessible
    if (access(resume_path, R_OK) != 0) {
        fprintf(stderr, "Error: Cannot access resume file at '%s'\n", resume_path);
        free(resume_path);
        exit(EXIT_FAILURE);
    }

    return resume_path;
}

char* get_job_description() {
    char* job_description = malloc(MAX_JOB_DESCRIPTION);
    if (!job_description) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter or paste the job description (press Ctrl+D on a new line when finished):\n");
    
    char buffer[1024];
    job_description[0] = '\0';
    
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Check if we would exceed the buffer size
        if (strlen(job_description) + strlen(buffer) >= MAX_JOB_DESCRIPTION - 1) {
            fprintf(stderr, "Warning: Job description too long, truncating.\n");
            break;
        }
        strcat(job_description, buffer);
    }
    
    // Clear the EOF state if Ctrl+D was pressed
    clearerr(stdin);
    
    return job_description;
}

int main() {
    print_welcome_message();
    print_instructions();
    
    // Get resume path
    char* resume_path = get_resume_path();
    
    // Get job description
    char* job_description = get_job_description();
    
    // Extract text from PDF
    printf("\nExtracting text from resume...\n");
    ResumeContent resume_content = extract_text_from_pdf(resume_path);
    
    // Extract keywords from job description
    printf("Analyzing job description...\n");
    KeywordList keywords = extract_keywords(job_description);
    
    // Match keywords against resume
    printf("Matching resume against job requirements...\n");
    MatchResult result = match_keywords(&keywords, &resume_content);
    
    // Calculate and display results
    calculate_match_score(&result);
    determine_match_level(&result);
    display_match_results(&result);
    
    // Clean up
    free(resume_path);
    free(job_description);
    free(resume_content.text);
    free_keyword_list(&keywords);
    
    printf("\nThank you for using ATS Resume Matcher!\n");
    
    return 0;
}