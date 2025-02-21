#include "parser.h"
#include <stdio.h>
#include <string.h>

typedef enum
{
    COMPILE,
    LINK,
} comp_opts;

int main(int _argc, char **_argv)
{
    int argc = _argc;
    char **argv = _argv;
    comp_opts comp_opts;

    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    if (argc < 4)
    {
        printf("Error: Not enough arguments passed to compiler\n");
        return -1;
    }

    if (!strcmp("comp", argv[1]))
    {
        comp_opts = COMPILE;
    }
    else if (!strcmp("link", argv[1]))
    {
        comp_opts = LINK;
    }
    else
    {
        printf("Error: No valid options provided\n");
        return 0;
    }

    if (comp_opts == COMPILE)
    {
        parse_source_code(argv[3]);
    }
    else if (comp_opts == LINK)
    {
        // link
    }
}
