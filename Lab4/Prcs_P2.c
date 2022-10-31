// Atiya Mirza
// CSc 332 - Lab 4
// Part 3: Step 2

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <string.h> 

int main()
{
    int source = open("source.txt", O_RDONLY);     // open source file in read mode
    int fd1 = open("./destination1.txt", O_RDWR);  // open destination1 file
    int fd2 = open("./destination2.txt", O_RDWR);  // open destination2 file

    char buffer1[100];  // buffer to hold char read from source file for dest1
    char buffer2[50];   // buffer to hold char read from source file for dest2
    int rd1, rd2;       // stores the number of chars read
    int flag;           // flag to distinguish between 100 char and 50 char read

    do { 
        // read next 100 chars from source, replace '1' with 'L', write in destination1.txt
        while(flag == 0 && (rd1 = read(source, buffer1, 100))) {
            // check which character is '1'
            for (int i = 0; i < rd1; i++) {
                char c[1];
                c[0] = buffer1[i];
                if (c[0] == '1') {      // '1' is found
                    write(fd1, "L", 1); // replace '1' with 'L'
                } else {                // '1' is not found
                    write(fd1, c, 1);   // no replacement occurs
                }
            }
            flag = 1; // set flag to 1 for the next read (50 char read)
        }

        // read next 50 chars from source, replace '3' with 'E', write in destination2.txt
        while(flag == 1 && (rd2 = read(source, buffer2, 50))) {
            // check which character is '3'
            for (int i = 0; i < rd2; i++) {
                char c[1];
                c[0] = buffer2[i];
                if (c[0] == '3') {      // '3' is found
                    write(fd2, "E", 1); // replace '3' with 'E'
                } else {                // '3' is not found
                    write(fd2, c, 1);   // no replacement occurs
                }
            }
            flag = 0; // set flag to 0 for the next read (100 char read)
        }
    } while (rd1 && rd2); // keep repeating until the end of source file

    // close files when done
    close(source);
    close(fd1);
    close(fd2);
    printf("source.txt content successfully copied!\n");
    return 0;
}