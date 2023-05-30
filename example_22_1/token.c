#include "token.h"
#include "in_file.h"
#include "ch_type.h"
#include <stdio.h>
#include <stdlib.h>

static int in_comment = FALSE;

static enum TOKEN_TYPE
read_comment (void)
{
    if ('\n' == in_cur_char())
    {
        in_read_char();
        return (T_NEWLINE);
    }

    while (1)
    {
        in_comment = TRUE;
        if (EOF == in_cur_char())
        {
            fprintf(stderr, "Error: EOF inside comment\n");
            return (T_EOF);
        }

        if ('\n' == in_cur_char())
        {
            return (T_COMMENT);
        }

        if ((in_cur_char() == '*') && (in_next_char() == '/'))
        {
            in_comment = FALSE;
            in_read_char();
            in_read_char();

            return (T_COMMENT);
        }

        in_read_char();
    }
}

enum TOKEN_TYPE
next_token (void)
{
    if (in_comment)
    {
        return (read_comment());
    }

    while (is_char_type(in_cur_char(), C_WHITE))
    {
        in_read_char();
    }

    if (in_cur_char() == EOF)
    {
        return (T_EOF);
    }

    switch (get_char_type(in_cur_char()))
    {
        case C_NEWLINE:
            in_read_char();
            return (T_NEWLINE);

        case C_ALPHA:
            while (is_char_type(in_cur_char(), C_ALPHA_NUMERIC))
            {
                in_read_char();
            }
            return (T_ID);

        case C_DIGIT:
            in_read_char();
            if ((in_cur_char() == 'X') || (in_cur_char() == 'x'))
            {
                in_read_char();
                while (is_char_type(in_cur_char(), C_HEX_DIGIT))
                {
                    in_read_char();
                }
                return (T_NUMBER);
            }
            while (is_char_type(in_cur_char(), C_DIGIT))
            {
                in_read_char();
            }
            return (T_NUMBER);

        case C_SLASH:
            /* Check for '/', '*' characters */
            if (in_next_char() == '*')
            {
                return (read_comment());
            }
        /* Fall through */
        case C_OPERATOR:
            in_read_char();
            return (T_OPERATOR);

        case C_L_PAREN:
            in_read_char();
            return (T_L_PAREN);

        case C_R_PAREN:
            in_read_char();
            return (T_R_PAREN);

        case C_L_CURLY:
            in_read_char();
            return (T_L_CURLY);

        case C_R_CURLY:
            in_read_char();
            return (T_R_CURLY);

        case C_DOUBLE:
            while (1)
            {
                in_read_char();
                /* Check for end of string */
                if (in_cur_char() == '"')
                    break;
                /* Escape character, then skip the next character */
                if (in_cur_char() == '\\')
                    in_read_char();
            }
            in_read_char();
            return (T_STRING);

        case C_SINGLE:
            while (1)
            {
                in_read_char();
                /* Check for end of character */
                if (in_cur_char() == '\'')
                    break;
                /* Escape character, then skip the next character */
                if (in_cur_char() == '\\')
                     in_read_char();
            }
            in_read_char();
            return (T_STRING);

        default:
            fprintf(stderr, "Internal error: Very strange character\n");
            abort();
    }
    
    fprintf(stderr, "Internal error: We should never get here\n");
    abort();
    return (T_EOF);
}