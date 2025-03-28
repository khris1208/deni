/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
/*defining macros*/
#define MAXOP 100/*size of operator and operand*/
#define NUMBER '0'/*flag to identify number*/
#define BUFSIZE 100/*size of buffer for input*/
#define MAXVAL 100/*maximum size of stack*/
extern int sp;/*stack pointer*/
extern double val[MAXVAL];/*stack to hold value*/
extern char buf[BUFSIZE];/*buffer to store the characters*/
extern int bufp;/*pointer to current position in buffer*/
double pop(void);

/*making re_rpn_5_10 function*/
void q10(void)
{
        char s[MAXOP];/*holding operators and operands*/
        double op2;/*seconf operands*/
        char input[MAXOP];/*storing expression*/
 
        printf("Enter the expression: ");/*taking an expression form the user*/
        fgets(input, sizeof(input), stdin);/*resding the input*/
 
        char *token = strtok(input, " \t\n");/*tokenize input string by space, tab or newline*/
        while (token != NULL) {/*placing the token into buffer*/
                ungets(" ");
                ungets(token);
 
                switch (getop(s)) {
                        case NUMBER:
                                push(atof(s));
                                break;
 
                        case '+':
                                push(pop() + pop());
                                break;
 
                        case '*':
                                push(pop() * pop());
                                break;
 
                        case '-':
                                op2 = pop();
                                push(pop() - op2);
                                break;
 
                        case '/':
                                op2 = pop();
                                if (op2 != 0.0) {
                                        push(pop() / op2);
                                } else {
                                        printf("Cannot divide by zero!\n");
                                        return;
                                }
                                break;
 
                        default:
                                printf("Error! Unknown command %s found!\n", s);
                                return;
                }
 
                token = strtok(NULL, "  \t\n");/*getting next token from the input*/
        }
 
        printf("Result: %.6g\n", pop());
        /*printing the final input*/
}
int32_t getop(char s[])
{
        int32_t i = 0, c;
        while ((s[0] = c = getch()) == ' ' || c == '\t'); //skipping whictespace

        s[1] = '\0';
        if (!isdigit(c) && c != '.' && c != '-')
                return c;//not a number

        if (c == '-' || isdigit(c))
                while (isdigit(s[++i] = c = getch()));

        if (c == '.')
                while (isdigit(s[++i] = c = getch()));

        s[i] = '\0';
        if (c != EOF)
                ungetch(c);

        if (strcmp(s, "-") == 0)
                return '-';

        return NUMBER;
}
void ungets(char s[])

{

        int len = strlen(s);

        while (len > 0)

                ungetch(s[--len]);

}
 
double pop(void)
{
        if (sp > 0)
                return val[--sp];
        else {
                printf("Stack is empty: %d\n", sp);
                return 0.0;
        }
}

void push(double f)
{
        if (sp < MAXVAL)
                val[sp++] = f;
        else
                printf("Stack is full\n");
}
int32_t getch()
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int32_t c)
{
        if (bufp >= BUFSIZE)
                printf("ungetch: overflowed\n");
        else
                buf[bufp++] = c;
}
