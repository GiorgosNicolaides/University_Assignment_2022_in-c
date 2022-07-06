#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "student.h"

list list_create(void)
{
    list l = malloc(sizeof(*l));
    if (l == NULL)
    {
        return NULL;
    }
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void list_destroy(list l)
{

    node current = l->head;
    while (current != NULL)
    {
        node next = current->next;

        free(current);
        current = next;
    }
    free(l);
}

int list_insert_last(list l, student data)
{
    node new = malloc(sizeof(*new));
    if (new == NULL)
    {
        printf("ERROR");
        return -1;
    }
    new->data = data;
    new->next = NULL;
    new->previous = NULL;

    node current = l->tail;
    if (current == NULL)
    {
        current = new;
        l->head = current;
    }
    else
    {
        current->next = new;
        new->previous = current;
    }

    l->tail = new;
    return new->data.id;
};

int list_edit(list l, int id, char *name)
{
    for (node n = l->head; n != NULL; n = n->next)
    {
        if (n->data.id == id)
        {
            if (strlen(name) > MAXSTRING)
            {
                // Error
                printf("Error: name length > MAXSTRING\n");
                return -1;
            }

            strcpy(n->data.name, name);
        }
    }
    return id;
}

int list_remove(list l, int id)
{
    for (node n = l->head; n != NULL; n = n->next)
    {
        if (n->data.id == id)
        {
            node next = n->next;
            node previous = n->previous;

            previous->next = next;
            next->previous = previous;

            if (n == l->head)
            {
                l->head = next;
            }

            if (n == l->tail)
            {
                l->tail = previous;
            }
            free(n);

            return 0;
        }
    }
    return -1; // Not found
}

student *list_find(list l, int id)
{
    for (node n = l->head; n != NULL; n = n->next)
    {
        if (n->data.id == id)
        {
            return &n->data;
        }
    }
    return NULL; // Not found
}