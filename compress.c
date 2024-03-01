#include "compress.h"

void encode(const char *path)
{
    FILE *fptr;
    if ((fptr = fopen(path, "r")) == NULL)
    {
        perror("Error! opening file"); // Program exits if the file pointer returns NULL.
        exit(1);
    }
    int *buffer = (int *)malloc(getFileSize(fptr) * sizeof(int));
    fread(buffer, sizeof(buffer), 1, fptr);



}

void decode(const char *path)
{
    int num = 0;
    char* filename = 0;
    FILE *binFile, *txtFile;
    if ((binFile = fopen(path, "r")) == NULL)
    {
        perror("Error! opening file"); // Program exits if the file pointer returns NULL.
        exit(1);
    }

    filename = strtok(path, PARSER);
    strcat(filename, TXT);
    

    if ((txtFile = fopen(filename, "a")) == NULL)
    {
        perror("Error! opening file"); // Program exits if the file pointer returns NULL.
        exit(1);
    }
    
    char* buffer[BIN_SIZE] = (char **)malloc((getFileSize(binFile) / BIN_SIZE) * sizeof(char*));
    
    
    fread(buffer, sizeof(buffer), 1, binFile);
    
    for(int i = 0; i < (getFileSize(binFile) / BIN_SIZE); i++)
    {
        num = (int) strtol(buffer[i], NULL, 2);
        num = ~num;
        fwrite(num, sizeof(num), 1, txtFile);
    }

}

/*this func return the sixe of the file */
int getFileSize(FILE *f)
{
    int size = 0;
    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    rewind(f);
    return size;
}