/*---
Suppose we want to hire few employees for an uprising software company through online registration
and aptitude test selecting from 50 candidates. To register, a candidate will provide the information
mentioned in (i) below. When a candidate log on, his/her total marks will be shown on the screen.
Now, write a C program considering the above scenario and the following information:
(i) Design a structure of candidate which contains Name, Email, Password, and Test Marks. You
should declare appropriate data type for each variable. Initialize the members with default
values with your own name, email, and other appropriate information.
(ii) Take input for all the candidates in an array of candidates from keyboard. Array size =
LAST_FOUR_DIGIT_OF_YOUR_STUDENT_ID.
(iii) As part of the login process, use a login() function. In the function, take an email and a
password from user as credential. Find the candidate using these credentials from the array
of candidates. If any match is found, display the total marks of that candidate. If not found,
display “Wrong Email and/or Password”.
(iv) Call the login() function from the main function.
---*/
#include <stdio.h>
#include <string.h>

// Structure to represent a candidate
struct Candidate {
    char Name[50];
    char Email[50];
    char Password[20];
    int TestMarks;
};

// Function to perform login and display total marks
void login(struct Candidate candidates[], int size) {
    char email[50], password[20];

    printf("Enter Email: ");
    scanf("%s", email);
    printf("Enter Password: ");
    scanf("%s", password);

    // Check credentials and display total marks
    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(candidates[i].Email, email) == 0 && strcmp(candidates[i].Password, password) == 0) {
            printf("Welcome, %s! Your total marks: %d\n", candidates[i].Name, candidates[i].TestMarks);
            found = 1;
            break;
        }
    }

    // Display message if credentials are incorrect
    if (found == 0) {
        printf("Wrong Email and/or Password\n");
    }
}

int main() {
    // Set array size to the last four digits of your student ID
     int arraySize = 0426;  // Replace with your actual last four digits

    // Declare and initialize an array of candidates
    struct Candidate candidates[0426] = {
        {"John Doe", "john@example.com", "password123", 80},
        {"Jane Smith", "jane@gmail.com", "pass456", 75},
         {"Bob Johnson", "bob@yahoo.com", "secure789", 90}
        // Add more candidates with default values as needed
    };

    // Call the login function from the main function
    login(candidates, arraySize);

    return 0;
}

