// I am a bit stuck when it comes to the buffer ??
// What exactly should I do with this buffer ??
// Have a look at the previous pset for some help

// Todo for Wed 27 May
// 1. Check syntax for declaring a struct
// 2. Work out how to use a buffer so you don't get a seg fault
// 3. See if you can now use the array of new structs to have a look up for the spell check
// 4. Maybe add a pointer to the new struct like in iteration 1?
// 5. Look at iteration 2, and merge iteration 2 with this one (3)

#include <stdio.h>
#include <stdlib.h> // <= malloc

#define DICTIONARY "dictionaries/small"
// #define DICTIONARY "dictionaries/large"
#define MAX_WORD_LENGTH 45

typedef struct node
{
    char word[MAX_WORD_LENGTH];
    long long int key; // <= Not currently in use
    struct node *next; // <= Pointer to next node (not currently in use)
}
node;

int main(void) 
{
    char *dictionary = DICTIONARY;
    FILE *myfile = fopen(dictionary, "r");
    
    if (myfile == NULL) 
    {
        printf("Cannot open file.\n");
        return 1;
    }

    // Step 2: Calc no. of words
    unsigned int size_of_dictionary = 0;
    int next_char;

    while ( ( next_char = fgetc(myfile) ) != EOF ) 
    {
        if (next_char == '\n')
        {
            size_of_dictionary++;
        }	
    }

    // Add one more word because last word won't have a "\n"
    size_of_dictionary++;
    printf("new lines (number of words): %u\n", size_of_dictionary);
    rewind(myfile);

    // malloc (otherwise you'll get a seg fault)
    node *array_of_words = malloc(size_of_dictionary * sizeof(node));

    // Check there's enough memory
    if (array_of_words == NULL)
    {
        return 1;
    }

    // Scan all lines inside dictionary & print
    for (int i = 0; i < size_of_dictionary - 1; i++)
    {
        fscanf(myfile, "%s\n", array_of_words[i].word);
        printf("%d: %s\n", i + 1, array_of_words[i].word);
    }

    // Declare words to look up
    char *yay = "locutor";
    char *nay = "pocutor";
    printf("Program will now look up these two words: %s and %s\n", yay, nay);

    // Linear Search Example
    for (int i = 0; i < size_of_dictionary - 1; i++)
    {
        printf("Looking for a word %s %d: %s\n", yay , i + 1, array_of_words[i].word);
    }

    // Free memory
    free(array_of_words);
    fclose(myfile);
    return 0;
}