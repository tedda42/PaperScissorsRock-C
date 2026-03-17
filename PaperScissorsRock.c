#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

const char* compare(const char* c1, const char* c2) {
    if (strcmp(c1, c2) == 0) return "The result is a tie!";
    if (strcmp(c1, "rock") == 0)     return (strcmp(c2, "scissors") == 0) ? "rock wins!"     : "paper wins!";
    if (strcmp(c1, "paper") == 0)    return (strcmp(c2, "rock") == 0)     ? "paper wins!"    : "scissors wins!";
    if (strcmp(c1, "scissors") == 0) return (strcmp(c2, "paper") == 0)    ? "scissors wins!" : "rock wins!";
    return "Invalid choice!";
}

int main(void) {
    printf("Do you choose rock, paper or scissors?\n");

    char *line = NULL;
    size_t cap = 0;

    if (getline(&line, &cap, stdin) == -1) {
        printf("You didn't enter a value\n");
        return 1;
    }

    // strip trailing newline
    size_t len = strlen(line);
    if (len && line[len - 1] == '\n') line[len - 1] = '\0';

    const char *userChoice = line;

    srand((unsigned)time(NULL));
    float r = rand() / (float)RAND_MAX;

    const char *computerChoice =
        (r < 0.34f) ? "rock" :
        (r <= 0.67f) ? "paper" : "scissors";

    printf("User    : %s\n", userChoice);
    printf("Computer: %s\n", computerChoice);
    printf("%s\n", compare(userChoice, computerChoice));

    free(line);
    return 0;
}