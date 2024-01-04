/*-----
Tanjiro Kamado wants to eliminate as many demons as possible to make a better world for us. Every demon in our world can be presented as an element of an array of structure. Like,
struct demons {
char name[60]; // Name of a demon int power; // Power of a demon
};
But he needs to fulfill two conditions before eliminating a demon. The conditions are:
a. A demon has power multiple of 5, and
b. A demon's name contains only English alphabets.
Tanjiro can only eliminate a demon who has power multiple of 5 and who has only English alphabets in his name. Like, if a demon has “Kute” as a name and power as 10 then Tanjiro can eliminate that demon. But if a demon has a name “Ku+e” as a name or power as 9 then Tanjiro can not eliminate that demon.
So your task is to find how many demons our Tanjiro can eliminate. Your implementation must have these two functions:
a) int onlyAlphabets(char *input) : This function returns 1 if the demon's name has only alphabets as letters ( they can be capital or small letters) or return 0 otherwise.
b) int Multiple_of_5(int x) : This function returns 1 if the demon’s power is multiple of 5. Returns 0 otherwise.
----*/

#include <stdio.h>
#include <ctype.h>

struct demons {
    char name[60];
    int power;
};

// Function to check if a demon's name has only alphabets
int onlyAlphabets(char *input) {
    while (*input != '\0') {
        if (!isalpha(*input)) {
            return 0;
        }
        input++;
    }
    return 1;
}

// Function to check if a demon's power is a multiple of 5
int Multiple_of_5(int x) {
    return (x % 5 == 0);
}

int main() {
    int numDemons;
    printf("Enter the number of demons: ");
    scanf("%d", &numDemons);

    struct demons demonList[numDemons];

    // Input demon details
    for (int i = 0; i < numDemons; i++) {
        printf("Enter the name of demon %d: ", i + 1);
        scanf("%s", demonList[i].name);

        printf("Enter the power of demon %d: ", i + 1);
        scanf("%d", &demonList[i].power);
    }

    // Count demons that Tanjiro can eliminate
    int countEliminated = 0;
    for (int i = 0; i < numDemons; i++) {
        if (onlyAlphabets(demonList[i].name) && Multiple_of_5(demonList[i].power)) {
            countEliminated++;
        }
    }

    // Display the result
    printf("Tanjiro can eliminate %d demons.\n", countEliminated);

    return 0;
}

