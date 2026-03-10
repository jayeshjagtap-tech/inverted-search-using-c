#include "inverted_search.h"

// Function to update the existing database by adding ONLY new files
Word *update_database(Word *wordlist)
{
    // Open FileList to read file names
    FILE *fp = fopen("FileList", "r");
    if (!fp)
    {
        printf("FileList missing!\n");
        return wordlist;
    }

    char fname[50];

    // Read each filename from FileList
    while (fscanf(fp, "%s", fname) != EOF)
    {
        int found = 0;   // To check if file already exists in database
        Word *w = wordlist;

        // Traverse all word nodes
        while (w)
        {
            File *f = w->fnode;

            // Traverse file list of each word
            while (f)
            {
                // Check if this file is already indexed
                if (strcmp(f->filename, fname) == 0)
                {
                    found = 1;   // File already present in database
                    break;
                }
                f = f->next;
            }

            if (found) 
                break;

            w = w->next;
        }

        // If this file is NOT found in the database → it's a NEW file
        if (!found)
        {
            FILE *newfp = fopen(fname, "r");

            if (newfp)
            {
                // Inform user that a new file is being processed
                printf("Updating with new file: %s\n", fname);

                // Add words from this new file into the existing database
                wordlist = read_datafile(newfp, wordlist, fname);

                fclose(newfp);
            }
        }
    }

    // Close FileList after processing all filenames
    fclose(fp);

    return wordlist; // Return updated wordlist
}
