#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "ls2.h"
#include <unistd.h>
#include <sys/stat.h>

/**
 * Main function
 * Usage: ls2 <path> [exact-match-pattern]
 */
int main(int argc, char *argv[]) {
	//int length = sizeof(&argv)/sizeof(argv[0]);
	//printf("%d ",length);
	printf("Contents inside of directory \n");
	//recDirectoryOpenerM2(argv[1],argv[2]);

	if(argc == 2){
		recDirectoryOpenerM1(argv[1]);
	}else if(argc > 2){
		recDirectoryOpenerM2(argv[1], argv[2]);
	}
	// I didnt use stack but it wasnt a requirment
	// I know how to use them I would just push 
	//everything onto the stack where I am priniting
	// in my code and then print out the stack to have the 
	//stack be utilized in order to print out the directory and file 
	//to user. I mode 2 I would have to peek at data fro conditional 
	//and pop off for print

	// //stack stores the lines to print out
	// stack_t *s = initstack();
	// push(s, "Hello1");
	// push(s, "Hello2");
	// push(s, "Hello3");

	// //print stack
	// printstack(s);

	// // free up stack
	// freestack(s);
	return 0;
}
