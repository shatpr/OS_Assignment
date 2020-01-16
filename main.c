/*----------------------------------------------------------------------------------------------
Project: CSC1007 - Operating Systems Assignment
Program name: OS File System
Authors: Xie Yuan Shan, Kwang Qi Rong, Hui Jie, Sharon, June, Hui Ting
Group: ???
Date Created: 16 January 2020
Description: 
-----------------------------------------------------------------------------------------------*/

#include "main.h"
#include "readCSV.c"

int main(void){
    register int i=0;
    unsigned char input[20];
    unsigned int choice = 0;
    unsigned int format = 0;

    do{
        printf("Type Y to format File System or N to exit\n");
        scanf("%s", &input);
        if(strlen(input) == 1){
            if(input[0] == 89 || input[0] == 121){
                //space for format
                format = 1;
            }  
            else if(input[0] == 78 || input[0] == 110){
                exit(0);
            }
            else
            {
                printf("Invalid input, please enter between Y or N\n");   
            }                     
        }else
        {
            printf("Invalid input, please enter between Y or N\n");   
        }
            
    }while(format != 1);

    //File system choice
    do{
        printf("Enter choice for file system: \n1: Contiguous Allocation\n2: Linked Allocation\n3: Indexed Allocation\n4: Custom Allocation\n");
        scanf("%s", &input);
        choice = atoi(input);
        if(choice <= 0 || choice > 4)
            printf("Invalid choice, please enter between 1 - 4");      
    }while(choice <= 0 || choice > 4);

    //Block size
    do{
        printf("Enter required block size: ");
        scanf("%s", &input);
        blockSize = atoi(input);
        if(blockSize <= 0 || blockSize > 10)
            printf("Invalid entry, please enter between 1 - 10");      
    }while(blockSize <= 0 || blockSize > 10);
    
    //Read CSV File
    printf("Enter name of .csv file to read from\n");
    scanf("%s", &input);
    readCSV(input);
} 