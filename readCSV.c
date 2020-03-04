#include "readCSV.h"
int counter = 0;
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
    while (token)
    {
        //printf("%s\n",token);
        strcpy(CSV_Data[counter], token);
        //printf(CSV_Data[counter]);
        printf("%d\t",counter);
        token = strtok(NULL, ", ");
        counter++;
    }
}
// int main()
// {
//     char *input="";
//     readCSV("SampleCSV.csv");
//     for (int i = 0; i < NO_OF_STRING; ++i)
//     {
//         printf("%s", CSV_Data[i]);
//     }
// }