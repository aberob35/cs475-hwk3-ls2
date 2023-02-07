#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ls2.h"
#include "stack.h"

// Global Variable Declarations
int counter = 0;
// TODO: function definitions here for ls2
/**
 * @param name of directory to parse
 * This recurses through directories and outputs all subdirectories and the files in them
 * 
 */

void recDirectoryOpenerM1(char *dName)
{
    // Creating necessary tools to traverse through directories
    char *directPath;
    struct dirent *dp;
    struct stat st;
    DIR *dir = opendir(dName);

    // Way to test to see if directory is accesible
    if (!dir)
    {
        // printf("Input an actual directory \n");
        return;
    }

    // Recursion and Outputted messages
    while ((dp = readdir(dir)) != NULL)
    {
        directPath = malloc(strlen(dName) + strlen(dp->d_name) + 2);

        // Making a new direcotry path
        strcpy(directPath, dName);
        strcat(directPath, "/");
        strcat(directPath, dp->d_name);

        // helper to get size in bytes
        lstat(dp->d_name, &st);
        int size = st.st_size;
        mode_t mode = st.st_mode;

        if (S_ISDIR(mode) != 0)
        {
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
            {
                // push(s, dp->d_name);
                for (int i = 0; i < counter; i++)
                {
                    printf("\t");
                }
                counter++;
                printf("%s/ (%s) \n", dp->d_name, "Directory");
                recDirectoryOpenerM1(directPath);
                counter--;
            }
        }
        else if (S_ISREG(mode))
        {
            for (int i = 0; i < counter; i++)
            {
                printf("\t");
            }
            printf("%s (%d) \n", dp->d_name, size);
        }
        free(directPath);
    }
    // Closing directory so no memeory leaks occur
    closedir(dir);
}


/**
 * @param dName name of directory to parse.
 * @param fname specific file name to get see if directories have. 
 * 
 */
void recDirectoryOpenerM2(char *dName, char *fname){
    // Creating necessary tools to traverse through directories
    char *directPath;
    struct dirent *dp;
    struct stat st;
    DIR *dir = opendir(dName);
    // stack_t *s = initstack();

    //Way to test to see if directory is accesible
    if (!dir)
    {
        return;
    }

    // Recursion and Outputted messages
    while ((dp = readdir(dir)) != NULL){
        directPath = malloc(strlen(dName) + strlen(dp->d_name) + 2);

        // Making a new direcotry path
        strcpy(directPath, dName);
        strcat(directPath, "/");
        strcat(directPath, dp->d_name);

        // helper to get size in bytes
        lstat(directPath, &st);
        int size = st.st_size;
        mode_t mode = st.st_mode;

        if (S_ISDIR(mode) != 0){
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
               char *directPath2 = malloc(strlen(directPath) + strlen(fname) + 2);

                // Making a new direcotry path
                strcpy(directPath2, directPath);
                strcat(directPath2, "/");
                strcat(directPath2, fname);

                if(stat(directPath2, &st) == 0){
                    for (int i = 0; i < counter; i++)
                {
                    printf("\t");
                }
                counter++;
                printf("%s/ (%s) \n", dp->d_name, "Directory");
                recDirectoryOpenerM2(directPath, fname);
                counter--;
                } else{
                recDirectoryOpenerM2(directPath, fname);
                }
                free(directPath2);
               
            }
        // if it is a file then print out file
        }else if (S_ISREG(mode)){
            if (strcmp(dp->d_name, fname) == 0){
                for (int i = 0; i < counter; i++)
                {
                    printf("\t");
                }
                printf("%s (%d) \n", dp->d_name, size);
            }
        }
        // free data so no leaks occur
        free(directPath);
    }
    // Closing directory so no memeory leaks occur
    closedir(dir);
}
