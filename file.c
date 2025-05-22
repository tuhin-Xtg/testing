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