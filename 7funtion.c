/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include<stdio.h>
#include<string.h>

#define MAXLINES 5000   /* max #lines to be sorted */

char *lineptr5[MAXLINES];
char linestor5[MAXLINES];

int readlines5(char *lineptr5[],char *linestor5,int nlines5);
void writelines5(char *lineptr5[],int nlines5);

void qsort5(char *lineptr5[],int left5,int right5);

/* sort input lines */

void q7(void)
{
    int nlines5; /* number of input lines read */

    if((nlines5 = readlines5(lineptr5,linestor5,MAXLINES)) >= 0)
    {
        qsort5(lineptr5,0,nlines5-1);
        writelines5(lineptr5,nlines5);
        return 0;
    }
    else
    {
        printf("error: input too big to sort \n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
#define MAXSTOR 5000

int mgetline5(char *,int);
char *alloc5(int);

/* readlines: read input lines */
int readlines5(char *lineptr5[],char *linestor5,int maxlines5)
{
    int len5,nlines5;
    char line5[MAXLEN];
    char *p5 = linestor5;
    char *linestop5 = linestor5 + MAXSTOR;

    nlines5=0;

    while((len5=mgetline5(line5,MAXLEN)) > 0)
        if(nlines5 >= maxlines5 || p5+len5 > linestop5)
            return -1;
        else
        {
            line5[len5-1] = '\0';
            strcpy(p5,line5);
            lineptr5[nlines5++]=p5;
            p5+=len5;
        }
    return nlines5;
}

/* writelines: write output lines */
void writelines5(char *lineptr5[],int nlines5)
{
    int i5;
    for(i5=0;i5<nlines5;i5++)
        printf("%s\n",lineptr5[i5]);
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort5(char *v5[],int left5,int right5)
{
    int i5,last5;
    void swap5(char *v5[],int i5,int j5);

    if(left5 >= right5)
        return;
    swap5(v5,left5,(left5+right5)/2);

    last5 = left5;

    for(i5=left5+1;i5<=right5;i5++)
        if(strcmp(v5[i5],v5[left5])<0)
            swap5(v5,++last5,i5);
    swap5(v5,left5,last5);
    qsort5(v5,left5,last5-1);
    qsort5(v5,last5+1,right5);
}

/* swap: interchange v[i] and v[j] */

void swap5(char *v5[],int i5,int j5)
{
    char *temp5;

    temp5=v5[i5];
    v5[i5]=v5[j5];
    v5[j5]=temp5;
}

#define ALLOCSIZE 10000  /* size of available space */

static char allocbuf5[ALLOCSIZE];    /* storage for alloc */
static char *allocp5 = allocbuf5;     /* next free position */

char *alloc5(int n5)  /* return pointer to n5 characters */
{
    if(allocbuf5 + ALLOCSIZE - allocp5 >= n5)
    {
        allocp5 += n5;
        return allocp5 -n5;
    }
    else
        return 0;
}

int mgetline5(char *s5,int lim5)
{
    int c5;
    char *t5=s5;

    while(--lim5 >0 && (c5=getchar())!=EOF && c5!='\n')
        *s5++ = c5;
    if( c5 == '\n')
        *s5++ = c5;

    *s5= '\0';

    return s5-t5;
}
