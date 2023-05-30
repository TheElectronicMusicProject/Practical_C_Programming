#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct linked_list
{
    struct linked_list * next_ptr;
    char * data;
};

struct linked_list * first_ptr;

void
add_list (char * item)
{
    struct linked_list * new_item_ptr = (struct linked_list *) malloc(sizeof(struct linked_list));
    (*new_item_ptr).data = item;
    (*new_item_ptr).next_ptr = first_ptr;
    first_ptr = new_item_ptr;

    return;
}

int
find (char * name)
{
    struct linked_list * current_ptr = first_ptr;

    while (current_ptr != NULL)
    {
        if (0 == strcmp((*current_ptr).data, name))
        {
            return 1;
        }

        current_ptr = (*current_ptr).next_ptr;
    }

    return 0;
}

int
main (void)
{
    first_ptr = NULL;

    char * p_string1 = (char *) malloc(strlen("Hello World"));
    char * p_string2 = (char *) malloc(strlen("Filippo"));
    char * p_string3 = (char *) malloc(strlen("Filippo 4"));
    strcpy(p_string1, "Hello World");
    strcpy(p_string2, "Filippo");
    strcpy(p_string3, "Filippo 4");
    add_list(p_string1);
    add_list(p_string2);
    add_list(p_string3);
    if (1 == find("Hello World"))
    {
        printf("Stringa trovata!\n");
    }
    else
    {
        printf("Non trovato\n");
    }
}