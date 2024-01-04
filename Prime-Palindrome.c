/*-----
In the bustling metropolis of Primeville, a "Superhero Palindromic Prime" is a prime number with a secret power: it remains unchanged even when its digits are reversed, just like the identity of a true superhero. For instance, numbers like 131 and 757 possess this extraordinary ability.
Your mission is to create a program that identifies and unveils all the hidden Superhero Palindromic Prime numbers within a given range. Channel your inner superhero and construct your code using the following components:
a. int is_prime(int x): This function serves as your prime power detector, taking an integer x as input and returning 1 (or a true value) if x is prime, and 0 otherwise.
b. int reverse_number(int x): This function possesses the power of time manipulation, accepting an integer x and returning the number obtained by reversing the order of its digits. You must write this function using recursion.
c. int is_palindromic_prime(int x): This function takes an integer x as input and returns 1 (or true) if x is a palindromic prime number (retains its form when its digits are reversed and also prime), and 0 otherwise. You should make function calls to functions (a) and (b) in this function.
d. void find_superhero_palindromic_primes(int start, int end): This function prints all Superhero Palindromic Prime numbers hidden within the range [start, end].
----*/
#include <stdio.h>

// Function to check if a number is prime
int is_prime(int x) {
    if (x < 2) {
        return 0;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to reverse the order of digits in a number using recursion
int reverse_number(int x, int reversed) {
    if (x == 0) {
        return reversed;
    }
    return reverse_number(x / 10, reversed * 10 + x % 10);
}

// Function to check if a number is a palindromic prime
int is_palindromic_prime(int x) {
    return is_prime(x) && x == reverse_number(x, 0);
}

// Function to find and display  Palindromic Primes in a given range
void find_superhero_palindromic_primes(int start, int end) {
    printf("Palindromic Primes in the range [%d, %d]:\n", start, end);

    for (int i = start; i <= end; i++) {
        if (is_palindromic_prime(i)) {
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

    // Find and display Superhero Palindromic Primes
    find_superhero_palindromic_primes(start, end);

    return 0;
}
