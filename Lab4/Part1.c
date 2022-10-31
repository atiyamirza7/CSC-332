// Atiya Mirza
// CSc 332 - Lab 4
// Part 1

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{    
    int child = fork(); // fork child
    int status; // var for waitpid status

    if (child == 0) { // child forked successfully 
        // use getpid() to display PID
        printf("\nChild forked successfully (pid: %d)\n", getpid());
        // use execl to display date and time
        execl("/bin/date", "date", NULL);

    } else { // wait for child process
        waitpid(child, &status, 0);
    }
    printf("\n");
    return 0;
}