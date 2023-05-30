#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Item;
typedef struct node * link;

struct node
{
    Item val;
    link next;
    link prev;
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
        x->prev = NULL;
        return x;
    }
}

link
sort_list_ins (link h, Item val)
{
    link x, t;

    if ((NULL == h) || (h->val > val))
    {
        t = new_node(val, h);
        t->prev = NULL;
        return t;
    }
    else
    {
        for (x = h; x->next != NULL && val > x->val; x = x->next)
        {
            /* Attesa */
        }
        if (NULL == x->next)
        {
            t = new_node(val, NULL);
        }
        else
        {
            t = new_node(val, x->next);
            x->next->prev = t;
        }
        x->next = t;
        t->prev = x;
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
    link x, t;

    if (NULL == h)
    {
        return NULL;
    }
    else
    {
        for (t = h, x = NULL; t != NULL; x = t, t = t->next)
        {
            if (t->val == val)
            {
                if (t == h)
                {
                    h = t->next;
                }
                else
                {
                    t->next->prev = x;
                    x->next = t->next;
                }
                
                free(t);
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