/* pdf_parser.c - Implementation of PDF parsing module */
#include "pdf_parser.h"
#include <sys/stat.h>

#define TEMP_TXT_FILE "temp_resume_text.txt"
#define MAX_COMMAND_LEN 512

/* Function to extract text from a PDF file using pdftotext utility */
ResumeContent extract_text_from_pdf(const char* pdf_path) {
    ResumeContent content = {NULL, 0};
    FILE* txt_file;
    struct stat file_stat;
    char command[MAX_COMMAND_LEN];
    int status;
    
    // Build the command to convert PDF to text
    snprintf(command, MAX_COMMAND_LEN, "pdftotext -layout -nopgbrk \"%s\" %s", 
             pdf_path, TEMP_TXT_FILE);
    
    // Execute the command
    status = system(command);
    if (status != 0) {
        fprintf(stderr, "Error: pdftotext command failed with status %d\n", status);
        fprintf(stderr, "Make sure pdftotext (poppler-utils) is installed on your system.\n");
        fprintf(stderr, "Install with: sudo apt-get install poppler-utils (Ubuntu/Debian)\n");
        exit(EXIT_FAILURE);
    }
    
    // Get the size of the text file
    if (stat(TEMP_TXT_FILE, &file_stat) != 0) {
        fprintf(stderr, "Error: Cannot access converted text file\n");
        exit(EXIT_FAILURE);
    }
    
    // Allocate memory for the text content
    content.text = malloc(file_stat.st_size + 1);
    if (!content.text) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Open and read the text file
    txt_file = fopen(TEMP_TXT_FILE, "r");
    if (!txt_file) {
        fprintf(stderr, "Error: Cannot open converted text file\n");
        free(content.text);
        exit(EXIT_FAILURE);
    }
    
    // Read the entire file
    content.size = fread(content.text, 1, file_stat.st_size, txt_file);
    content.text[content.size] = '\0';
    
    // Close and remove the temporary file
    fclose(txt_file);
    remove(TEMP_TXT_FILE);
    
    return content;
}
