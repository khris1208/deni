/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int getch1(void);
void ungetch1(int);
int getint(int *pn);

void q1(void)
{
    int n, s, array[SIZE];

    for (n = 0; n < SIZE; n++) {
        int result = getint(&array[n]);
        
        if (result == 0) {
            printf("Invalid Entry!!!\n");
            n--; // Prevent invalid entry from being counted
       break;
       	}

        else if (result == EOF) {
            break; // Stop reading if EOF is encountered
        } 
        else {
            printf("storing in n = %d, getint %d\n", n, array[n]);
        }
    }

    printf("Final value of n = %d\n", n);

    for (s = 0; s < n; s++)
        printf("%d ", array[s]);
    printf("\n");
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch1())) // Skip whitespace
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch1(c); // Not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int next = getch1();
        if (!isdigit(next)) { // If not a number, push back both characters
            ungetch1(next);
            ungetch1(c);
            return 0;
        }
        c = next;
    }

    for (*pn = 0; isdigit(c); c = getch1())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch1(c);

    return 1; // Successfully read a number
}

#define BUFSIZE 100
static char buf[100];
static int bufp = 0;
int getch1(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch1(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

