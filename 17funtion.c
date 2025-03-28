/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define NUMERIC 1   /* numeric sort */
#define DECR    2   /* sort in decreasing order */
#define FOLD    4   /* fold upper and lower cases */
#define MDIR    8   /* directory order */
#define LINES   100 /* maximum number of lines to be sorted */

int charcmp_17(char *, char *);
int numcmp_17(char *, char *);
int readlines_17(char *lineptr[], int maxlines);
void myqsort_17(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines_17(char *lineptr[], int nlines, int order);

static char option = 0;

/* sort input lines */
void q17(void)
{
    char *lineptr[LINES];   /* pointer to text line */
    int nlines;
    
    if ((nlines = readlines_17(lineptr, LINES)) > 0)
    {
        if (option & NUMERIC)
            myqsort_17((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp_17);
        else
            myqsort_17((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp_17);
    
        writelines_17(lineptr, nlines, option & DECR);
    }
    else
    {
        printf("input too big to sort \n");
    }
    
    return 0;
}

/* charcmp_17: return <0 if s < t, 0 if s ==t, >0 if s > t */
int charcmp_17(char *s, char *t)
{
    char a, b;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & MDIR) ? 1 : 0;
    
    do
    {
        if (dir)
        {
            while (!isalnum(*s) && *s != ' ' && *s != '\0')
                s++;
            while (!isalnum(*t) && *t != ' ' && *t != '\0')
                t++;
        }
        a = fold ? tolower(*s) : *s;
        s++;
        b = fold ? tolower(*t) : *t;
        t++;
    
        if (a == b && a == '\0')
            return 0;
    } while (a == b);
    
    return a - b;
}

/* numcmp_17: compare s1 and s2 numerically */
int numcmp_17(char *s1, char *s2)
{
    double v1, v2;
    
    v1 = atof(s1);
    v2 = atof(s2);
    
    return (v1 > v2) - (v1 < v2);
}

void swap_17(void *v[], int i, int j)
{
    void *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* myqsort_17: sort v[left] ... v[right] into increasing order */
void myqsort_17(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right)   /* do nothing if array contains */
        return;     /* fewer than two elements */

    swap_17(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap_17(v, ++last, i);

    swap_17(v, left, last);

    myqsort_17(v, left, last - 1, comp);
    myqsort_17(v, last + 1, right, comp);
}

#define MAXLEN  1000    /* max length of any input line */
int mgetline_17(char *, int);
char *alloc_17(int);

/* readlines_17: read input lines */
int readlines_17(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while ((len = mgetline_17(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc_17(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines_17: write output lines */
void writelines_17(char *lineptr[], int nlines, int order)
{
    int i;
    
    if (order)
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf_17[ALLOCSIZE];    /* storage for alloc */
static char *allocp_17 = allocbuf_17;     /* next free position */

char *alloc_17(int n)      /* return pointer to n characters */
{
    if (allocbuf_17 + ALLOCSIZE - allocp_17 >= n)    
    {
        allocp_17 += n;
        return allocp_17 - n;
    }
    else
        return 0;
}

void afree_17(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf_17 && p < allocbuf_17 + ALLOCSIZE)
        allocp_17 = p;
}

/* mgetline_17: read a line s, return length */
int mgetline_17(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

