#include "inverted_search.h"

// Function to store a word in sorted order and update its file occurrence list
Word *store_word(char *word, char *filename, Word *wordlist)
{
    Word *temp = wordlist, *prev = NULL;

    // Traverse the word list to find correct position or an existing match
    while (temp)
    {
        // Case-insensitive compare to check if the word already exists
        if (strcasecmp(temp->word, word) == 0)
            break;

        // If current node word is greater → insert before it (sorted order)
        if (strcmp(temp->word, word) > 0)
            break;

        prev = temp;
        temp = temp->next;
    }

    // If word not found → create a new word node
    if (!temp || strcasecmp(temp->word, word) != 0)
    {
        Word *new = malloc(sizeof(Word));
        strcpy(new->word, word);
        new->file_count = 0;     // No files counted yet
        new->fnode = NULL;       // File list empty initially
        new->next = temp;        // Attach new node before temp

        // Insert node in correct position
        if (prev)
            prev->next = new;
        else
            wordlist = new;      // Insert at beginning

        temp = new;              // temp now points to newly inserted node
    }

    // Check if this word already has this filename in its file list
    File *f = temp->fnode;
    while (f)
    {
        // If file already exists, just increment the count
        if (strcmp(f->filename, filename) == 0)
        {
            f->word_count++;
            return wordlist;
        }
        f = f->next;
    }

    // If filename NOT found → create a new file node
    File *newf = malloc(sizeof(File));
    strcpy(newf->filename, filename);
    newf->word_count = 1;
    newf->next = temp->fnode;   // Insert at beginning of file list
    temp->fnode = newf;

    // Increase file_count since this is a new file entry
    temp->file_count++;

    return wordlist;
}
