/*
Programmer: Vianney Estefania Diaz-Barraza
Date: December 14th, 2024

Create a C program to manages students records database by using linked lists of student's structures;
pointers for the link list and to access the records; and functions to search for students, calculate class
average and print the desired information.
*/

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define END (struct Student *)0 // Null pointer for linked list termination
#define MAX_NAME_LEN 25         // Maximum length for student names

// Global function prototype declarations
void showMenu(void);
void searchByID(struct Student *list_pointer, struct Student *start_pointer);
void printIDs(struct Student *list_pointer);
int countStudents(struct Student *list_pointer);
float classAverage(struct Student *list_pointer);
void printClassAvgCountStudents(struct Student *start_pointer);
void fullData(struct Student *list_pointer, struct Student *start_pointer);
void addStudent(struct Student **start_pointer);
void removeStudent(struct Student **start_pointer);

int main(void) {
    int repeat, user_Choice;

    // Creating students records (database)
    struct Student s1 = {"Vianney", "Diaz", 80892347, 9.6};
    struct Student s2 = {"Jesus", "Melendez", 80773456, 8.5};
    struct Student s3 = {"Jose", "Torres", 80747889, 7.2};
    struct Student s4 = {"Sophia", "Aguirre", 80729754, 10.0};
    struct Student s5 = {"Edgar", "Barraza", 80776489, 4.3};
    struct Student *list_pointer = &s1;

    // Linking the records
    s1.next = &s2;
    s2.next = &s3;
    s3.next = &s4;
    s4.next = &s5;
    s5.next = END; // End of the linked list

    do {
        showMenu();
        scanf(" %i", &user_Choice);

        // Perform the operation based on user's choice
        switch (user_Choice) {
        case 1:
            searchByID(list_pointer, &s1);
            break;

        case 2:
            printIDs(list_pointer);
            break;

        case 3:
            fullData(list_pointer, &s1);
            break;
        
        case 4:
            addStudent(&list_pointer);
            break;

        case 5:
            removeStudent(&list_pointer);
            break;

        case 6:
            printf("\nThank you! :)");
            return 0;

        default: // Handle invalid input
            printf("ERROR: Please enter a valid option.\n");
            break;
        }

        printf("-------------------------------------------------------\n");
        printf("Do you want to perform another operation?\n(1) Yes\t(2) No\n");
        scanf(" %i", &repeat);

        // Handle invalid input for repeat
        if ((repeat != 1) && (repeat != 2)) {
            repeat = 2;
            printf("ERROR: Unknown input, exiting the program...\n");
        }

    } while (repeat == 1); // Repeat until the user chooses to exit

    printf("Thank you! :)\n");

    return 0;
}

// Function to display the menu of options
void showMenu(void) {
    printf("\n-------------------------------------------------------\n");
    printf("Select the number of the operation to perform: \n\n");
    printf("(1) Search a student record by ID.\n");
    printf("(2) Print all student's ID.\n");
    printf("(3) Print full database.\n");
    printf("(4) Add a new student to the database.\n");
    printf("(5) Remove a student of the database.\n");
    printf("(6) Exit.\n");
    printf("-------------------------------------------------------\n");
}
