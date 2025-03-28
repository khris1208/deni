/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include<stdio.h>
#define MAXLINE 1000
#include"header.h"
int mgetline(char s[],int max);
int strend(char *s,char *t);
int mystrlen(char *t);

void q4(void)
{
    char s[MAXLINE],t[MAXLINE];
    int ret;
    mgetline(s,MAXLINE);
    mgetline(t,MAXLINE);
    ret = strend(s,t);
    printf("%d",ret);
}

int mgetline(char s[],int lim)
{
    int c,i;
    
    for(i=0;i<lim-1 && ((c=getchar())!=EOF) && c!='\n';++i)
        s[i]=c;

    if(c=='\n')
    {
        s[i]=c;
        ++i;
    }
    s[i]='\0';

    return i;
}

int strend(char *s,char *t)
{
    int len;
    len=mystrlen(t);
    while(*s!='\0')
        ++s;
    --s;

    while(*t!='\0')
        ++t;
            
    --t;
    while(len > 0)
    {
        if(*t==*s)
        {
            --t;
            --s;
            --len;
        }
        else
            return 0;
    }
    if( len == 0)
        return 1;
}

int mystrlen(char *t)
{
    char *p;
    p=t;

    while(*p!='\0')
        ++p;

    return p-t;
    }
