/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 10
#define BUFFERSIZE 100

static char buf[BUFFERSIZE]; // Fixed buffer size
static int bufp = 0;         // Buffer position

// Get character from buffer or input stream
int getch2(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push character back into input buffer
void ungetch2(int c)
{
    if (bufp >= BUFFERSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

// Function to read a float value from input
int getfloat2(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch2())) // Skip whitespace
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch2(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int next = getch2();
        if (!isdigit(next) && next != '.') { // Ensure valid number follows +/-  
            ungetch2(next);  // Fixed incorrect function call
            ungetch2(c);  
            return 0;
        }
        c = next;
    }

    for (*pn = 0.0; isdigit(c); c = getch2()) // Read integer part
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.') {
        c = getch2();
        if (!isdigit(c)) { // Ensure decimal point is followed by digits
            ungetch2(c);
            ungetch2('.');
            return 0;
        }
    }

    for (power = 1.0; isdigit(c); c = getch2()) { // Read fractional part
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }

    *pn = (*pn * sign) / power; // Apply sign and scale

    if (c != EOF)
        ungetch2(c);

    return 1; // Successful conversion
}

void q2(void)
{
    int n;
    float array[MAXSIZE];

    for (n = 0; n < MAXSIZE; n++) {
        int result = getfloat2(&array[n]);

        if (result == 0) {
            printf("Invalid Entry!!!\n");
            n--; // Don't count invalid entries
        } else if (result == EOF) {
            break; // Stop if EOF is encountered
        } else {
            printf("%10.6f\n", array[n]); // Right-aligned, 6 decimal places
        }
    }
}
