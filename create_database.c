#include "inverted_search.h"

// Function to create the full database from all files listed in FileList
void create_database(FILE *filelist)
{
    char filename[50];

    // Read each file name from FileList one by one
    while (fscanf(filelist, "%s", filename) != EOF)
    {
        // Try opening the current file for reading
        FILE *fp = fopen(filename, "r");

        // If file cannot be opened, print error and skip it
        if (!fp)
        {
            printf("Cannot open %s\n", filename);
            continue;
        }

        // Indicate which file is currently being processed
        printf("Processing: %s\n", filename);

        // Read the file, extract words, and update the database
        head = read_datafile(fp, head, filename);

        // Close the file after processing
        fclose(fp);
    }

    // Close FileList after reading all filenames
    fclose(filelist);

    // Database creation completed message
    printf("Database created successfully.\n");
}
