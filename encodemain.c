#include <string.h>
#include "compress.h"

#define ARGS 3
#define FILENAME 2
#define ENCODE "-c"
#define DECODE "-d"
#define PARSER "."

int main(int argc, char **argv)
{
    char *parsed;

    if (argc != ARGS)
    {
        perror("Invalid amount of arguments\n");
        exit(1);
    }

    if (strcmp(argv[1], ENCODE) && strcmp(argv[1], DECODE))
    {
        perror("Wrong type of command\n");
        exit(1);
    }

    parsed = strtok(argv[FILENAME], PARSER);
    parsed = strtok(NULL, PARSER);

    if (strcmp(parsed, TXT) && strcmp(parsed, BIN))
    {
        perror("Invalid file type\n");
        exit(1);
    }

    if (!strcmp(parsed, TXT))
        encode(argv[FILENAME]);

    else if(!strcmp(parsed, BIN))
        decode(argv[FILENAME]);

    return 0;
}