#include "inverted_search.h"

// Function to search for a word in the inverted index
void search_word(Word *wordlist, char *word)
{
    // Traverse the main word linked list
    while (wordlist)
    {
        // Compare each word in a case-insensitive way
        if (strcasecmp(wordlist->word, word) == 0)
        {
            // Word found → print how many files contain this word
            printf("Word is present in %d file/s:\n", wordlist->file_count);

            // Pointer to traverse the file list of this word
            File *f = wordlist->fnode;

            // Print filename and count of occurrences
            while (f)
            {
                printf("%s: %d times\n", f->filename, f->word_count);
                f = f->next;  // Move to next file-node
            }

            return; // Exit after printing results
        }

        // Move to the next word node
        wordlist = wordlist->next;
    }

    // If loop finishes → word was not found
    printf("Word not found in any file.\n");
}
