/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include<stdio.h>
#define MAXLINE 1000
#include"header.h"
int mgetline1(char line[],int maxline);
void mystrcat(char *,char *);

void q3(void)
{
    int len;
    char s[MAXLINE],t[MAXLINE];

    putchar('s');
    putchar(':');
    mgetline1(s,MAXLINE);
    
    putchar('t');
    putchar(':');
    mgetline1(t,MAXLINE);
    
    mystrcat(s,t);

    printf("%s",s);

}

int mgetline1(char s[],int lim)
{
    int c,i;
    
    for(i=0;i<lim-1 && (c=getchar()) !=EOF && c!='\n';++i)
        s[i] = c;
    
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';

    return i;
}

void mystrcat(char *s,char *t)
{
    while(*s!='\0')
        s++;
    s--;             /* goes back to \0 char */
    while((*s=*t)!='\0')
    {   
        s++;
        t++;
    }
}
