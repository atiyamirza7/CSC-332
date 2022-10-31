// Lab 2: File Management System Calls
// Atiya Mirza
// CSC 332
// Question 4

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
        perror("Error"); // File DNE
        return 0;
    }

    // Open file in read mode only
    int fdSource = open(sourceFile, O_RDONLY);
    if (fdSource == -1) // Check for errors
    {
        perror("Error");
        return 1;
    }

    // Use bitwise flag to either open the file or create new file with all permissions
    // Create another text file if first file name does not exist
    // If first file name does exist, continue on and perform write sys calls
    int fdDestination = open(destinationP, O_WRONLY | O_CREAT, 0777);
    if (fdDestination == -1) // Check for errors
    {
        perror("Error");
        return 1;
    }

    // Begin copying and replacing parts of file content
    char buf[100], temp;
    int count = 0;
    do
    {
        count = 0;
        for (int i = 0; i < 100; i++) // For every 100 characters from source.txt we read... 
        {
            if (read(fdSource, &temp, 1)) // Continue to read file
            {
                count++;
                if (temp == '1') // Search for all 1's and replace with L
                    buf[i] = 'L';
                else
                    buf[i] = temp;
            }
            else
            {
                break; 
            }
        }
        write(fdDestination, buf, count); // For every 100 read characters, we write into the file...
        write(fdDestination, "XYZ", 3); // Write XYZ every 100 characters
    } while (count == 100);

    // Close files when done
    close(fdSource);
    close(fdDestination);
    return 0;
}