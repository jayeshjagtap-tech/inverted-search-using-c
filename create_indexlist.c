#include "inverted_search.h"

/*
Format example in DatabaseFile.txt:

hello 2 file1.txt 3 file2.txt 1
jayesh 1 file2.txt 1

This function rebuilds the Word and File nodes.
*/

Word *create_indexlist(FILE *dbfile, Word *index_list)
{
    char word[50], fname[50];
    int file_count, wcount;

    while (fscanf(dbfile, "%s %d", word, &file_count) != EOF)
    {
        /* Create Word node */
        Word *new_word = malloc(sizeof(Word));
        strcpy(new_word->word, word);
        new_word->file_count = file_count;
        new_word->fnode = NULL;

        /* Insert at front (you can sort later if needed) */
        new_word->next = index_list;
        index_list = new_word;

        /* Read associated file nodes */
        for (int i = 0; i < file_count; i++)
        {
            fscanf(dbfile, "%s %d", fname, &wcount);

            File *new_file = malloc(sizeof(File));
            strcpy(new_file->filename, fname);
            new_file->word_count = wcount;

            /* Insert file-node at front */
            new_file->next = new_word->fnode;
            new_word->fnode = new_file;
        }
    }

    return index_list;
}
