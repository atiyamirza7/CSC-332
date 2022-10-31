// Atiya Mirza
// OS Lab 3
// Question 3

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{
    int S1, S2, S3; // to store the sum of each series

    int child_1 = fork(); // fork first child
    if (child_1 == 0) { // first child process
        S1 = 0;
        // series from 1 to 10 with difference 2 (odd numbers)
        for (int i = 1; i <= 10; i += 2) {
            S1 += i;
        }
        // child 1 prints result
        printf("\nI am Child 1. Sum of Series 1 (odd #'s) is %d\n", S1);

    } else {
        int child_2 = fork(); // fork second child
        if (child_2 == 0) { // second child process
            S2 = 0;
            // series from 2 to 10 with difference 2 (even numbers)
            for (int i = 2; i <= 10; i += 2) {
                S2 += i;
            }
            // child 2 prints result
            printf("\nI am Child 2. Sum of Series 2 (even #'s) is %d\n", S2);

        } else { // parent process
            int status_1, status_2; // int variable for waitpid status
            waitpid(child_1, &status_1, 0); // wait for first child process
            waitpid(child_2, &status_2, 0); // wait for second child process
            S3 = 0;
            // series from 1 to 10 with difference 1 (or S3 = S1+S2)
            for (int i = 1; i <= 10; i++) {
                S3 += i;
            }
            // parent prints result
            printf("\nI am Parent. Sum of Series 3 (S1 + S2) is %d\n", S3);
        }
    }
    return 0;
}