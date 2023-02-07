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
	printf("Contents inside of directory \n");
	if(argc == 2){
		recDirectoryOpenerM1(argv[1]);
	}else if(argc == 3){
		recDirectoryOpenerM2(argv[1], argv[2]);
	} else if(argc > 3 ){
		printf("Too many things to search for");
	} else if(argc <= 1){
		printf("Too little things to search for");
	}
	
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
