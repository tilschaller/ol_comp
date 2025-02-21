#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

enum error_type
{
    missing_semicolon,
};

struct syntax_error
{
    enum error_type error;
    int line;
    char file_name[];
};

/*    FILE READER     */
char *read_file(const char *filename);

/*    INPUT READER    */
char peek_reader(int ahead);
char consume_reader(int ahead);
int isEOF(char c);

/*    MAIN PARSER FUNCTION      */
void parse_source_code(char *source)
{
    unsigned int cur_pos = 0;
    char *source_string = read_file(source);

    while (!isEOF(cur_pos))
    {
    }

    free(source_string);
}

char *read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Specified source file could not be found");
        exit(1);
    }

    // find file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(file_size + 1);
    if (!buffer)
    {
        perror("Failed to allocate memory for source file");
        fclose(file);
        exit(1);
    }

    // fill the buffer with file content
    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';

    fclose(file);

    return buffer;
}

int isEOF(char c)
{
    if (c == '\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
