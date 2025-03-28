/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define NUMERIC 1   /* numeric sort */
#define DECR    2   /* sort in decreasing order */
#define FOLD    4   /* fold upper and lower cases */
#define LINES   100 /* maximum number of lines to be sorted */

int charcmp_15(char *, char *);
int numcmp_15(char *, char *);
int readlines_15(char *lineptr[], int maxlines);
void myqsort_15(char *v[], int left, int right, int (*comp)(void *, void *));
void writelines_15(char *lineptr[], int nlines, int order);

static char option = 0;

void q15(void) {
    char *lineptr[LINES];
    int nlines;
    char choice;

    printf("Choose sorting options:\n");
    printf("f - Case insensitive sort\n");
    printf("n - Numeric sort\n");
    printf("r - Reverse order\n");
    printf("Enter options (e.g., fnr for all): ");
    while ((choice = getchar()) != '\n') {
        switch (choice) {
            case 'f': option |= FOLD; break;
            case 'n': option |= NUMERIC; break;
            case 'r': option |= DECR; break;
            default: printf("Invalid option: %c\n", choice); break;
        }
    }

    if ((nlines = readlines_15(lineptr, LINES)) > 0) {
        if (option & NUMERIC)
            myqsort_15((char **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp_15);
        else if (option & FOLD)
            myqsort_15((char **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp_15);
        else
            myqsort_15((char **)lineptr, 0, nlines - 1, (int (*)(void *, void *))strcmp);

        writelines_15(lineptr, nlines, option & DECR);
    } else {
        printf("Input too big to sort\n");
        return -1;
    }
    return 0;
}

int charcmp_15(char *s, char *t) {
    for (; tolower(*s) == tolower(*t); s++, t++)
        if (*s == '\0') return 0;
    return tolower(*s) - tolower(*t);
}

int numcmp_15(char *s1, char *s2) {
    double v1 = atof(s1), v2 = atof(s2);
    return (v1 < v2) ? -1 : (v1 > v2);
}

#define MAXLEN 1000
int mgetline_15(char *, int);
char *alloc_15(int);

int readlines_15(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = mgetline_15(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc_15(len)) == NULL)
            return -1;
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void myqsort_15(char *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap_15(char *v[], int i, int j);

    if (left >= right) return;
    swap_15(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap_15(v, ++last, i);
    swap_15(v, left, last);
    myqsort_15(v, left, last - 1, comp);
    myqsort_15(v, last + 1, right, comp);
}

void swap_15(char *v[], int i, int j) {
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void writelines_15(char *lineptr[], int nlines, int decr) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE 1000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc_15(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    return 0;
}

void afree_15(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int mgetline_15(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

