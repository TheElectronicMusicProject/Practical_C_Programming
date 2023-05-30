#include "ia.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

static struct infinite_array *
ia_locate (struct infinite_array * array_ptr, int index, int * current_index_ptr)
{
    struct infinite_array * current_ptr = NULL;
    
    current_ptr = array_ptr;
    *current_index_ptr = index;

    while (*current_index_ptr >= BLOCK_SIZE)
    {
        if (NULL == current_ptr->next)
        {
            current_ptr->next = (struct infinite_array *) malloc(sizeof(struct infinite_array));

            if (NULL == current_ptr->next)
            {
                fprintf(stderr, "Error: out of memory\n");
                exit(8);
            }

            memset(current_ptr->next, '\0', sizeof(struct infinite_array));
        }

        current_ptr = current_ptr->next;
        *current_index_ptr -= BLOCK_SIZE;
    }

    return (current_ptr);
}   /* ia_locate() */

void
ia_store (struct infinite_array * array_ptr, int index, int store_data)
{
    struct infinite_array * current_ptr;
    int current_index;

    current_ptr = ia_locate(array_ptr, index, &current_index);
    current_ptr->data[current_index] = store_data;
}   /* ia_store() */

int
ia_get (struct infinite_array * array_ptr, int index)
{
    struct infinite_array * current_ptr;
    int current_index;

    current_ptr = ia_locate(array_ptr, index, &current_index);

    return (current_ptr->data[current_index]);
}   /* ia_get() */