#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }

    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Student Marks: ");
    scanf("%f", &s.marks);

    students[student_count++] = s;
    printf("Student added successfully!\n");
}

void display_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    printf("ID\tName\t\tMarks\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

void search_student() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            printf("Student Found: %s with Marks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

int main() {
    int choice;

    do {
        printf("\n--- Student Management Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: search_student(); break;
            case 4: printf("Exiting program...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}