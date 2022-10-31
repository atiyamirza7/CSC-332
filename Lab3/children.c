// Atiya Mirza
// OS Lab 3
// Question 1

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int child_1 = fork(); // fork sys call for first child
    int status_1;         // int variable for waitpid status
    if (child_1 == 0) {   // first child process
        // use getpid() to retrieve PID
        printf("\nI am child one, my pid is: %d \n", getpid());
        return 0;

    } else {
        int child_2 = fork(); // fork sys call for second child
        int status_2;         // int variable for waitpid status
        if (child_2 == 0) {   // second child process 
            // use getpid() to retrieve PID
            printf("\nI am child two, my pid is: %d \n", getpid());
            printf("\n");
            return 0;

        } else { // guarantee that parent terminates after children terminate
            waitpid(child_1, &status_1, 0); // wait for second child process
        }
        waitpid(child_2, &status_2, 0);     // wait for first child process
    }
    return 0;
}
