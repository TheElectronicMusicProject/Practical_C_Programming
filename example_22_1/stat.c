#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ch_type.h"
#include "in_file.h"
#include "token.h"

static int cur_line;

static void
lc_init (void)
{
    cur_line = 0;
}

static void
lc_take_token (enum TOKEN_TYPE token)
{
    if (token == T_NEWLINE)
        ++cur_line;
}

static void
lc_line_start (void)
{
    printf("%4d ", cur_line);
}

static void
lc_eof (void)
{
    printf("Total number of lines: %d\n", cur_line);
}

static int pc_cur_level;
static int pc_max_level;

void
pc_init (void)
{
    pc_cur_level = 0;
    pc_max_level = 0;
}

void
pc_take_token (enum TOKEN_TYPE token)
{
    switch (token)
    {
        case T_L_PAREN:
            ++pc_cur_level;
            if (pc_cur_level > pc_max_level)
                pc_max_level = pc_cur_level;
        break;
        case T_R_PAREN:
            --pc_cur_level;
        break;
        default:
        /* Ignore */
        break;
    }
}

static void
pc_line_start (void)
{
    printf("(%-2d ", pc_cur_level);
}

void
pc_eof (void)
{
    printf("Maximum nesting of () : %d\n", pc_max_level);
}

static int bc_cur_level; /* Current nesting level */
static int bc_max_level; /* Maximum nesting level */

void
bc_init (void)
{
    bc_cur_level = 0;
    bc_max_level = 0;
}

void
bc_take_token (enum TOKEN_TYPE token)
{
    switch (token)
    {
        case T_L_CURLY:
            ++bc_cur_level;
            if (bc_cur_level > bc_max_level)
                bc_max_level = bc_cur_level;
        break;
        case T_R_CURLY:
            --bc_cur_level;
        break;
        default:
        /* Ignore */
        break;
    }
}

static void
bc_line_start (void)
{
    printf("{%-2d ", bc_cur_level);
}

static void
bc_eof (void)
{
    printf("Maximum nesting of {} : %d\n", bc_max_level);
}

static const int CF_COMMENT = (1<<0); /* Line contains comment */
static const int CF_CODE = (1<<1); /* Line contains code */

/* 0 -- [0] Blank line */
/* CF_COMMENT -- [1] Comment-only line */
/* CF_CODE -- [2] Code-only line */
/* CF_COMMENT|CF_CODE -- [3] Comments and code on this line */

static int counters[4]; /* Count of various types of stats. */
static int flags; /* Flags for the current line */

static void
cc_init (void)
{
    memset(counters, '\0', sizeof(counters));
    flags = 0;
}

static void
cc_line_start
(void)
{
    /* Do nothing */
}

void
cc_take_token (enum TOKEN_TYPE token)
{
    switch (token)
    {
        case T_COMMENT:
            flags |= CF_COMMENT;
        break;
        default:
            flags |= CF_CODE;
        break;
        case T_NEWLINE:
            ++counters[flags];
            flags = 0;
        break;
    }
}

static void
cc_eof (void)
{
    printf("Number of blank lines .................%d\n",
           counters[0]);
    printf("Number of comment only lines ..........%d\n",
           counters[1]);
    printf("Number of code only lines .............%d\n",
           counters[2]);
    printf("Number of lines with code and comments %d\n",
           counters[3]);
    printf("Comment to code ratio %3.1f%%\n",
           (float)(counters[1] + counters[3]) /
           (float)(counters[2] + counters[3]) * 100.0);
}

static void
do_file (const char * const name)
{
    enum TOKEN_TYPE cur_token; /* Current token type */
    /*
    * Initialize the counters
    */
    lc_init();
    pc_init();
    bc_init();
    cc_init();

    if (in_open(name) != 0)
    {
        printf("Error: Could not open file %s for reading\n", name);
        return;
    }

    while (1)
    {
        cur_token = next_token();
        lc_take_token(cur_token);
        pc_take_token(cur_token);
        bc_take_token(cur_token);
        cc_take_token(cur_token);
        switch (cur_token)
        {
            case T_NEWLINE:
                lc_line_start();
                pc_line_start();
                bc_line_start();
                cc_line_start();
                in_flush();
            break;
            case T_EOF:
                lc_eof();
                pc_eof();
                bc_eof();
                cc_eof();
                in_close();
            return;
            default:
            /* Do nothing */
            break;
        }
    }
}

int
main (int argc, char *argv[])
{
    char *prog_name = argv[0]; /* Name of the program */

    if (argc == 1)
    {
        printf("Usage is %s [options] <file-list>\n", prog_name);
        exit (8);
    }

    for (/* argc set */; argc > 1; --argc)
    {
        do_file(argv[1]);
        ++argv;
    }

    return (0);
}