/*------
Write a program that takes a sentence from keyboard, makes the sentence camel/title casing (first letter of
all words capital), appends your id to the sentence as the last word, and finally display the sentence.
------*/
#include <stdio.h>
#include <ctype.h>

void camelCase(char sentence[], char id[]);

int main() {
    char sentence[100];
    char id[] = "0426";

    // Input a sentence from the user
    printf("Enter a sentence: ");
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < sizeof(sentence) - 1) {
        sentence[i] = ch;
        i++;
    }

    // Convert the sentence to camel/title case and append the ID
    camelCase(sentence, id);

    // Display the modified sentence
    printf("Modified Sentence: %s\n", sentence);

    return 0;
}

void camelCase(char sentence[], char id[]) {
    int i = 0;

    // Capitalize the first letter of the sentence
    if (sentence[i] >= 'a' && sentence[i] <= 'z') {
        sentence[i] = toupper(sentence[i]);
    }
    i++;

    // Loop through each character in the sentence
    while (sentence[i] != '\0') {
        // If the current character is a space
        if (sentence[i] == ' ') {
            // Capitalize the next letter
            i++;
            if (sentence[i] >= 'a' && sentence[i] <= 'z') {
                sentence[i] = toupper(sentence[i]);
            }
        } else {
            // Convert other letters to lowercase
            if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
                sentence[i] = tolower(sentence[i]);
            }
        }
        i++;
    }

    // Append the ID to the sentence as the last word
    while (sentence[i - 1] == ' ') {
        i--;
    }
    sentence[i] = ' ';  // Add a space before the ID
    i++;
    int j = 0;
    while (id[j] != '\0') {
        sentence[i] = id[j];
        i++;
        j++;
    }
    sentence[i] = '\0';  // Null-terminate the sentence
}
