/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINES 100   /* max # of lines to be sorted */

int numcmp_14(char *, char *);
int readlines_14(char *lineptr[], int maxlines);
void myqsort_14(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines_14(char *lineptr[], int nlines);

/* sort input lines */
void q14(void)
{
    char *lineptr[LINES];
    int nlines;  /* number of input lines read */
    
    if ((nlines = readlines_14(lineptr, LINES)) > 0)
    {
        myqsort_14((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp_14);
        writelines_14(lineptr, nlines);
    }
    else
    {
        printf("Input too big to sort\n");
    }
    return 0;
}

/* writelines_14: write output lines */
void writelines_14(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* numcmp_14: compare s1 and s2 numerically */
int numcmp_14(char *s1, char *s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);
    
    return (v1 > v2) - (v1 < v2);
}

#define MAXLEN 1000 /* max length of any input line */
int mgetline_14(char *, int);
char *alloc_14(int);

/* readlines_14: read input lines */
int readlines_14(char *lineptr[], int maxlines)
{
    int len, nlines = 0;
    char *p, line[MAXLEN];
    
    while ((len = mgetline_14(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc_14(len)) == NULL)
            return -1;
        
        line[len - 1] = '\0'; /* delete newline */
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

#define ALLOCSIZE 1000  /* size of available space */
static char allocbuf_14[ALLOCSIZE];
static char *allocp_14 = allocbuf_14;

char *alloc_14(int n)  /* return pointer to n characters */
{
    if (allocbuf_14 + ALLOCSIZE - allocp_14 >= n)
    {
        allocp_14 += n;
        return allocp_14 - n;
    }
    else
        return 0;
}

/* myqsort_14: sort v[left] ... v[right] into increasing order */
void myqsort_14(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap_14(void *v[], int, int);

    if (left >= right)
        return;

    swap_14(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap_14(v, ++last, i);
    
    swap_14(v, left, last);
    myqsort_14(v, left, last - 1, comp);
    myqsort_14(v, last + 1, right, comp);
}

void swap_14(void *v[], int i, int j)
{
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* mgetline_14: read a line into s, return length */
int mgetline_14(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

