#include "student.h"
#include <stdlib.h>
#include <stdio.h>
void printMenu()
{
    printf("Choose 0 to add student\n");
    printf("choose 1 to find student\n");
    printf("Choose 2 to update students\n");
    printf("Choose 3 to delete students\n");
    printf("Choose 4 to print students\n");
    printf("Choose 5 to print individual student\n");
    printf("Choose 6 to load the list\n");
    printf("Choose 7 to save the list\n");
    printf("Choose 8 to to exit the program\n");
}

void print(student st)
{
    printf("%d: %s\n", st.id, st.name);
}

void printstudents(list l)
{
    for (node n = l->head; n != NULL; n = n->next)
    {
        print(n->data);
    }
}

list load(char *filename)
{
    FILE *fd;
    fd = fopen(filename, "r");
    if (fd == NULL)
    {
        perror("fopen");
        return NULL;
    }

    list students = list_create();

    student st;
    while (!feof(fd))
    {
        fscanf(fd, "%d, %s\n", &st.id, st.name);
        list_insert_last(students , st);
    }

    if (fclose(fd) == EOF)
    {
        list_destroy(students);
        perror("fclose");
        return NULL;
    }

    return students;
}

void save(char *filename, list l)
{
    FILE *fd;
    fd = fopen(filename, "a");
    if (fd == NULL)
    {
        perror("fopen");
        return;
    }

    for (node n = l->head; n != NULL; n = n->next)
    {
        if (fprintf(fd, "%d, %s\n", n->data.id, n->data.name) < 0)
        {
            perror("fprintf");
            return;
        }
    }

    if (fclose(fd) == EOF)
    {
        perror("fclose");
        return;
    }
}

int addStudent(student st, list l)
{

    return list_insert_last(l, st);
}

student *findStudent(int id, list l)
{

    return list_find(l, id);
}

int deleteStudent(student st, list l)
{
    return list_remove(l, st.id);
}

int updateStudent(student st, list l)
{
    return list_edit(l, st.id, st.name);
    ;
}