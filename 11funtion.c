/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 200

void encode(int n);
void decode(int n);
void invalid_usage();
void invalid_entry();

void q11(void) {
    char mode[10];
    int n;

    // Ask user for mode (en/de)
    printf("Enter mode (en for encode, de for decode): ");
    scanf("%s", mode);

    // Ask user for number n
    printf("Enter a number (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        invalid_entry();
        return 1;
    }

    // Consume newline left in buffer
    getchar();

    // Check if mode is valid
    if (strcmp(mode, "en") == 0) {
        encode(n);
    } else if (strcmp(mode, "de") == 0) {
        decode(n);
    } else {
        invalid_entry1();
    }

    return 0;
}

// Encoding function
void encode(int n) {
    char input[MAXLINE];

    printf("Input: ");
    if (!fgets(input, MAXLINE, stdin)) return;

    int count = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '*') {
            count++;
            if (count % n == 0) {
                putchar(' ');
            } else {
                putchar('*');
            }
        } else if (input[i] == '\t') {
            putchar(' ');
        } else {
            putchar(input[i]);
        }
    }
}

// Decoding function
void decode(int n) {
    char input[MAXLINE];

    printf("Input: ");
    if (!fgets(input, MAXLINE, stdin)) return;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\t') {
            printf("**");
        } else {
            putchar(input[i]);
        }
    }
}

// Invalid entry message
void invalid_entry1() {
    printf("Invalid Entry!!!\n");
}

