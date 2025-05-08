/* keyword_extractor.h - Header for keyword extraction module */
#ifndef KEYWORD_EXTRACTOR_H
#define KEYWORD_EXTRACTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char word[50];
    int importance;  // 1-3, where 3 is highest importance
    int found;       // Boolean flag
} Keyword;

typedef struct {
    Keyword* keywords;
    int count;
    int capacity;
} KeywordList;

/* Function to extract keywords from job description */
KeywordList extract_keywords(const char* job_description);

/* Function to free memory used by the keyword list */
void free_keyword_list(KeywordList* list);

#endif /* KEYWORD_EXTRACTOR_H */