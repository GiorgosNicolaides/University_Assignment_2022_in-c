#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <string.h>

static int id_base = 0;
static int saved = 0;

int main(int argc, char const *argv[])
{
    // Make list
    list students = list_create();
    // Print Menu
    printMenu();

    // Int for options selection
    int decision = 0;

    // Loop for decision
    do
    {
        printf("Choose an option:\n");
        scanf("%d", &decision);

        switch (decision)
        {
        case 0: // add student
            // Make a student
            student st;
            // Get the students name
            printf("Give me the student's name:\n");
            scanf("%s", st.name);
            // set the unique id
            st.id = id_base++;
            // add student to the list
            addStudent(st, students);

            break;

        case 1: // find student
            // Get from user the id of the student that he wants
            int id_search;
            printf("What is the id of the student that you want to search:\n");
            scanf("%d", &id_search);
            // Find the student
            findStudent(id_search, students);
            break;

        case 2: // update student
            // Get the id of the student you want to edit
            student st_update;
            printf("What is the id of the student that you want to update:\n");
            scanf("%d", &st_update.id);
            findStudent(st_update.id, students);
            // Get the new students name
            printf("What is the name of the student\n");
            scanf("%s", st.name);
            // id stays the same
            updateStudent(st, students);

            break;

        case 3: // delete student
            // Get the id of the student you want to delete
            student st_del;
            printf("What is the id of the student that you want to delete:\n");
            scanf("%d", &st_del.id);
            findStudent(st_del.id, students);
            deleteStudent(st_del, students);

            break;

        case 4: // print students
            printstudents(students);

            break;

        case 5:
            // Get the id of the student you want to print
            int id_print;
            printf("What is the id of the student that you want to update:\n");
            scanf("%d", &id_print);
            findStudent(id_print, students);
            print(st);
            break;

        case 6: // load the list
            printf("LOADING\n");
            load("./test.txt");
            break;

        case 7: // save the list

            char filename[BUFSIZ];
            memset(filename, 0x00, BUFSIZ);
            printf("Provide a path to save the list: ");
            scanf("%s\n", filename);
            save(filename, students);

            break;

        case 8:
            if (!saved)
            {
                char filename[BUFSIZ];
                memset(filename, 0x00, BUFSIZ);
                printf("Provide a path to save the list: ");
                scanf("%s\n", filename);

                save(filename, students);
                saved = 1;
            }
            list_destroy(students);

            break;
        }

    } while (decision < 9);
}