// Atiya Mirza
// OS Lab 3
// Question 2

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() 
{
    // parent P
	int a=10, b=25, fq=0, fr=0;
	fq = fork();  // fork a child - call it Process Q
	if (fq == 0) { // Child successfully forked
        // process Q 
		a = a+b;
        printf("Values of a, b, and process_id are: %d, %d, %d\n\n", a, b, getpid());
		fr = fork(); // fork another child - call it Process R
		if (fr != 0) {
            // process Q continues
			b = b+20;
            printf("Values of a, b, and process_id are: %d, %d, %d\n\n", a, b, getpid());
		}
		else { 
            // process R
			a = (a*b)+30;
            printf("Values of a, b, and process_id are: %d, %d, %d\n\n", a, b, getpid());
		}
	}
	else {
        // parent process P
		b = a+b-5;
        printf("Values of a, b, and process_id are: %d, %d, %d\n\n", a, b, getpid());
	}
	return 0;
}