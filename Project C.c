#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rollNumber;
    char name[21];
    int age;
    char course[21];
} Student;

Student *students = NULL; // Dynamic array of students
int numberOfStudentsAdded = 0; // Current number of students
int maxStudents = 10; // Initial capacity for dynamic array

void addStudent();
void editStudent();
void deleteStudent();
void searchStudent();
void displayListOfStudents();
void saveToFile();
void loadFromFile();
void clearInputBuffer();  // Function to clear input buffer
void resizeArray(); // Function to resize the dynamic array

int main() {
    int choice;

    // Allocate initial memory for students
    students = malloc(maxStudents * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Load existing students from file
    loadFromFile();

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Edit Student\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. Display List of Students\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear input buffer after reading choice

        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: deleteStudent(); break;
            case 4: searchStudent(); break;
            case 5: displayListOfStudents(); break;
            case 6: saveToFile(); free(students); return 0;
            default: printf("Invalid choice, please select (1-6).\n");
        }
    }
}

// Function to resize the student array if necessary
void resizeArray() {
    maxStudents *= 2; // Double the size
    students = realloc(students, maxStudents * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(1); // Exit if memory reallocation fails
    }
}

void addStudent() {
    if (numberOfStudentsAdded >= maxStudents) {
        resizeArray(); // Resize if the current capacity is reached
    }

    Student newStudent;
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);
    clearInputBuffer();

    // Validate roll number
    if (newStudent.rollNumber <= 0) {
        printf("Invalid roll number.\n");
        return;
    }

    // Check for duplicate roll number
    for (int i = 0; i < numberOfStudentsAdded; i++) {
        if (students[i].rollNumber == newStudent.rollNumber) {
            printf("Roll number %d is already assigned to %s.\n", newStudent.rollNumber, students[i].name);
            return;
        }
    }

    printf("Enter name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Remove newline

    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    clearInputBuffer();

    // Validate age
    if (newStudent.age <= 0) {
        printf("Invalid age.\n");
        return;
    }

    printf("Enter course: ");
    fgets(newStudent.course, sizeof(newStudent.course), stdin);
    newStudent.course[strcspn(newStudent.course, "\n")] = 0; // Remove newline

    students[numberOfStudentsAdded++] = newStudent; // Add new student to array
    printf("Student added successfully!\n");
}

void editStudent() {
    int rollNumber;
    printf("Enter roll number of the student to edit: ");
    scanf("%d", &rollNumber);
    clearInputBuffer();

    for (int i = 0; i < numberOfStudentsAdded; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Editing student: %s\n", students[i].name);
            printf("Enter new name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove newline

            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            clearInputBuffer();

            // Validate age
            if (students[i].age <= 0) {
                printf("Invalid age.\n");
                return;
            }

            printf("Enter new course: ");
            fgets(students[i].course, sizeof(students[i].course), stdin);
            students[i].course[strcspn(students[i].course, "\n")] = 0; // Remove newline

            printf("Student updated successfully!\n");
            return;
        }
    }
    printf("No student found with roll number %d.\n", rollNumber);
}

void deleteStudent() {
    int rollNumber;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &rollNumber);
    clearInputBuffer();

    for (int i = 0; i < numberOfStudentsAdded; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Shift students down to delete
            for (int j = i; j < numberOfStudentsAdded - 1; j++) {
                students[j] = students[j + 1];
            }
            numberOfStudentsAdded--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("No student found with roll number %d.\n", rollNumber);
}

void searchStudent() {
    int rollNumber;
    printf("Enter roll number of the student to search: ");
    scanf("%d", &rollNumber);
    clearInputBuffer();

    for (int i = 0; i < numberOfStudentsAdded; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Roll Number: %d, Name: %s, Age: %d, Course: %s\n", 
                   students[i].rollNumber, students[i].name, students[i].age, students[i].course);
            return;
        }
    }
    printf("No student found with roll number %d.\n", rollNumber);
}

void displayListOfStudents() {
    if (numberOfStudentsAdded == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("List of Students:\n");
    for (int i = 0; i < numberOfStudentsAdded; i++) {
        printf("Roll Number: %d, Name: %s, Age: %d, Course: %s\n", 
               students[i].rollNumber, students[i].name, students[i].age, students[i].course);
    }
}

void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numberOfStudentsAdded; i++) {
        fprintf(file, "%d,%s,%d,%s\n", 
                students[i].rollNumber, students[i].name, students[i].age, students[i].course);
    }
    fclose(file);
    printf("Students saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("No previous records found.\n");
        return;
    }

    while (fscanf(file, "%d,%20[^,],%d,%20[^,\n]", 
                  &students[numberOfStudentsAdded].rollNumber, 
                  students[numberOfStudentsAdded].name, 
                  &students[numberOfStudentsAdded].age, 
                  students[numberOfStudentsAdded].course) == 4) {
        numberOfStudentsAdded++;
        if (numberOfStudentsAdded >= maxStudents) {
            resizeArray(); // Resize if we exceed current capacity
        }
    }
    fclose(file);
    printf("Students loaded from file successfully!\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}
