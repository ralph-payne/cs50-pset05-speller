#include <stdio.h>
#include <stdbool.h>
// malloc
#include <stdlib.h>

// Define struct called node which represents a node in a hash table
typedef struct node
{
    char word[45]; // temp hardcoding this
    struct node *next;
}
node;

#define DICTIONARY "dictionaries/small"
#define DICTIONARYSIZE 200

bool load(const char *dictionary);

void main (void)
{
    char *dictionary = DICTIONARY;

    load(dictionary);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // Step 1: Load the dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        // unload();
        return false; // return 1 is exit failure
    }

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

    printf("new lines (numberr of words): %u", new_line_counter);
    // ==== end ====

    // Allocate enough memory to store 10 nodes
    node *list = malloc(DICTIONARYSIZE * sizeof(node));

    if (list == NULL){return 1;} // good pract

    // read file into buffer (list) | returns an int
    fread(list, sizeof(char), 512, file);
    
    

    free(list);
    fclose(file);
    return true;
}