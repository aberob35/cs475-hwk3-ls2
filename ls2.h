#ifndef LS2_H_INCLUDED
#define LS2_H_INCLUDED

#include "stack.h"
#include <unistd.h>
#include <sys/stat.h>

#define TRUE 1
#define FALSE 0
#define INDENT "    "

// TODO: Function declarations here for ls2
void recDirectoryOpenerM1(char *dName);
void recDirectoryOpenerM2(char *dName, char *fName);

#endif
