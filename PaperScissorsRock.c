#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("Do you choose rock, paper or scissors?\n");
  char *line = NULL;
  size_t size;
  if (getline(&line, &size, stdin) == -1) {
      printf("You didn't enter a value\n");
      return 1;
  }
  char userChoice[strlen(line)-1];
  strncpy(userChoice, line, strlen(line)-1);

  srand(time(NULL));
  float computerChoiceRand = rand()/(float)RAND_MAX;

  char* computerChoice;

  if (computerChoiceRand < 0.34) {
      computerChoice = "rock";
  } else if (computerChoiceRand <= 0.67) {
      computerChoice = "paper";
  } else {
      computerChoice = "scissors";
  }


  printf("User    : %s\n", userChoice);
  printf("Computer: %s\n", computerChoice);
  return 0;
}