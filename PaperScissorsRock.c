#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char* compare(char* choice1, char* choice2) {
    if (strcmp(choice1,choice2) == 0) {
        return "The result is a tie!";
//    } else if (choice1.equals("rock")) {
//        if (choice2.equals("scissors")) {
//            return "rock wins!";
//        } else {
//            return "paper wins!";
//        }
//    } else if (choice1.equals("paper")) {
//        if (choice2.equals("rock")) {
//            return "paper wins!";
//        }
//        else {
//            return "scissors wins!";
//        }
//    } else if (choice1.equals("scissors")) {
//        if (choice2.equals("rock")) {
//            return "rock wins!";
//        } else {
//            return "scissors wins!";
//        }
    } else {
        char* result;
        strcpy(result, "Invalid choice '");
        strcat(result, choice1);
        strcat(result, "'");
        return result;
    }
}

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

  char* result = compare(userChoice, computerChoice);
  printf("%s\n", result);
  return 0;
}
