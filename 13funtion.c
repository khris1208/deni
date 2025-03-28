/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFLINES 10 /* default # of lines to print */
#define LINES   100 /* maximum # of lines to print */
#define MAXLEN  100 /* maximum length of an input line */

void error(char *);
int mgetline13(char *, int);

/* print the last 10 lines of the input */

void q13(void)
{
    char *p;
    char *buf;  /* pointer to the large buffer */
    char *bufend;   /* end of the large buffer */

    char line[MAXLEN];
    char *lineptr[LINES];   /* pointer to lines read */
    
    int first, i, last, len, n = DEFLINES, nlines;

    for(i = 0; i < LINES; i++)
        lineptr[i] = NULL;

    if((p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail: cannot allocate buf");
    bufend = buf + LINES * MAXLEN;

    last = 0;
    nlines = 0;

    while((len = mgetline13(line, MAXLEN)) > 0)
    {
        if(p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p;

        strcpy(lineptr[last], line);
        if(++last >= LINES)
            last = 0;

        p += len + 1;
        nlines++;
    }

    if(n > nlines)
        n = nlines;

    first = last - n;

    if(first < 0)
        first += LINES;
    
    for(i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);

    return 0;
}

/* error: print error messages and exit */

void error(char *s)
{
    printf("%s\n", s);
    exit(1);
}

/* mgetline: read a line into s and return length */

int mgetline13(char s[], int lim)
{
    int c, i;
    
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
