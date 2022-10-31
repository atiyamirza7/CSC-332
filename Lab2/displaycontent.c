// Lab 2: File Management System Calls
// Atiya Mirza
// CSC 332
// Question 2

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    // Arg File
    char *filepath = argv[1];

    // Check file existence
    int doesExist = access(filepath, F_OK);

    if (doesExist != 0) // Check if file can be opened without error
    {
        perror("Error, file cannot be opened."); // File does not exist
        return 0;
    }
    else if (access(filepath,X_OK)) { // Check if user can access file 
        printf("The file %s is not accessible\n", filepath);
    }
    else if (access(filepath,R_OK)) { // Check read permissions 
        printf("There are no read permissions for the current user.");
    }
    else {
        int fd = open(filepath, O_RDONLY); // Open file with read only access
        char buf[1];
        while (read(fd, buf,1)) // While loop to display content of file
        {
            printf("%s", buf);
        }
        close(fd); // Close file when done
    }
    printf("\n");
    return 0;
}