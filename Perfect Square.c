/*---
In the mystical land of Digitaria, a "Perfect Square Sorcerer" is a number that possesses an enchanting quality: it's a perfect square and its digits are arranged in non-decreasing order. These magical numbers, such as 16, 112225, and 1444, hold a captivating spell that fascinates mathematicians.
Your quest is to write a program that reveals all the hidden wonders of Perfect Square Sorcerers within a given range. Equip yourself with the following components to embark on this numerical adventure:
a. int is_perfect_square(int x): This function takes an integer x as input and returns 1 (or true) if it's a perfect square, and 0 otherwise.
b. int are_digits_non_decreasing(int x,int prev_digit): This function takes an integer x as input and returns 1 (or true) if its digits are arranged in non-decreasing order, and 0 otherwise.You must write this function using recursion.
c. int check_are_digits_non_decreasing(int x): This is a helper function which will start the recursive call by calling the function are_digits_non_decreasing()
d. void find_perfect_square_sorcerers(int start, int end): This function prints all the Perfect Square Sorcerers that lie within the range [start, end].
----*/
#include <stdio.h>
#include <math.h>

int is_perfect_square(int x) {
    int sqrt_x = sqrt(x);
    return (sqrt_x * sqrt_x == x);
}

int are_digits_non_decreasing(int x, int prev_digit) {
    if (x == 0) {
        return 1;
    }

    int current_digit = x % 10;

    if (current_digit > prev_digit) {
        return 0;
    }

    return are_digits_non_decreasing(x / 10, current_digit);
}

int check_are_digits_non_decreasing(int x) {
    return are_digits_non_decreasing(x, 9);
}

void find_perfect_square_sorcerers(int start, int end) {
    printf("Perfect Square Sorcerers in the range [%d, %d]:\n", start, end);

    for (int i = start; i <= end; i++) {
        if (is_perfect_square(i) && check_are_digits_non_decreasing(i)) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int start, end;

    // Input range
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);

    // Find and print Perfect Square Sorcerers
    find_perfect_square_sorcerers(start, end);

    return 0;
}

