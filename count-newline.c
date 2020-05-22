// https://stackoverflow.com/questions/4278845/what-is-the-easiest-way-to-count-the-newlines-in-an-ascii-file

#include <stdio.h>

int main()
{
    FILE                *fp = stdin;    /* or use fopen to open a file */
    int                 c;              /* Nb. int (not char) for the EOF */
    unsigned int       newline_count = 0;

    /* count the newline characters */
    while ( ( c = fgetc(fp) ) != EOF ) 
    {
        if (c == '\n')
        {
            newline_count++;
        }
    }

    printf("%u newline characters\n", newline_count);
    return 0;
}