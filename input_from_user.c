#include "inverted_search.h"

// Function to take a word as input from the user
char *input_from_user(void)
{
    // Allocate memory to store the input word
    char *str = malloc(100);

    // Ask the user to enter a word for searching
    printf("Enter the word to search: ");

    // Read the word from user input
    scanf("%s", str);

    // Return the entered word to calling function
    return str;
}
