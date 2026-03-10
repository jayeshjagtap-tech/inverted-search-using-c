#include "inverted_search.h"

// Function to read a single file and extract all its words
Word *read_datafile(FILE *file, Word *wordlist, char *filename)
{
    char buff[200];   // Buffer to store each line of the file
    char *token;      // Pointer for storing each extracted word

    // Read file line-by-line until EOF
    while (fgets(buff, sizeof(buff), file))
    {
        // Extract the first word (token) from the current line
        token = string_token(buff);

        // Extract all remaining words in the same line
        while (token)
        {
            // Store the word into our inverted index structure
            wordlist = store_word(token, filename, wordlist);

            // Get next token from the same line
            token = string_token(NULL);
        }
    }

    // Return updated linked list after processing the whole file
    return wordlist;
}
