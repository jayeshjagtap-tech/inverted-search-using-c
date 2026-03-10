# Inverted Search Using C

This project implements a simple Inverted Search system using the C programming language. The goal of the project is to read multiple text files, extract words from them, and build an index that maps each word to the files where it appears along with the number of occurrences.

The idea behind this project is similar to how search engines organize data internally. Instead of scanning every file during each search, the program creates an indexed structure so that a word can be located quickly.

The implementation uses linked lists and file handling in C, and the project is organized into multiple modules to keep the code modular and easy to maintain.

---

## Objectives

The main objectives of this project are:

* To understand how an inverted index works.
* To practice file handling in C.
* To implement linked lists for structured data storage.
* To design a modular C program using multiple source files.
* To allow efficient searching of words across multiple text files.

---

## How the Program Works

The program reads a file named FileList, which contains the names of the text files that need to be indexed.

For each file listed:

1. The program opens the file.
2. It reads the contents line by line.
3. Each line is tokenized to extract words.
4. Words are stored in a linked list structure.
5. For each word, the program keeps track of:

   * The files where it appears
   * The number of times it appears in each file.

Once the database is created, the user can:

* Display the entire indexed database
* Search for a specific word
* Update the database if new files are added
* Save the database into a file for later use

---

## Project Features

* Builds an inverted index from multiple text files
* Maintains word → file → occurrence count mapping
* Supports searching a word across all indexed files
* Allows updating the database when new files are added
* Saves the indexed database to a file
* Modular program design using separate `.c` files

---

## Project Structure

```
main.c
create_database.c
create_indexlist.c
read_datafile.c
store_word.c
string_token.c
search.c
display_output.c
write_databasefile.c
update_database.c
input_from_user.c
inverted_search.h
makefile
```

### Brief Description of Important Files

**main.c**

Contains the menu-driven program that controls all operations.

**create_database.c**

Reads file names from FileList and builds the inverted index.

**read_datafile.c**

Reads data from each file and extracts words for indexing.

**store_word.c**

Stores words in the linked list and updates occurrence counts.

**string_token.c**

Custom tokenizer that extracts alphabetic words from text.

**search.c**

Searches a given word in the indexed database.

**display_output.c**

Displays the complete inverted index in a readable format.

**write_databasefile.c**

Saves the database into a file.

**update_database.c**

Updates the database when new files are added to FileList.

**create_indexlist.c**

Rebuilds the linked list structure from a saved database file.

**inverted_search.h**

Header file containing structures and function declarations.

**makefile**

Used to compile the project automatically.

---

## Data Structures Used

Two linked list structures are used in this project.

### Word Node

Stores each unique word.

```
Word
 ├── word
 ├── file_count
 ├── pointer to file list
 └── next word
```

### File Node

Stores information about the files containing that word.

```
File
 ├── filename
 ├── word_count
 └── next file
```

This structure allows efficient storage and retrieval of word occurrences.

---

## Input Files

The program expects a file named FileList containing the names of the files to be indexed.

Example:

```
file1.txt
file2.txt
```

Example contents of input files:

**file1.txt**

```
Hi this is file one
Hello from file one
```

**file2.txt**

```
Hi this is file two
Hello from file two
```

---

## How to Compile

Use the Makefile provided in the project.

```
make
```

This command compiles all source files and creates the executable:

```
InvertedSearch
```

---

## How to Run the Program

After compiling, run the executable:

```
./InvertedSearch
```

You will see a menu like this:

```
1. Create DATABASE
2. Display DATABASE
3. Update DATABASE
4. Search
5. Save DATABASE
6. Exit
```

---

## Sample Output

Example search operation:

```
Enter word to search: hello

Word is present in 2 file/s:
file1.txt: 1 times
file2.txt: 1 times
```

---

## Learning Outcome

While working on this project, I gained practical experience in:

* Linked list implementation
* File handling in C
* String processing
* Modular program design
* Implementing indexing techniques similar to search systems

It also helped improve debugging skills and understanding of how structured data can be organized for efficient searching.

---

## Author

Jayesh Jagtap
