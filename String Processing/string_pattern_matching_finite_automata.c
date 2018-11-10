#include<stdio.h>
#include<string.h>

/// maximum characters in ASCII
#define CHARACTERS 256
/// maximum text and pattern length
#define MAX_CHAR_TEXT 1024

/// function prototypes
void patternMatch(char patt[], char text[]);
void transitionTable(char patt[] , int patt_len, int tabl[][CHARACTERS]);

int main()
{
    // character array for pattern and text store
    char text[MAX_CHAR_TEXT];
    char patt[MAX_CHAR_TEXT];

    // input the pattern
    printf("Pattern: "); gets(patt);

    while(1)
    {
        // input the text for pattern match
        printf("Your text: "); gets(text);
        /// for empty string program will finished
        if(strlen(text) == 0) break;
        // check pattern matching
        patternMatch(patt, text);
    }
}

/// function defining area
void patternMatch(char patt[], char text[])
{
    // pattern string length
    int patt_len = strlen(patt);
    // text string length
    int text_len = strlen(text);

    // transition function table
    int tabl[patt_len+1][CHARACTERS];

    /// set preferred value in transition table
    transitionTable(patt,patt_len,tabl);

    // iterating index of the text string
    int index;
    // initial length of matched pattern from text string
    int len=0;

    // flag for check whether any match found or not
    short flag = 0;

    // iterate through the text string
    for(index=0; index<text_len; index++)
    {
        // update the matched pattern length from transition table
        len = tabl[len][text[index]];
        // whether matched pattern length equal with pattern length then match found
        if(len == patt_len)
        {
            // print out the index from where match started
            printf("Pattern match at index: %d\n",index-(patt_len-1));
            // change the flag
            flag = 1;
        }
    }

    // when no match for current text
    if(! flag) puts("No match found");
}

void transitionTable(char patt[] , int patt_len, int tabl[][CHARACTERS])
{
    // tracker index for row value copy
    int track = 0;
    // iteration index
    int row, col;

    // for first row of the table
    for(col=0; col<CHARACTERS; col++)
        tabl[0][col] = 0;
    // update the next index of first character from the pattern
    tabl[0][patt[0]] = 1;

    for(row=1; row<=patt_len; row++)
    {
        // copy row value from tracker row
        for(col=0; col<CHARACTERS; col++)
            tabl[row][col] = tabl[track][col];
        // set next state for current index character
        tabl[row][patt[row]] = row+1;

        // last row will copy the first row value for re-checking
        if(row<patt_len)
            track = tabl[track][patt[row]];
    }
}
