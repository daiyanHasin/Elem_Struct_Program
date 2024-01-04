#include <stdio.h>

int main() {
    FILE *file;
    int num, sum = 0, count = 0;

    // Open the file for reading
    file = fopen("Sample.txt", "r");

    // Check if the file is successfully opened
    if (file == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1; // Return an error code
    }

    // Read numbers from the file and calculate the sum and count
    while (fscanf(file, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    // Close the file
    fclose(file);

    // Check if any numbers were read
    if (count > 0) {
        // Calculate and print the average
        double average = (double)sum / count;
        printf("Average of numbers: %.2lf\n", average);
    } else {
        printf("No numbers found in the file.\n");
    }

    return 0;
}
