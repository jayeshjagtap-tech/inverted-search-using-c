#include "inverted_search.h"

// Function to save the current inverted database into DatabaseFile.txt
void write_databasefile(Word *wordlist, FILE *fp)
{
    // Traverse through the entire word linked list
    while (wordlist)
    {
        // Write the word and how many files it appears in
        fprintf(fp, "%s %d ", wordlist->word, wordlist->file_count);

        // Pointer to the file list of this word
        File *f = wordlist->fnode;

        // Write each filename and the count for this word
        while (f)
        {
            fprintf(fp, "%s %d ", f->filename, f->word_count);
            f = f->next;   // Move to next file node
        }

        // End this line so the next word starts on a new line
        fprintf(fp, "\n");

        // Move to the next word node in the main list
        wordlist = wordlist->next;
    }
}
