#ifndef STUDENT_H
#define STUDENT_H

#define MAXSTRING 256

typedef struct
{
    char name[MAXSTRING];
    int id;
} student;

typedef struct nodeR *node;
typedef struct listR *list;

struct nodeR
{
    student data;
    node next;
    node previous;
};

struct listR
{
    node head;
    node tail;
};


void printMenu();

void print(student st);

void printstudents(list l);

list load(char *filename); //ανάκτηση λίστας φοιτητών από αρχείο

void save(char *filename, list l); //αποθήκευση λίστας φοιτητών σε αρχείο

int addStudent(student st, list l); //προσθήκη νέου student

student *findStudent(int id, list l); //αναζήτηση του student από τη λίστα με βάση το id

int deleteStudent(student st, list l); //διαγραφή με βάση το st.id

int updateStudent(student st, list l); //ανανέωση με βάση το st.id

list list_create(void);

void list_destroy(list l);

int list_insert_last(list l, student data);

int list_edit(list l, int id, char *name);

int list_remove(list l, int id);

student *list_find(list l, int id);

#endif