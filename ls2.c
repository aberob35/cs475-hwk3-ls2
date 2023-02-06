#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ls2.h"
#include "stack.h"



// Global Variable Declarations 

// TODO: function definitions here for ls2
void recDirectoryOpenerM1(char *dName){
    //stack_t *s = initstack();
    //Creating necessary tools to traverse through directories
    char directPath[MAX_INPUT];
    struct dirent *dp;
    struct stat st;
    DIR *dir = opendir(dName);

    //Way to test to see if directory is accesible
    if(!dir){
        //printf("Input an actual directory \n");
        return;
    }
    
    //Recursion and Outputted messages 
    while ((dp = readdir(dir)) != NULL){
        if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name,".." ) != 0){
            lstat(dp->d_name, &st);
            int size = st.st_size;
            mode_t mode = st.st_mode;
            if(S_ISDIR(mode) != 0){
                //push(s, dp->d_name);
                printf("%s (%s) \n", dp->d_name, "Directory");
            }else{
                //push(s, dp->d_name);
                printf("%s (%d) \n", dp->d_name, size);
            }
            
            //Making a new direcotry path
            strcpy(directPath, dName);
            strcat(directPath, "/");
            strcpy(directPath, dp->d_name);
            recDirectoryOpenerM1(directPath);
        }
    }
    //Closing directory so no memeory leaks occur
    closedir(dir);
}

void recDirectoryOpenerM2(char *dName, char *fName){
    //Creating necessary tools to traverse through directories
    char directPath[MAX_INPUT];
    struct dirent *dp;
    struct stat st;
    DIR *dir = opendir(dName);

    //Way to test to see if directory is accesible
    if(!dir){
        //printf("Input an actual directory \n");
        return;
    }
    
    //Recursion and Outputted messages 
    while ((dp = readdir(dir)) != NULL){
        if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name,".." ) != 0){
            lstat(dp->d_name, &st);
            int size = st.st_size;
            mode_t mode = st.st_mode;
            if(S_ISDIR(mode) != 0){
                printf("%s (%s) \n", dp->d_name, "Directory");
            }else{
                if(strcmp(dp->d_name, fName) == 0){     
                    printf("%s (%d) \n", dp->d_name, size);
                }
            }
            
            //Making a new direcotry path
            strcpy(directPath, dName);
            strcat(directPath, "/");
            strcpy(directPath, dp->d_name);
            recDirectoryOpenerM2(directPath,fName);
        }
    }
    //Closing directory so no memeory leaks occur
    closedir(dir);
}
