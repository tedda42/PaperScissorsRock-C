#include <stdio.h>
#include <string.h>

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
  printf("User    : %s\n", userChoice);
  return 0;
}