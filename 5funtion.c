/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include <stdio.h>
#include <string.h>

#define MAXSIZE 50

// strncpy: copy at most n characters of t to s
void my_strncpy(char *s, const char *t, size_t n) {
    size_t i;
    for (i = 0; i < n && t[i] != '\0'; i++) {
        s[i] = t[i];
    }
    for (; i < n; i++) {
        s[i] = '\0';
    }
}

// strncat: concatenate at most n characters of t to s
void my_strncat(char *s, const char *t, size_t n) {
    size_t i, len = strlen(s);
    for (i = 0; i < n && t[i] != '\0'; i++) {
        s[len + i] = t[i];
    }
    s[len + i] = '\0';
}

// strncmp: compare at most n characters of s and t
int my_strncmp(const char *s, const char *t, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            return s[i] - t[i];
        }
        if (s[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

void q5(void) {
    char s1[MAXSIZE], s2[MAXSIZE];
    int n, choice;

    printf("Enter first string S1: ");
    fgets(s1, MAXSIZE, stdin);
    s1[strcspn(s1, "\n")] = '\0';

    printf("Enter second string S2: ");
    fgets(s2, MAXSIZE, stdin);
    s2[strcspn(s2, "\n")] = '\0';

    printf("Choose the operation!\n");
    printf("1.) Copy string\n2.) Concatenate string\n3.) Compare string\n");
    scanf("%d", &choice);
    
    printf("Enter value of n: ");
    scanf("%d", &n);
    getchar(); // Consume newline character left by scanf

    if (choice == 1) {
        my_strncpy(s1, s2, n);
        printf("Result: %s\n", s1);
    } else if (choice == 2) {
        my_strncat(s1, s2, n);
        printf("Result: %s\n", s1);
    } else if (choice == 3) {
        int cmp_result = my_strncmp(s1, s2, n);
        if (cmp_result == 0) {
            printf("Result: match found\n");
        } else {
            printf("Result: no match\n");
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

