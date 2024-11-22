#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int RN, UserGuess, attempts = 0;
    srand(time(0));
    RN = (rand() % 100) + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &UserGuess);

        attempts++;

        if (UserGuess > RN) {
            printf("Too high! Try again.\n");
        } else if (UserGuess < RN) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed it in %d attempts.\n", attempts);
        }
    } while (UserGuess != RN);

    return 0;
}

