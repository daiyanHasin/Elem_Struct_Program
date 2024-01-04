/*-----
Write a program where you take a sentence from keyboard and count the number of letters that are in
upper case without using indices.
----*/
#include <stdio.h>

int main() {
    char sentence[100];
    int count = 0;
    char ch;

    // Input a sentence from the user
    printf("Enter a sentence: ");

    // Read characters until Enter is pressed or the array is full
    while ((ch = getchar()) != '\n' && count < sizeof(sentence) - 1) {
        sentence[count] = ch;
        count++;
    }

    // Null-terminate the string
    sentence[count] = '\0';

    // Loop through each character in the sentence
    for (int i = 0; sentence[i] != '\0'; ++i) {
        // Check if the character is an uppercase letter
        if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
            count++;
        }
    }

    // Display output based on the count
    if (count % 2 == 1) {
        printf("Count is odd. \n");
        printf("Zubayer Ahmed.\n");  // Replace with your own name
    } else {
        printf("Count is even.\n");
        printf("0426.\n");  // Replace with your student ID
    }

    return 0;
}
