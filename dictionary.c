// Implements a dictionary's functionality

// file and printf
#include <stdio.h>

#include <stdbool.h>

#include "dictionary.h"

// malloc
#include <stdlib.h>

// Define struct called node which represents a node in a hash table
typedef struct node
{
    // "+1" is for \0
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 16;

// Hash table
// Used for keeping track of words in the dictionary
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO (return 0 is the same as saying exit success)
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // Step 1: Load the dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false; // return 1 is exit failure
    }

    // Allocate enough memory to store 1 nodes
    int *list = malloc(sizeof(node));

    if (list == NULL)
    {
        return 1;
    }
    
    printf("opened dictionary");

    // ==== start ====
    // Calc no. of words
    unsigned int new_line_counter = 0;
    int next_char;

    // fgetc
    while ( ( next_char = fgetc(file) ) != EOF ) 
    {
        if (next_char == '\n')
        {
            new_line_counter++;
        }
    }

    // Add one more word because last word won't have a "\n"
    new_line_counter++;

    printf("We now have the number of words in the dictionary %u\n", new_line_counter);
    // ==== end ====

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
