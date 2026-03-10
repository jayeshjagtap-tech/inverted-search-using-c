#include "inverted_search.h"

// Function to display the entire inverted index (database)
void display_output(Word *wordlist)
{
    int index = 0;

    // Header format for display
    printf("[index] [word] file/s: filename count\n");

    // Traverse the word linked list
    while (wordlist)
    {
        // Print the current word and how many files it appears in
        printf("[%d] [%s] %d file/s: ",
               index, wordlist->word, wordlist->file_count);

        // Traverse the file-list for this word
        File *f = wordlist->fnode;

        while (f)
        {
            // Print filename and count of occurrences
            printf("%s %d time%s ",
                   f->filename,
                   f->word_count,
                   f->word_count > 1 ? "s" : ""); // plural handling

            f = f->next; // Move to next file-node
        }

        printf("\n"); // End of one word entry

        index++;             // Increase index counter
        wordlist = wordlist->next; // Move to next word-node
    }
}
