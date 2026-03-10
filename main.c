#include "inverted_search.h"

// Global head pointer for the main word list
Word *head = NULL;

int main(int argc, char *argv[])
{
    int choice;
    char word[50];

    while (1)   // Menu-driven loop runs until Exit
    {
        // Display menu to user
        printf("\nSelect your choice:\n");
        printf("1. Create DATABASE\n");
        printf("2. Display DATABASE\n");
        printf("3. Update DATABASE (only new files)\n");
        printf("4. Search\n");
        printf("5. Save DATABASE\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            // Open FileList to read file names
            FILE *fp = fopen("FileList", "r");

            // Validation: FileList must exist
            if (!fp)
            {
                printf("FileList missing!\n");
                break;
            }

            // Reset database before fresh creation
            head = NULL;

            // Create the full inverted index
            create_database(fp);
            break;
        }

        case 2:
            // Display entire word → file → count mapping
            display_output(head);
            break;

        case 3:
            // Update database by adding ONLY new files from FileList
            head = update_database(head);
            break;

        case 4:
            // Take word input and search
            printf("Enter word to search: ");
            scanf("%s", word);

            // Perform search operation
            search_word(head, word);
            break;

        case 5:
        {
            // Save the current database into DatabaseFile.txt
            FILE *fp = fopen("DatabaseFile.txt", "w");
            write_databasefile(head, fp);
            fclose(fp);

            printf("Database saved successfully.\n");
            break;
        }

        case 6:
            // Exit program gracefully
            exit(0);

        default:
            // Handles invalid menu choices
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
