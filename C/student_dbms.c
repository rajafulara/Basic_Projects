#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student information
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

// Global array to store student records
struct Student students[MAX_STUDENTS];
int numStudents = 0; // Current number of students in the database

// Function to add a new student record
void addStudent() {
    if (numStudents < MAX_STUDENTS) {
        struct Student newStudent;

        printf("Enter name of the student: ");
        scanf(" %[^\n]", newStudent.name); // Read name with spaces
        printf("Enter roll number: ");
        scanf("%d", &newStudent.rollNumber);
        printf("Enter marks: ");
        scanf("%f", &newStudent.marks);

        students[numStudents] = newStudent;
        numStudents++;

        printf("Student added successfully!\n");
    } else {
        printf("Student database is full. Cannot add more students.\n");
    }
}

// Function to display all student records
void displayStudents() {
    if (numStudents == 0) {
        printf("Student database is empty.\n");
    } else {
        printf("List of students:\n");
        printf("-------------------------------------------------\n");
        printf("Roll No.\tName\t\tMarks\n");
        printf("-------------------------------------------------\n");

        for (int i = 0; i < numStudents; i++) {
            printf("%d\t\t%s\t\t%.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
        }

        printf("-------------------------------------------------\n");
    }
}

// Function to search for a student by roll number
void searchStudent(int rollNumber) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student found:\n");
            printf("-------------------------------------------------\n");
            printf("Roll No.\tName\t\tMarks\n");
            printf("-------------------------------------------------\n");
            printf("%d\t\t%s\t\t%.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
            printf("-------------------------------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

int main() {
    int choice;
    int rollNumber;

    do {
        printf("\nStudent Database Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &rollNumber);
                searchStudent(rollNumber);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
