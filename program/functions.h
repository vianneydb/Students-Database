#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define END (struct Student *)0 // Null pointer for linked list termination
#define MAX_NAME_LEN 25         // Maximum length for student names

// Define the structure
typedef struct Student {
    char first_name[25];
    char last_name[25];
    long int ID;
    float final_Grade;
    struct Student *next;
} Student;

// Declare all function prototypes
void searchByID(Student *list_pointer, Student *start_pointer);
void printIDs(Student *list_pointer);
int countStudents(Student *list_pointer);
float classAverage(Student *list_pointer);
void printClassAvgCountStudents(Student *start_pointer);
void fullData(Student *list_pointer, Student *start_pointer);
void addStudent(Student **start_pointer);
void removeStudent(Student **start_pointer);
float getFinalGrade();

// Function to search for a student by their ID and print the data
void searchByID(struct Student *list_pointer, struct Student *start_pointer) {
    long int id_Num;
    bool idFound = false;
    int user_Choice;

    // Asking for ID
    printf("\nPlease enter the ID to look up (8 digits): ");
    scanf(" %li", &id_Num);

    printf("-------------------------------------------------------\n");

    // Traverse the linked list to find the student with the specified ID
    while (list_pointer != END) {
        // Print student details if the ID matches
        if (list_pointer->ID == id_Num) {
            printf(" First name: %s\n", list_pointer->first_name);
            printf("  Last name: %s\n", list_pointer->last_name);
            printf("         ID: %li\n", list_pointer->ID);
            printf("Final grade: %.2f\n", list_pointer->final_Grade);

            idFound = true;
            break; // Exit loop once the ID is found
        }

        list_pointer = list_pointer->next;
    }

    // If ID number wasn't found, display message
    if (!idFound) {
        printf("No ID number found.\n");
    }

    printf("\nDo you want to print the number of students and class average?\n(1) Yes\t(2) No\n");
    if (scanf(" %i", &user_Choice) == 1 && user_Choice == 1) {
        printClassAvgCountStudents(start_pointer); // Reset pointer to the start
    }
}

// Function to print all student IDs
void printIDs(struct Student *list_pointer) {
    int i = 1;

    printf("\n");

    // Traverse the linked list and print each student's ID
    while (list_pointer != END) {
        printf("Student %i: %li\n", i, list_pointer->ID);

        list_pointer = list_pointer->next;
        i++; // Incrementing student counter
    }
}

// Function to count the number of students in the linked list
int countStudents(struct Student *list_pointer) {
    int num_Students = 0;

    while (list_pointer != END) {
        num_Students++; // Incrementing counter
        list_pointer = list_pointer->next;
    }

    return num_Students;
}

// Function to calculate class average grade
float classAverage(struct Student *list_pointer) {
    float sum = 0.0, avg;
    int num_Students = countStudents(list_pointer); // Get the total number of students

    while (list_pointer != END) {
        sum += list_pointer->final_Grade; // Sum all grades
        list_pointer = list_pointer->next;
    }

    avg = sum / ((float)num_Students); // Calculate average

    return avg;
}

// Function to print number of students and class average
void printClassAvgCountStudents(struct Student *start_pointer) {
    printf("\nThe total number of students is: %i\n", countStudents(start_pointer));
    printf("Class Average: %.2f\n", classAverage(start_pointer));
}

// Function to print full database of students
void fullData(struct Student *list_pointer, struct Student *start_pointer) {
    printf("\n     Name    Last name     ID    Final grade\n");
    printf("-------------------------------------------------------\n");

    // Traverse the list and print each student's details
    while (list_pointer != END) {
        printf("%10s %10s %10li %8.2f\n", list_pointer->first_name, list_pointer->last_name,
               list_pointer->ID, list_pointer->final_Grade);

        list_pointer = list_pointer->next;
    }

    printClassAvgCountStudents(start_pointer); // Reset pointer to start
}

