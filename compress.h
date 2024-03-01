#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BIN_SIZE 4
#define PARSER "."
#define TXT ".txt"
#define BIN ".bin"
#define LEN 3

void encode(const char *path);
/*this func encrypt a binary file*/

void decode(const char *path);
/* this func decrypt a binary file*/