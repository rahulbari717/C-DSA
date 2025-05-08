/* matcher.c - Implementation of matching module */
#include "matcher.h"

/* Function to check if a keyword exists in the resume text */
static int keyword_exists_in_resume(const char* keyword, const ResumeContent* resume) {
    char* resume_text_lower;
    char* keyword_lower;
    int result = 0;
    
    // Convert resume text to lowercase for case-insensitive search
    resume_text_lower = strdup(resume->text);
    if (!resume_text_lower) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; resume_text_lower[i]; i++) {
        resume_text_lower[i] = tolower(resume_text_lower[i]);
    }
    
    // Convert keyword to lowercase
    keyword_lower = strdup(keyword);
    if (!keyword_lower) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(resume_text_lower);
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; keyword_lower[i]; i++) {
        keyword_lower[i] = tolower(keyword_lower[i]);
    }
    
    // Check if the keyword appears in the resume text
    if (strstr(resume_text_lower, keyword_lower) != NULL) {
        result = 1;
    }
    
    // Clean up
    free(resume_text_lower);
    free(keyword_lower);
    
    return result;
}

/* Function to match keywords against resume */
MatchResult match_keywords(KeywordList* keywords, ResumeContent* resume) {
    MatchResult result;
    
    // Initialize the result structure
    result.total_keywords = keywords->count;
    result.matched_keywords = 0;
    result.match_percentage = 0.0f;
    strcpy(result.match_level, "");
    
    // Allocate memory for the keyword results
    result.keywords = malloc(keywords->count * sizeof(Keyword));
    if (!result.keywords) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Copy keywords and check if they are found in the resume
    for (int i = 0; i < keywords->count; i++) {
        strcpy(result.keywords[i].word, keywords->keywords[i].word);
        result.keywords[i].importance = keywords->keywords[i].importance;
        
        result.keywords[i].found = keyword_exists_in_resume(keywords->keywords[i].word, resume);
        
        if (result.keywords[i].found) {
            result.matched_keywords++;
        }
    }
    
    return result;
}

/* Function to calculate match score */
void calculate_match_score(MatchResult* result) {
    if (result->total_keywords > 0) {
        // Calculate weighted match percentage
        float weighted_matches = 0;
        float total_weight = 0;
        
        for (int i = 0; i < result->total_keywords; i++) {
            total_weight += result->keywords[i].importance;
            
            if (result->keywords[i].found) {
                weighted_matches += result->keywords[i].importance;
            }
        }
        
        if (total_weight > 0) {
            result->match_percentage = (weighted_matches / total_weight) * 100.0f;
        } else {
            result->match_percentage = 0.0f;
        }
    } else {
        result->match_percentage = 0.0f;
    }
}

/* Function to determine match level based on score */
void determine_match_level(MatchResult* result) {
    if (result->match_percentage >= 80.0f) {
        strcpy(result->match_level, "High");
    } else if (result->match_percentage >= 50.0f) {
        strcpy(result->match_level, "Medium");
    } else {
        strcpy(result->match_level, "Low");
    }
}

/* Function to display match results */
void display_match_results(MatchResult* result) {
    printf("\n*******************************************\n");
    printf("*             MATCH RESULTS              *\n");
    printf("*******************************************\n");
    
    printf("\nTotal Keywords: %d\n", result->total_keywords);
    printf("Matched Keywords: %d\n", result->matched_keywords);
    printf("Match Percentage: %.1f%%\n", result->match_percentage);
    printf("Match Level: %s\n", result->match_level);
    
    printf("\nMATCHED KEYWORDS:\n");
    printf("------------------\n");
    int matched_count = 0;
    for (int i = 0; i < result->total_keywords; i++) {
        if (result->keywords[i].found) {
            printf("✓ %s", result->keywords[i].word);
            // Mark high importance keywords
            if (result->keywords[i].importance == 3) {
                printf(" (High Importance)");
            }
            printf("\n");
            matched_count++;
        }
    }
    
    if (matched_count == 0) {
        printf("No keywords matched.\n");
    }
    
    printf("\nMISSING KEYWORDS:\n");
    printf("------------------\n");
    int missing_count = 0;
    for (int i = 0; i < result->total_keywords; i++) {
        if (!result->keywords[i].found) {
            printf("✗ %s", result->keywords[i].word);
            // Mark high importance keywords
            if (result->keywords[i].importance == 3) {
                printf(" (High Importance)");
            }
            printf("\n");
            missing_count++;
        }
    }
    
    if (missing_count == 0) {
        printf("No missing keywords.\n");
    }
    
    printf("\n*******************************************\n");
    printf("RECOMMENDATION:\n");
    
    if (result->match_percentage >= 80.0f) {
        printf("Your resume matches this job description very well!\n");
        printf("Consider applying immediately.\n");
    } else if (result->match_percentage >= 50.0f) {
        printf("Your resume has a decent match with this job description.\n");
        printf("Consider adding the missing high-importance keywords before applying.\n");
    } else {
        printf("Your resume needs improvement for this job description.\n");
        printf("Focus on adding the missing keywords, especially those marked as high importance.\n");
    }
    
    printf("*******************************************\n");
}