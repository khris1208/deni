/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define MAXLINE 1000
#define MAXOP 100

int sp = 0; // Stack pointer
double val[MAXVAL]; // Stack
char buf[BUFSIZE]; // Buffer for getch4/ungetch4
int bufp = 0; // Buffer pointer

// Function declarations
int getch4(void);
void ungetch4(int);
int getop4(char *);
void push4(double);
double pop4(void);
int mgetline4(char *line, int max);
int strindex4(char *s, char *t);
int atoiv24(char *);
void itoav24(int n, char *s);
void reverse4(char *);

void display_menu() {
    printf("Select an option:\n");
    printf("1. Getline\n");
    printf("2. Atoi\n");
    printf("3. Itoa\n");
    printf("4. Reverse\n");
    printf("5. Strindex\n");
    printf("6. Reverse Polish Calculator\n");
    printf("7. Exit\n");
}

void q6(void) {
    while (1) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        char line[MAXLINE];
        int num;
        char s1[100];

        switch (choice) {
            case 1:
                printf("Input: ");
                mgetline4(line, MAXLINE);
                printf("Output: %s\n", line);
                break;
            case 2:
                printf("Input: ");
                scanf("%s", s1);
                num = atoiv24(s1);
                printf("Output: %d\n", num);
                break;
            case 3:
                printf("Input: ");
                if(!(scanf("%d", &num)))
		{
			printf("Enter the valid no.\n");
			while (getchar() != '\n');
			break;
		}
                itoav24(num, s1);
                reverse4(s1);
                printf("Output: %s\n", s1);
                break;
            case 4:
		char c;
		int i=0;
                printf("Input String: ");
                while((c=getchar())!=EOF && c!='\n' )
                {
                        s1[i++]=c;
                }
                s1[i]='\0';
                reverse4(s1);
		printf("Output:");
		for (int j=0;j<=i;j++)
			printf("%c", s1[j]);
		printf("\n");
                break;
            case 5: {
                char s2[MAXLINE], t[MAXLINE];
		char c;
		int i=0;
                printf("Input String: ");
                while((c=getchar())!=EOF && c!='\n'&& i < MAXLINE - 1 )
		{
			s2[i++]=c;
		}
		s2[i]='\0';
		int j=0;
		for (j=0;j<=i;j++) 
		{
        		s2[j]=tolower(s2[j]);
        		
    		}
		i=0;
		j=0;
                printf("Match: ");
                while((c=getchar())!=EOF&& c!='\n'&& i < MAXLINE - 1)
                {
                        t[i++]=c;
                }
                t[i]='\0';
		for (j=0;j<i;j++)
                {
                        t[j]=tolower(t[j]);
                        
                }
                i=0;
                int index = strindex4(s2, t);
                if (index != -1) 
		{
                     printf("Output: String \"%s\" found in \"%s\" at position %d\n", t, s2, index + 1);
                }  
		else  
		{
                  printf("Output: Not found\n");
    }
		break;
            }
            case 6: {
                printf("Enter Reverse Polish Notation expression (EOF to stop):\n");
                char s3[MAXOP];
                double op2;
                while ((num = getop4(s3)) != EOF) {
                    switch (num) {
                        case NUMBER:
                            push4(atof(s3));
                            break;
                        case '+':
                            push4(pop4() + pop4());
                            break;
                        case '*':
                            push4(pop4() * pop4());
                            break;
                        case '-':
                            op2 = pop4();
                            push4(pop4() - op2);
                            break;
                        case '/':
                            op2 = pop4();
                            if (op2 != 0.0)
                                push4(pop4() / op2);
                            else
                                printf("Error: Zero divisor\n");
                            break;
                        case '\n':
                            printf("Output: %.8g\n", pop4());
                            break;
                        default:
                            printf("Error: Unknown command %s\n", s3);
                            break;
                    }
                }
                break;
            }
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Reads a line into s and returns the length
int mgetline4(char *s, int lim) {
    int c;
    char *t = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

// Get next operator or operand
int getop4(char *s) {
    int c;
    while ((*s = c = getch4()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    if (isdigit(c))
        while (isdigit(*++s = c = getch4()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch4()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch4(c);
    return NUMBER;
}

// Converts string to integer
int atoiv24(char *s) {
    int n = 0,sign=1;
    while (*s==' ')
	   s++;
   if(*s=='-'||*s=='+')
   {
	   if(*s=='-')
	   {
		   sign=-1;
	   }
	   s++;
   }
   if(!isdigit(*s))
   {
                printf("Enter the valid no.\n");
   }
   while(isdigit(*s))
   {
	   n=n*10+(*s-'0');
	   s++;
   }
    return sign*n;
}

// Converts integer to string
void itoav24(int n, char *s)
{
    int i = 0, sign;
    if ((sign = n) < 0)
        n = -n;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
}

// Reverse string
void reverse4(char *s) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// Find index of t in s
int strindex4(char *s, char *t) {
    char *p = NULL, *temp;
    
    // Use strstr to find first occurrence
    temp = strstr(s, t);
    
    while (temp) {
        p = temp;  // Store the last occurrence found
        temp = strstr(temp + 1, t);  // Search for the next occurrence
    }
    
    if (p)
        return p - s;  // Return last occurrence index
    
    return -1;  // Not found
}

// Push onto stack
void push4(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: Stack full\n");
}

// Pop from stack
double pop4(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: Stack empty\n");
        return 0.0;
    }
}

// Get next character
int getch4(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push character back onto input
void ungetch4(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch4: too many characters\n");
    else
        buf[bufp++] = c;
void reverse4(char *s) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}}
