/* matcher.h - Header for matching module */
#ifndef MATCHER_H
#define MATCHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "keyword_extractor.h"
#include "pdf_parser.h"

typedef struct {
    int total_keywords;
    int matched_keywords;
    float match_percentage;
    char match_level[20]; // "Low", "Medium", or "High"
    Keyword* keywords;    // Array of keywords with found status
} MatchResult;

/* Function to match keywords against resume */
MatchResult match_keywords(KeywordList* keywords, ResumeContent* resume);

/* Function to calculate match score */
void calculate_match_score(MatchResult* result);

/* Function to determine match level based on score */
void determine_match_level(MatchResult* result);

/* Function to display match results */
void display_match_results(MatchResult* result);

#endif /* MATCHER_H */