#include <stdio.h>

// Recursive function to find the GCD
int gcd(int a, int b) {
    // Base case: GCD(a, 0) = a, GCD(0, b) = b
    if (b == 0) {
        return a;
    }

    // Recursive case: GCD(a, b) = GCD(b, a % b)
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    // Input two numbers from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Call the gcd function and print the result
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}




