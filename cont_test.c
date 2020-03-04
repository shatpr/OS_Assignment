#include "cont.h"

// bool checkDigit(char str[NO_OF_STRINGS1]);
// char *choice;
// char data[MAX_BLOCK][MAX_STRING_SIZE1];
// void deleteblock(int filename);
// void addblock(int data, char *choice, int pos, char* input);
// int blocks[MAX_BLOCK];
// bool sortoutnode(struct node node[MAX_BLOCK]);
// int blockSize = 5;
// char CSV_Data1[10][10] = {"add", "100", "101", "102", "103", "104", "105", "106"};
// bool cont(char CSV_Data1[NO_OF_STRINGS1][MAX_STRING_SIZE1])
// {
//     sortoutnode(node);
//     int filename = 0;
//     int csvid = blockSize - 1;
//     for (int i = 0; i < NO_OF_STRINGS1; ++i)
//     {
//         if (checkDigit(CSV_Data1[i]))
//         {
//             char *data1=strdup(CSV_Data1[i])
//             //data[i]=strdup(data1);
//             if (strcmp(choice, "add") == 0)
//             { 
//                 addblock(filename, choice, csvid, data); //its not good to leave it here because 
//                 //you should put print add in here but it won't work because it will keep calling print add
//                 //because you need to print both add and delete statements when you run the program
//                 //FIX IT (only print block no once, and indexes)
//                 csvid++;
//             }
//             else if (strcmp(choice, "delete") == 0)
//             {
//                 deleteblock(filename);
//             }
//         }
//         else
//         {
//             choice = strdup(CSV_Data1[i]);
//             if (*choice)
//             {
//                 filename = atoi(CSV_Data1[i + 1]);
//             }
//             assert(strcmp(CSV_Data1[i], choice) == 0);
//         }
//     }
//     free(choice);
//     for (int i = 0; i < MAX_BLOCK; ++i)
//     {
//         blocks[i] = 0;
//     }
//     for (int i = 0; i < 130; ++i)
//     {
//         printf("%d: %d\t", node[i].blockNo, node[i].data);
//     }
//     // for (int i = 0; i < sizeof(data); ++i)
//     // {
//     //     printf("%d\t", blocks[i]);
//     // }
//     return true;
// }

// bool checkDigit(char str[4])
// {
//     for (int i = 0; str[i] != '\0'; i++)
//     {
//         if (isdigit(str[i]) != 0)
//             return true;
//     }
//     return false;
// }

// bool sortoutnode(struct node node[MAX_BLOCK])
// {
//     int index = 0;
//     int blkid = 0;
//     bool success = false;
//     for (int i = 0; i < MAX_BLOCK; ++i)
//     {
//         node[i].index = index;
//         node[i].blockNo = blkid;
//         success = true;
//         index++;
//         if (index % blockSize == 0)
//         {
//             blkid++;
//         }
//     }
//     return success;
// }
// void choose(char *choice)
// {

// }
// void addblock(int filename, char *choice, int pos, char* input)
// {
//     int blockNo = 0;
//     node[pos].filename = filename;

//     if (input != node[pos].filename)
//     {
//         node[pos].data = input;
//         blockNo = node[pos].blockNo;
//         if (blocks[blockNo] != 1)
//         {
//             blocks[blockNo] = 1;
//         }
//     }
// }
// void deleteblock(int filename)
// {

//     for (int j = 0; j < MAX_BLOCK; ++j)
//     {
//         if (node[j].filename == filename)
//         {
//             node[j].data = 0;
//         }
//     }
// }
// // void printaddblock(int filename, struct node node)
// // {
// //     int blockNo;
// //     printf("Adding file %s", filename);
// //     for (int i = 0; i < MAX_BLOCK; ++i)
// //     {
// //         if (blocks[i] == node.blockNo)
// //         {
// //             blockNo = i;
// //         }
// //     }
// //     printf("@ block:%d", blockNo);
// // }

// int main()
// {
//     cont(CSV_Data1);
// }