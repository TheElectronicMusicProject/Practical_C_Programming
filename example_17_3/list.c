#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Item;
typedef struct node * link;

struct node
{
    Item val;
    link next;
};

link
new_node (Item val, link next)
{
    link x = (link) malloc(sizeof(*x));

    if (NULL == x)
    {
        return NULL;
    }
    else
    {
        x->val = val;
        x->next = next;
        return x;
    }
}

link
sort_list_ins (link h, Item val)
{
    link x, p;

    if ((NULL == h) || (h->val > val))
    {
        return new_node(val, h);
    }
    else
    {
        for (x = h->next, p = h; x != NULL && val > x->val; p = x, x = x->next)
        {
            /* Attesa */
        }

        p->next = new_node(val, x);
        return h;
    }
}

Item
sort_list_search (link h, Item val)
{
    link x;

    for (x = h; x != NULL && h->val <= val; x = x->next)
    {
        if (x->val == val)
        {
            return x->val;
        }
    }

    return -1;
}

link
sort_list_del (link h, Item val)
{
    link x, p;

    if (NULL == h)
    {
        return NULL;
    }
    else
    {
        for (x = h, p = NULL; x != NULL; p = x, x = x->next)
        {
            if (x->val == val)
            {
                if (x == h)
                {
                    h = x->next;
                }
                else
                {
                    p->next = x->next;
                }
                
                free(x);
                break;
            }
        }
    }

    return h;
}

int
main (void)
{
    link first_ptr = NULL;

    first_ptr = sort_list_ins(first_ptr, 14);
    first_ptr = sort_list_ins(first_ptr, 8);
    first_ptr = sort_list_ins(first_ptr, 36);
    first_ptr = sort_list_ins(first_ptr, 3);

    if (-1 != sort_list_search(first_ptr, 14))
    {
        printf("Valore trovato!\n");
    }
    else
    {
        printf("Non trovato\n");
    }

    first_ptr = sort_list_del(first_ptr, 14);

    if (-1 != sort_list_search(first_ptr, 14))
    {
        printf("Valore trovato!\n");
    }
    else
    {
        printf("Non trovato\n");
    }
}