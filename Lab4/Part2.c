// Atiya Mirza
// CSc 332 - Lab 4
// Part 2

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    int child = fork(); // fork child
    int status; // var for waitpid status
    char *argv[] = {"ls", "-la", NULL}; // uses -la command to list files

    if (child == 0) { // child forked successfully
      // use getpid() to display PID
      printf("\nChild forked successfully! Pid is %d\n", getpid());
      // use execvp to display all files
      execvp(argv[0], argv);

    } else { // wait for child process
      waitpid(child, &status, 0);
    }
    printf("\n");
    return 0;
}