// Function to add a student for database
void addStudent(struct Student **start_pointer) {
    struct Student *new_student = (struct Student *)malloc(sizeof(struct Student));
    struct Student *temp = *start_pointer;
    int chose;

    if (new_student == NULL) {
        printf("Memory allocation failed. Cannot add student.\n");
        return;
    }

    // Prompt user for student details
    printf("\nEnter the first name: ");
    scanf(" %24s", new_student->first_name);
    printf("Enter the last name: ");
    scanf(" %24s", new_student->last_name);
    printf("Enter the ID (8 digits): ");
    scanf(" %li", &new_student->ID);

    printf("Do you know the final grade?\n(1) Yes\t(2) No\n");
    scanf(" %d", &chose);
        if (chose == 1){
            printf("Enter the final grade:");
        scanf(" %f", &new_student->final_Grade);
        }else{
            new_student->final_Grade = getFinalGrade();
        }
        
    new_student->next = END;

    // Traverse to the end of the list and add the new student
    if (*start_pointer == END) {
        *start_pointer = new_student; // List was empty
    } else {
        while (temp->next != END) {
            temp = temp->next;
        }
        temp->next = new_student;
    }

    printf("Student added successfully.\n");
}

// Function to remove a student for database
void removeStudent(struct Student **start_pointer) {
    long int id_to_remove;
    struct Student *temp = *start_pointer;
    struct Student *prev = NULL;

    printf("\nEnter the ID of the student to remove: ");
    scanf(" %li", &id_to_remove);

    while (temp != END) {
        if (temp->ID == id_to_remove) {
            if (prev == NULL) {
                // Removing the first student
                *start_pointer = temp->next;
            } else {
                // Bypass the student to remove
                prev->next = temp->next;
            }

            free(temp); // Free the memory of the removed student
            printf("Student with ID %li removed successfully.\n", id_to_remove);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Student with ID %li not found.\n", id_to_remove);
}

float getFinalGrade() {
    int x, n, i;

    // Get the number of assignments
    do {
        printf("Please enter the number of assignments: \n");
        scanf("%d", &n);
        if (n < 1) {
            printf("ERROR: Enter a valid number of assignments.\n");  
        }
    } while (n < 1);

    // Get the number of quizzes
    do {
        printf("\nPlease enter the number of quizzes: \n");
        scanf("%d", &x);
        if (x < 1) {
            printf("\tERROR: Enter a valid number of quizzes.\n");  
        }
    } while (x < 1);

    // Setting percentage of each category to work with.
    const float each_assignment_percent = 0.25 / n;
    const float each_quizzes_percent = 0.25 / x;
    const float each_exam_percent = 0.15;
    const float instructor_assessment = 0.05;

    // Defining arrays of each category
    float assignments[n], quizzes[x], exam[3];

    // Variables to store final grades of each category
    float final_grade = 0.0, sum_exam_percent = 0.0, sum_assignments_percent = 0.0, sum_quizzes_percent = 0.0;

    // Input grades for assignments
    printf("\nPlease enter %d grades (0 to 100) for assignments: \n", n);
    for (i = 0; i < n; i++) {
        do {
            scanf("%f", &assignments[i]);
            if (assignments[i] < 0 || assignments[i] > 100) {
                printf("\tERROR: Enter a valid grade (0 to 100).\n");
            }
        } while (assignments[i] < 0 || assignments[i] > 100);

        sum_assignments_percent += (assignments[i] * each_assignment_percent) / 100;
    }

    // Input grades for quizzes
    printf("\nPlease enter %d grades (0 to 100) for quizzes: \n", x);
    for (i = 0; i < x; i++) {
        do {
            scanf("%f", &quizzes[i]);
            if (quizzes[i] < 0 || quizzes[i] > 100) {
                printf("\tERROR: Enter a valid grade (0 to 100).\n");
            }
        } while (quizzes[i] < 0 || quizzes[i] > 100);

        sum_quizzes_percent += (quizzes[i] * each_quizzes_percent) / 100;
    }

    // Input grades for exams
    printf("\nPlease enter 3 grades (0 to 100) for exams: \n");
    for (i = 0; i < 3; i++) {
        do {
            scanf("%f", &exam[i]);
            if (exam[i] < 0 || exam[i] > 100) {
                printf("\tERROR: Enter a valid grade (0 to 100).\n");
            }
        } while (exam[i] < 0 || exam[i] > 100);

        sum_exam_percent += (exam[i] * each_exam_percent) / 100;
    }

    final_grade = (sum_exam_percent + sum_assignments_percent + sum_quizzes_percent + instructor_assessment)*10;

    printf("\nFinal grade on a 1 to 10 scale = %.2f\n", final_grade);
    return final_grade;
}

#endif
