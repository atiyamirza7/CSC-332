// Atiya Mirza
// CSc 332 - Lab 4
// Part 3: Step 3 & Step 4

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
  int status_1, status_2; // int vars for waitpid status
  int child_1, child_2;   // vars for child processes

  child_1 = fork();                                      // fork first child
  if (child_1 == 0) {                                    // fork successful 
    printf("\nI am Child 1, my pid is: %d\n", getpid()); // print PID
    char* argv[] = {"./Prcs_P1.exe", NULL};              // arguments list for execv command
    execv("./Prcs_P1.exe", argv);                        // execute Prcs_P1
    return 0;

  } else {                                             // wait for first child process
    waitpid(child_1, &status_1, 0);
  }

  sleep(2);

  child_2 = fork();                                      // fork second child
  if (child_2 == 0) {                                    // fork successful 
    printf("\nI am Child 2, my pid is: %d\n", getpid()); // print PID
    char* argv[] = {"./Prcs_P2.exe", NULL};              // arguments list for execv command
    execv("./Prcs_P2.exe", argv);                        // execute Prcs_P2
    return 0;

  } else {                                             // wait for second child process
    waitpid(child_2, &status_2, 0);
  }

  sleep(2); 
  printf("\nParent_Prcs is complete!\n\n");
  return 0;
}