/* keyword_extractor.c - Implementation of keyword extraction module */
#include "keyword_extractor.h"

#define INITIAL_CAPACITY 100
#define MAX_STOPWORDS 100
#define MAX_WORD_LENGTH 50

/* Array of common stopwords to filter out */
static const char* stopwords[] = {
    "a", "an", "the", "and", "or", "but", "is", "are", "was", "were", 
    "be", "been", "being", "have", "has", "had", "do", "does", "did",
    "can", "could", "will", "would", "shall", "should", "may", "might",
    "must", "to", "of", "in", "on", "at", "by", "for", "with", "about",
    "against", "between", "into", "through", "during", "before", "after",
    "above", "below", "from", "up", "down", "out", "off", "over", "under",
    "again", "further", "then", "once", "here", "there", "when", "where",
    "why", "how", "all", "any", "both", "each", "few", "more", "most",
    "other", "some", "such", "no", "nor", "not", "only", "own", "same",
    "so", "than", "too", "very", "s", "t", "just", "don", "now"
};

/* Function to check if a word is a stopword */
static int is_stopword(const char* word) {
    int num_stopwords = sizeof(stopwords) / sizeof(stopwords[0]);
    
    for (int i = 0; i < num_stopwords; i++) {
        if (strcmp(word, stopwords[i]) == 0) {
            return 1;
        }
    }
    
    return 0;
}

/* Function to convert a string to lowercase */
static void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

/* Function to check if a word already exists in the keyword list */
static int word_exists(KeywordList* list, const char* word) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->keywords[i].word, word) == 0) {
            return 1;
        }
    }
    
    return 0;
}

/* Function to extract keywords from job description */
KeywordList extract_keywords(const char* job_description) {
    KeywordList list;
    char *text_copy, *token, *saveptr;
    char word[MAX_WORD_LENGTH + 1];
    int word_len;
    
    // Initialize the keyword list
    list.capacity = INITIAL_CAPACITY;
    list.count = 0;
    list.keywords = malloc(list.capacity * sizeof(Keyword));
    
    if (!list.keywords) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Create a copy of the job description for tokenization
    text_copy = strdup(job_description);
    if (!text_copy) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(list.keywords);
        exit(EXIT_FAILURE);
    }
    
    // Split the text into words
    token = strtok_r(text_copy, " \t\n\r\f\v.,;:!?\"'()[]{}", &saveptr);
    
    while (token != NULL) {
        // Skip very short words and numbers
        word_len = strlen(token);
        if (word_len > 2 && word_len <= MAX_WORD_LENGTH && !(isdigit(token[0]))) {
            // Copy the word and convert to lowercase
            strncpy(word, token, MAX_WORD_LENGTH);
            word[MAX_WORD_LENGTH] = '\0';
            to_lowercase(word);
            
            // Skip stopwords and check if the word already exists
            if (!is_stopword(word) && !word_exists(&list, word)) {
                // Check if we need to expand the array
                if (list.count >= list.capacity) {
                    list.capacity *= 2;
                    list.keywords = realloc(list.keywords, list.capacity * sizeof(Keyword));
                    
                    if (!list.keywords) {
                        fprintf(stderr, "Error: Memory allocation failed\n");
                        free(text_copy);
                        exit(EXIT_FAILURE);
                    }
                }
                
                // Add the word to the list
                strcpy(list.keywords[list.count].word, word);
                list.keywords[list.count].importance = 1; // Default importance
                list.keywords[list.count].found = 0;      // Not found yet
                list.count++;
            }
        }
        
        // Get the next token
        token = strtok_r(NULL, " \t\n\r\f\v.,;:!?\"'()[]{}", &saveptr);
    }
    
    // Free the text copy
    free(text_copy);
    
    // Determine importance based on common technical skills and keywords
    const char* tech_skills[] = {
        "python", "java", "javascript", "c++", "c#", "ruby", "php", "html", "css",
        "sql", "mysql", "postgresql", "mongodb", "react", "angular", "vue", "node",
        "express", "django", "flask", "spring", "linux", "aws", "azure", "gcp",
        "docker", "kubernetes", "jenkins", "git", "agile", "scrum", "jira",
        "algorithm", "data", "structure", "analysis", "architecture", "design",
        "testing", "debugging", "implementation", "deployment", "maintenance"
    };
    
    int num_skills = sizeof(tech_skills) / sizeof(tech_skills[0]);
    
    for (int i = 0; i < list.count; i++) {
        for (int j = 0; j < num_skills; j++) {
            if (strcmp(list.keywords[i].word, tech_skills[j]) == 0) {
                list.keywords[i].importance = 3; // Higher importance for tech skills
                break;
            }
        }
    }
    
    return list;
}

/* Function to free memory used by the keyword list */
void free_keyword_list(KeywordList* list) {
    if (list && list->keywords) {
        free(list->keywords);
        list->keywords = NULL;
        list->count = 0;
        list->capacity = 0;
    }
}