#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    struct node * left;
    struct node * right;
    char * word;
};

static struct node * root = NULL;

void
memory_error (void)
{
    fprintf(stderr, "Error: out of memory\n");
    exit(8);
}

char *
save_string (char * string)
{
    char * new_string;
    
    new_string = (char *) malloc(strlen(string) + 1);
    if (NULL == new_string)
    {
        memory_error();
        return NULL;
    }
    else
    {
        strcpy(new_string, string);
        return (new_string);
    }
}

void
print_tree (struct node * top)
{
    if (NULL == top)
    {
        return;
    }
    else
    {
        print_tree(top->left);
        printf("%s\n", top->word);
        print_tree(top->right);
    }
}

void
enter (struct node ** node, char * word)
{
    int result;
    
    if (NULL == (*node))
    {
        (*node) = (struct node *) malloc(sizeof(struct node));

        if (NULL == (*node))
        {
            memory_error();
        }
        else
        {
            (*node)->left = NULL;
            (*node)->right = NULL;
            (*node)->word = save_string(word);
            return;
        }
    }
    else
    {
        result = strcmp((*node)->word, word);

        if (0 == result)
        {
            return;
        }

        if (result < 0)
        {
            enter(&((*node)->right), word);
        }
        else
        {
            enter(&((*node)->left), word);
        }
    }
}

void
scan (char * name)
{
    char word[100];
    unsigned int index;
    int ch;
    FILE * in_file;

    in_file = fopen(name, "r");
    if (NULL == in_file)
    {
        fprintf(stderr, "Error: unable to open %s\n", name);
        exit(8);
    }
    else
    {
        while (1)
        {
            while (1)
            {
                ch = fgetc(in_file);

                if (0 != isalpha(ch) || (ch == EOF))
                {
                    break;
                }
            }

            if (EOF == ch)
            {
                break;
            }

            word[0] = ch;
            for (index = 1; index < sizeof(word); ++index)
            {
                ch = fgetc(in_file);
                if (!isalpha(ch))
                {
                    break;
                }
                else
                {
                    word[index] = ch;
                }
            }

            word[index] = '\0';

            fprintf(stderr, "Word found %s\n", word);

            enter(&root, word);
        }

        fclose(in_file);
    }
}

int
main (int argc, char * argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error\n");
        exit(8);
    }
    else
    {
        fprintf(stdout, "File %s\n", argv[1]);
        scan(argv[1]);
        print_tree(root);
    }

    return (0);
}