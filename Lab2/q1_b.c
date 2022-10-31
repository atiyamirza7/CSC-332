// Lab 2: File Management System Calls
// Atiya Mirza
// CSC 332
// Question 1b

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    // Arg file
    char *fp = argv[1];
    int fileP;
    // Use bitwise OR flag to either create or open file
    // Assign full permissions for file (to be used in later lab questions)
    fileP = open(fp, O_RDWR | O_CREAT, 0777);
    if (fileP == -1) { // Check if error/fail occurs
        printf("Error is open() \n"); 
        return 1;
    }
    else { // File open is success, read operations can be performed now 
        printf("Open() Successful\n");
        // Close file when done 
        close(fileP);
    }
    return 0;
}