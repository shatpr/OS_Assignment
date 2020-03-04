#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#define NO_OF_STRING 50
#define MAX_STRING_SIZE 100
#define MAX_BLOCK 130
<<<<<<< Updated upstream
#define NO_OF_VCB 50
#define FALSE 0
#define TRUE !(FALSE)
=======
>>>>>>> Stashed changes

struct node{
    int index;
    int blockNo;
<<<<<<< Updated upstream
    int data; 
=======
    char data[MAX_STRING_SIZE];
>>>>>>> Stashed changes
    int filename;
}node[MAX_BLOCK];


int blockSize;
float noOfBlocks;
char CSV_Data[NO_OF_STRING][MAX_STRING_SIZE];
#endif