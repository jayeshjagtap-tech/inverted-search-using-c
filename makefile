# Compiler to use
CC = gcc

# Compiler flags (-Wall enables all warnings)
CFLAGS = -Wall

# Object files required to build the project
OBJ = main.o create_database.o read_datafile.o string_token.o store_word.o \
      write_databasefile.o search.o display_output.o update_database.o


# ------------------ BUILD TARGET ------------------
# Build the final executable named 'InvertedSearch'
InvertedSearch: $(OBJ)
	$(CC) $(OBJ) -o InvertedSearch


# ------------------ OBJECT FILE CREATION ------------------
# Rule to compile every .c file into a .o file
# inverted_search.h is included because all .c files depend on it
%.o: %.c inverted_search.h
	$(CC) $(CFLAGS) -c $<


# ------------------ CLEAN TARGET ------------------
# Removes generated files to clean the workspace
clean:
	rm -f *.o InvertedSearch DatabaseFile.txt
