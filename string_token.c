#include "inverted_search.h"

// Custom tokenizer function to extract one alphabetic word at a time
char *string_token(char *str)
{
    static char *ptr;   // Holds the current position in the string
    char *word;

    // If a new string is passed, reset ptr to the start of that string
    if (str != NULL)
        ptr = str;

    // If ptr is NULL, no more tokens
    if (ptr == NULL)
        return NULL;

    // Skip all non-alphabetic characters (spaces, punctuation, numbers)
    while (*ptr && !isalpha(*ptr))
        ptr++;

    // End of string reached → no more words
    if (*ptr == '\0')
        return NULL;

    // Mark the start of the word
    word = ptr;

    // Move pointer forward until the end of the alphabetic word
    while (*ptr && isalpha(*ptr))
        ptr++;

    // If not end of string, replace delimiter with '\0'
    if (*ptr)
    {
        *ptr = '\0';  // Terminate the word
        ptr++;        // Move to next character for the next call
    }

    return word;      // Return extracted word
}
