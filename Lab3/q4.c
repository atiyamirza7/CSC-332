// Atiya Mirza
// OS Lab 3
// Question 4

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) 
{
    // declarations
    int fd;
    char* filename = argv[1];
    int pipefd[2];
    pipe(pipefd); // pipe file descriptors 

    // fork child
    int child = fork();
    // fork is successful 
    if (child == 0) { // child process
        close(pipefd[0]); // close read end of the pipe
        errno = 0; // for error handling 
        fd = open(filename, O_RDONLY); // open file in read only
        // check for errors 
        if (fd == -1) {
            if (errno == ENOENT) { // file does not exist
                printf ("%s does not exist\n", filename);
                perror("open"); // prints error explanation
            }
            else if (errno == EACCES) { // no read permissions
                printf ("%s cannot be accessed\n", filename);
                perror("open"); // prints error explanation
            }
            return 1;
        }
        char buffer[1]; // buffer to store char read from file
        while (read(fd, buffer, 1)) {
            // write the buffer to be read to the write end of the pipe
            write(pipefd[1], buffer, 1);
        }
        close(fd); // close file
        close(pipefd[1]); // close write end of the pipe

    } else if (child > 0) { // parent process
        int status; // int variable for waitpid status
        waitpid(child, &status, 0); // wait for child process
        close(pipefd[1]); // close write end of the pipe
        errno = 0; // for error handling
        fd = open(filename, O_WRONLY | O_APPEND); // open file in write only
        // check for errors
        if (fd == -1) {
            if (errno == EACCES) { // no write permissions
                printf ("%s cannot be accessed\n", filename);
                perror("open"); // prints error explanation
            }
            return 1;
        }
        // parent will append to readme.txt using the read end of the pipe
        char buffer[1]; // buffer to hold char read from file
        write(fd, "\n\nParent is writing:\n", 21);
        while (read(pipefd[0], buffer, 1)) {
            // write the buffer onto the file
            write(fd, buffer, 1);
        }
        close(fd); // close file
        close(pipefd[0]); // close read end of the pipe
    }
    return 0;
}