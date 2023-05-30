#ifndef CH_TYPE_H
#define CH_TYPE_H

enum CHAR_TYPE
{
    C_EOF,
    C_WHITE,
    C_NEWLINE,
    C_ALPHA,
    C_DIGIT,
    C_OPERATOR,
    C_SLASH,
    C_L_PAREN,
    C_R_PAREN,
    C_L_CURLY,
    C_R_CURLY,
    C_SINGLE,
    C_DOUBLE,
    C_HEX_DIGIT,
    C_ALPHA_NUMERIC,
};

extern int is_char_type(int ch, enum CHAR_TYPE kind);
extern enum CHAR_TYPE get_char_type(int ch);

#endif /* CH_TYPE_H */