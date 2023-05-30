#include "in_file.h"
#include <stdio.h>
#include <errno.h>

#define LINE_MAX    500

struct input_file
{
    FILE * file;
    char line[LINE_MAX];
    char * char_ptr;
    int cur_char;
    int next_char;
};

static struct input_file in_file = {
    NULL,
    "",
    NULL,
    '\0',
    '\0',
};

int
in_open (const char name[])
{
    in_file.file = fopen(name, "r");

    if (in_file.file == NULL)
    {
        return (errno);
    }

    in_file.cur_char = fgetc(in_file.file);
    in_file.next_char = fgetc(in_file.file);
    in_file.char_ptr = in_file.line;

    return (0);
}

void
in_close (void)
{
    if (in_file.file != NULL)
    {
        fclose(in_file.file);
        in_file.file = NULL;
    }
}

int
in_cur_char (void)
{
    return (in_file.cur_char);
}

int
in_next_char (void)
{
    return (in_file.next_char);
}

void
in_flush (void)
{
    *in_file.char_ptr = '\0';
    fputs(in_file.line, stdout);
    in_file.char_ptr = in_file.line;
}

void
in_read_char (void)
{
    *in_file.char_ptr = in_file.cur_char;
    ++in_file.char_ptr;
    in_file.cur_char = in_file.next_char;
    in_file.next_char = fgetc(in_file.file);
}