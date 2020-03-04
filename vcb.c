#include "main.h"
#include <stdbool.h>
#include <ctype.h>

char *freeblocks;
void freespace(struct node node[MAX_BLOCK], float noOfBlocks)
{
    freeblocks = (char *)malloc(noOfBlocks * sizeof(int));
    for (int i = 0; i < MAX_BLOCK; ++i)
    {
        if (strcmp(node[i].data, " "))
        {
            freeblocks[node[i].blockNo] = '1';
        }
        else
        {
            freeblocks[node[i].blockNo] = '0';
        }
    }
}
void vcb(struct node node[MAX_BLOCK])
{
    int blocksize = MAX_BLOCK / noOfBlocks;
    freespace(node, noOfBlocks);
}
// int main(){
//     freespace(node);
//     printf("%s",freeblocks);
// }