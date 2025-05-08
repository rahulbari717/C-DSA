/* pdf_parser.h - Header for PDF parsing module */
#ifndef PDF_PARSER_H
#define PDF_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* text;
    size_t size;
} ResumeContent;

/* Function to extract text from a PDF file */
ResumeContent extract_text_from_pdf(const char* pdf_path);

#endif /* PDF_PARSER_H */