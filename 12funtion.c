/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 200
#define DEFAULT_M 1  // Default start column
#define DEFAULT_N 8  // Default tab width

void entab(int m, int n);
void detab(int m, int n);
void invalid_entry();
int get_number_input(const char *prompt);

void q12(void) {
    char mode[10];
    int m, n;

    // Ask for mode
    printf("Enter mode (entab/detab): ");
    scanf("%s", mode);

    // Get values for m and n
    m = get_number_input("Enter starting column (m) [default 1]: ");
    n = get_number_input("Enter tab width (n) [default 8]: ");

    // Consume newline
    getchar();

    // Call appropriate function
    if (strcmp(mode, "entab") == 0) {
        entab(m, n);
    } else if (strcmp(mode, "detab") == 0) {
        detab(m, n);
    } else {
        invalid_entry();
    }

    return 0;
}

// Function to replace spaces with tabs
void entab(int m, int n) {
    char input[MAXLINE];
    int space_count = 0, pos = 1;

    printf("Input: ");
    if (!fgets(input, MAXLINE, stdin)) return;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            space_count++;
            if ((pos >= m) && ((pos - m) % n == 0)) {
                putchar('\t');
                space_count = 0;
            }
        } else {
            while (space_count > 0) {
                putchar(' ');
                space_count--;
            }
            putchar(input[i]);
        }
        pos++;
    }
}

// Function to replace tabs with spaces
void detab(int m, int n) {
    char input[MAXLINE];
    int pos = 1;

    printf("Input: ");
    if (!fgets(input, MAXLINE, stdin)) return;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\t') {
            do {
                putchar('#');
                pos++;
            } while ((pos - m) % n != 0);
        } else {
            putchar(input[i]);
            pos++;
        }
    }
}

// Function to handle invalid input
void invalid_entry() {
    printf("Invalid Entry!!!\n");
}

// Function to get number input with default value
int get_number_input(const char *prompt) {
    int num;
    printf("%s", prompt);
    if (scanf("%d", &num) != 1) {
        num = (prompt[6] == 'm') ? DEFAULT_M : DEFAULT_N;  // Default based on prompt
    }
    return num;
}

