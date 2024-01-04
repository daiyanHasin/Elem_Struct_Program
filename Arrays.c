/*---
Write a program as part of the UCAM application that will store the Fall 2021 SPL final exam scores of
sections A, B, C, D, E, and F using a 2-D array. The maximum capacity for any section is 45 students. In
your program, initialize all the array values with (LAST_FOUR_DIGITS_OF_YOUR_STUDENT_ID % 11 +
10) values. Increment all the scores of section C by i10, where i is the index of the score.

---*/
#include <stdio.h>

// Constants for array dimensions
#define SECTIONS 6
#define MAX_STUDENTS 45

// Function to initialize array values
void initializeArray(int scores[][MAX_STUDENTS]);

int main() {
    // Set array dimensions
    int scores[SECTIONS][MAX_STUDENTS];

    // Initialize array values
    initializeArray(scores);

    // Increment scores of section C by i * 10
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        scores[2][i] += i * 10;
    }

    // Print the scores for each section
    printf("Fall 2021 SPL Final Exam Scores:\n");
    for (int section = 0; section < SECTIONS; ++section) {
        printf("Section %c: ", 'A' + section);
        for (int student = 0; student < MAX_STUDENTS; ++student) {
            printf("%d ", scores[section][student]);
        }
        printf("\n");
    }

    return 0;
}

// Function to initialize array values
void initializeArray(int scores[][MAX_STUDENTS]) {
    // Set a id based on the last four digits of the student ID
    int id = 0426; // Replace with your actual last four digits

    for (int section = 0; section < SECTIONS; ++section) {
        for (int student = 0; student < MAX_STUDENTS; ++student) {
            // Initialize array values using the specified formula
            scores[section][student] = (id % 11 + 10);
            id++;
        }
    }
}
