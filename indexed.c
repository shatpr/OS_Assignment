#include "indexed.h"

unsigned char input[20];
int file_name;
enum allstate
{
    add = 1,
    read = 2,
    delete = 3
} state;
int valid;
int fNameArr[MAX_BLOCK];

int indexed(void)
{
    for (int i=0; i<MAX_BLOCK; i++){
        fNameArr[i] = 0;
    }
    

    printf("Enter name of .csv file to read from\n");
    //scanf("%s", &input);
    readCSV("SampleCSV.csv");

    printf("Num of files reserved: %i\n", counterfile);

    //    updateIndexBlock();

    printallocation();
}
void readCSV(char input[])
{
    register int count = 0;
    FILE *fp = fopen(input, "r");

    char buffer[1024];
    while (fgets(buffer, 1024, (FILE *)fp))
    {
        count++;
        if (count != 0)
        {
            getData(buffer);
        }
    }

    fclose(fp);
}

void getData(char buffer[])
{
    char *token = strtok(buffer, ",");
    int counter = 0;
    while (token)
    {
        //printf("%s\n",token);
        //strcpy(CSV_Data[counter], token);
        // printf(CSV_Data[counter]);
        allocation(token);
        token = strtok(NULL, ", ");

        counter++;
    }
}

void allocation(char *data)
{
    char choice;
    //printf("%s\n",data);

    if (!strcmp(data, "add"))
    {
        choice = add;
    }
    else if (!strcmp(data, "read"))
    {
        choice = read;
    }
    else if (!strcmp(data, "delete"))
    {
        choice = delete;
    }
    switch (choice)
    {
    case add:
        //printf("+");
        if (atoi(data) != 0 && atoi(data) % 100 == 0) //If data is 100,200 or 300, data contains the file name now. Goes in here.
        {
            file_name = atoi(data);
            //    strcpy(file_name, atoi(data));
            counterfile = counterfile + 1;
            reserveBlock(file_name); //Reserve block for the file file_name.
            blockNum = findNewBlock(); //Block num variable for file block (not reserved)
            printf("Finding block num for first file: %i\n", blockNum);
            counterI=0;
        }
        else
        {
            if (atoi(data) != 0) //If data is not file name, which is data of file, go in here. 
            {
                int startIndex = findSNodeFromNum(blockNum);
                printf("Found startindex for first file block: %i \n", startIndex);
                allocate(file_name, data, startIndex, counterI);        

                counterI++;
                // printf("Inside else");
                
                // fNameArr[counterI] = file_name;
                // printf("%d", fNameArr[counterI]);
                
                // if (fNameArr[counterI] == fNameArr[0]){
                //     printf("Same");
                //     allocate(file_name, data);
                // }
                // else{
                //     printf("Different");
                // }
                
                // for (int i=0; i<)
                
                // printf("filename is %i in else statement", file_name);
                // allocate(file_name, data);
                // counterI++;   
             }
        }
        break;
    case read:
        //printf("=");
        break;
    case delete:
        //printf("-");
        break;
    }
}

void allocate(int fileBlock, char data[], int startIndex, int counter)
{    
    strcpy(node[startIndex+counter].data, data);
    node[startIndex+counter].filename = fileBlock;          
//                 strcpy(node[i].data, data);
//                 node[i].filename = fileBlock;
}

int findSNodeFromNum(int blockNum){
    for (int i=0; i<MAX_BLOCK; i++){
        if (node[i].blockNo == blockNum){
            printf("starting index: %i \n", node[i].index);
            return node[i].index;
        }
    }
}

// void savetofile(int f, int d, int block_num){
//     for (int i = 0; i<MAX_BLOCK; i++){
//         if (node[i].blockNo = block_num){
//             node[i].filename = f;
//             node[i].data = d;
//         }
// }

// }

// int findNewBlock(int f, int d){
//     int block_num = randomBlock();
//     for (int i = 0; i<MAX_BLOCK; i++){
//         if (node[i].blockNo = block_num){
//             if (checkspace(i)){
//             valid = 1;
//             }
//             else{
//             valid = 0;
//             }
//         }
//     }
//     if (valid==1){
//         savetofile(f, d, block_num);
//     }
//     else if (valid ==0){
//         findNewBlock(f,d);
//     }
// }

void reserveBlock(int fileBlock)
{
    block_num = randomBlock();
    for (int i = 0; i < MAX_BLOCK; i++)
    {
        if (node[i].blockNo == block_num)
        {
            if (checkspace(i))
            {
                node[i].fileBlock = fileBlock;
            }
            else
            {
                reserveBlock(fileBlock);
            }
        }
    }
}

// void savetofile(int f, int d)
// {
//     for (int i = 0; i < MAX_BLOCK; i++)
//     {
//         if (checkspace(i))
//         {
//             node[i].filename = f;
//             return;
//         }
//     }
// }
// void updateIndexBlock(int fileBlock){

// }


// void allocate(int fileBlock, char data[])
// {
//     printf("block num after finding new block in allocate? %d\n", block_num);
//     for (int i = 0; i < MAX_BLOCK; i++)
//     {
//         if (node[i].blockNo == block_num)
//         {
            
//                 strcpy(node[i].data, data);
//                 node[i].filename = fileBlock;
//                 return;
            
//         }
//     }
// }


int checkspace(int n)
{
    if (strcmp(node[n].data, "/0") && node[n].filename == 0 && node[n].fileBlock == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int randomBlock()
{
    int _randomBlock = rand() % noOfBlocks;
    return _randomBlock;
}

int findNewBlock()
{
    
    block_num = randomBlock();
    for (int i = 0; i < MAX_BLOCK; i++)
    {
        if (node[i].blockNo == block_num)
        {
            if (checkspace(i))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
            }
        }
    }
    if (valid == 1)
    {
        return block_num;
    }
    else if (valid == 0)
    {
        findNewBlock();
    }
}

void printallocation()
{
    printf("Block:\t Index:\t File Name: \t File Data: \t Reserved For:\n");
    for (int i = 0; i < MAX_BLOCK; i++)
    {

        // if(node[i].filename != 0 || node[i].fileBlock != 0){
        //     printf("Filename: %i", node[i].filename);
        //     printf("Data: %i", node[i].data);
        //     printf("Block reserved for: %i", node[i].fileBlock);
        // }
        printf("%d\t%d\t%d\t\t%d\t%s\n", node[i].blockNo, node[i].index, node[i].filename, node[i].fileBlock, node[i].data);
    }

}
void freespace(struct node node[MAX_BLOCK],int noOfBlocks)
{

    freeblocks = (char *)malloc(noOfBlocks * sizeof(char));
    for (int i = 0; i < MAX_BLOCK; ++i)
    {

        if (strcmp(node[i].data, "0") == 0)
        {
            freeblocks[node[i].blockNo] = '1';
            //printf("%c",freeblocks[node[i].blockNo] );
        }
        else
        {
            freeblocks[node[i].blockNo] = '0';
            // printf("%c",freeblocks[node[i].blockNo] );
        }
    }
}
