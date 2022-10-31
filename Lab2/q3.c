// Lab 2: File Management System Calls
// Atiya Mirza
// CSC 332
// Question 3

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    // First arg file 
    char *sourceFile = argv[1];
    // Second arg file
    char *destinationP = argv[2];

    // Check file existence
    int doesExist = access(sourceFile, F_OK); // Takes in file name
    if (doesExist != 0) // Check if file can be opened without error
    {
        perror("Error"); // File does not exist
        return 0;
    }

    // Open file in read mode only
    int fdSource = open(sourceFile, O_RDONLY);
    if (fdSource == -1) // Check for errors
    {
        perror("Error");
        return 1;
    }

    // Create another text file if first file name does not exist
    // If first file name does exist, continue on and perform write sys calls
    int fdDestination = open(destinationP, O_WRONLY | O_CREAT, 0777);
    if (fdDestination == -1) // Check for errors
    {
        perror("Error");
        return 1;
    }

    // Copy existing content in source file to destination file 
    char buff[1];
    do
    {
        write(fdDestination, buff, 1);
    } while (read(fdSource, buff, 1));
    
    // Close files when done
    close(fdSource); 
    close(fdDestination);
    return 0;
}