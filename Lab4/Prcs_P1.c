// Atiya Mirza
// CSc 332 - Lab 4
// Part 3: Step 1

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  // create two files with read, write, and execute permissions
  int fd1 = open("./destination1.txt", O_RDWR | O_CREAT, 0777);
  int fd2 = open("./destination2.txt", O_RDWR | O_CREAT, 0777);

  // check if error occurs
  if (fd1 == -1) {
    printf("Error: Unable to create new file\n");
    return 1;
  }
  else {
    printf("destination1.txt successfully created!");
    // close file when done 
    close(fd1);
  }

  if (fd2 == -1) {
    printf("Error: Unable to create new file\n");
    return 1;
  }
  else {
    printf("\ndestination2.txt successfully created!\n");
    // close file when done 
    close(fd2);
  }

  return 0;
}