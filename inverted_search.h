#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// ---------------------- FILE NODE STRUCTURE ----------------------
// Stores filename and how many times the word appears in that file.
typedef struct file_node
{
    char filename[50];     // Name of the file
    int word_count;        // Count of this word inside that file
    struct file_node *next; // Pointer to next file-node
} File;


// ---------------------- WORD NODE STRUCTURE ----------------------
// Stores a word and linked list of files where the word appears.
typedef struct word_node
{
    char word[50];         // The actual word
    int file_count;        // Number of files containing this word
    File *fnode;           // Head pointer to file-node list
    struct word_node *next; // Pointer to next word-node
} Word;


// Global pointer to the head of the main word list
extern Word *head;


// ---------------------- FUNCTION DECLARATIONS ----------------------

// Creates the full database from all files in FileList
void create_database(FILE *filelist);

// Reads a specific file and adds its words into the database
Word *read_datafile(FILE *file, Word *wordlist, char *filename);

// Custom tokenizer: extracts one word at a time
char *string_token(char *str);

// Stores a word in sorted order and updates file occurrence count
Word *store_word(char *word, char *filename, Word *wordlist);

// Saves the complete database into DatabaseFile.txt
void write_databasefile(Word *wordlist, FILE *fp);

// Displays the database (word → files → counts)
void display_output(Word *wordlist);

// Searches for a word and prints the matching file list
void search_word(Word *wordlist, char *word);

// Adds newly added files from FileList into existing database
Word *update_database(Word *wordlist);

// Recreates index list from an already saved database file
Word *create_indexlist(FILE *dbfile, Word *index_list);

#endif
