// Lab 2: File Management System Calls
// Atiya Mirza
// CSC 332
// Question 1a

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char* argv[]) 
{
    char* filepath = argv[1];
    int returnval;

    // Check file existence
    returnval = access (filepath, F_OK);
    if (returnval == 0)
        printf ("\n %s exists\n", filepath);
    else // System call passes the error code to errno 
    {
        if (errno == ENOENT)  // ENOENT means no such file or directory
            printf ("%s does not exist\n", filepath);
        else if (errno == EACCES)
            printf ("%s is not accessible\n", filepath);
        return 0;
    }

    // Check read access
    returnval = access (filepath, R_OK); // R_OK checks for read permissions
    if (returnval == 0) {
        printf("\n %s read access approved\n", filepath);
    }
    else {
        printf("\n %s read access denied\n", filepath);
    }

    // Check write access
    returnval = access(filepath, W_OK); // W_OK checks for write permissions
    if (returnval == 0) {
        printf("\n %s write access approved\n", filepath);
    }
    else {
        printf("\n %s write access denied\n", filepath);
    }
    return 0;
}