/*
WAP to take two string inputs from the user-first one is the main string, and the latter is the substring. Then, find if the substring occurred in the main string.
---*/
#include <stdio.h>

// Function to calculate the length of a string
int strlen(const char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    // Declare variables
    char mainString[100], subString[50];

    // Input main string
    printf("Mainstring: ");
    scanf("%s", mainString);

    // Input substring
    printf("Substring: ");
    scanf("%s", subString);

    // Find if the substring occurs in the main string
    int mainLen = strlen(mainString);
    int subLen = strlen(subString);
    int found = 0;

    for (int i = 0; i <= mainLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (mainString[i + j] != subString[j]) {
                break;
            }
        }
        if (j == subLen) {
            found = 1;
            break;
        }
    }

    // Output the result
    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}

