/*---
Write a program that performs the following operations.
(a) Use a user-defined function “search” that takes four parameters: (i) an array of float values, (ii) a
value to search, (iii) an int value n - number of values in the array, and (iv) an int number r.
The “search” function finds the rth occurrence of that value in the array. If found, returns the index. If
not found, returns -1.
(b) In the main function: i) Call the function “search” passing an array, a value to search, and an int a,
where a = LAST_FOUR_DIGIT_OF_YOUR_STUDENT_ID % 10. ii) If found, display the value and the
index. If not found, display “Not Found”. (iii) Do all the necessary declarations, initialization, and input
of variables as required.
(c) Add appropriate prototypes of the function.
---*/
#include <stdio.h>

// Function prototype
int search(float array[], float value, int n, int r);

int main() {
    // Set array size to the last digit of your student ID
     int arraySize = 0426;  // Replace with your actual last digit

    // Declare and initialize an array of float values
    float values[4] = {3.14, 2.718, 1.618, 0.577};

    // Declare variables
    float searchValue;
    int result, occurrence;

    // Input value to search and occurrence from the user
    printf("Enter the value to search: ");
    scanf("%f", &searchValue);
    printf("Enter the occurrence to find: ");
    scanf("%d", &occurrence);

    // Call the search function
    result = search(values, searchValue, arraySize, occurrence);

    // Display the result
    if (result != -1) {
        printf("Value %.3f found at index %d (occurrence %d)\n", searchValue, result, occurrence);
    } else {
        printf("Value %.3f not found\n", searchValue);
    }

    return 0;
}

// Function to search for the rth occurrence of a value in an array
int search(float array[], float value, int n, int r) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (array[i] == value) {
            count++;

            if (count == r) {
                return i;  // Return the index of the rth occurrence
            }
        }
    }

    return -1;  // Value not found
}

