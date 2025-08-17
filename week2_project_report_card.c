#include <stdio.h>
#include <string.h>

// Number of students
#define NUM_STUDENTS 5

// Function prototypes
void inputStudentData(char names[][50], int marks[][3]);
int calculateTotal(int marks[]);
float calculateAverage(int total);
char calculateGrade(float average);
void displayReport(char names[][50], int marks[][3]);

int main() {
    char studentNames[NUM_STUDENTS][50];
    int studentMarks[NUM_STUDENTS][3]; // Assuming 3 subjects per student

    // Input data
    inputStudentData(studentNames, studentMarks);

    // Display report
    displayReport(studentNames, studentMarks);

    return 0;
}

// Function to input student names and marks
void inputStudentData(char names[][50], int marks[][3]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]s", names[i]); // Read full name with spaces

        for (int j = 0; j < 3; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }
}

// Function to calculate total marks of a student
int calculateTotal(int marks[]) {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        total += marks[i];
    }
    return total;
}

// Function to calculate average marks
float calculateAverage(int total) {
    return total / 3.0;
}

// Function to calculate grade based on average
char calculateGrade(float average) {
    if (average >= 90)
        return 'A';
    else if (average >= 75)
        return 'B';
    else if (average >= 50)
        return 'C';
    else
        return 'D';
}

// Function to display the report
void displayReport(char names[][50], int marks[][3]) {
    printf("\n----- STUDENT REPORT CARD -----\n");
    printf("Name\t\tTotal\tAverage\tGrade\n");
    printf("---------------------------------\n");

    for (int i = 0; i < NUM_STUDENTS; i++) {
        int total = calculateTotal(marks[i]);
        float average = calculateAverage(total);
        char grade = calculateGrade(average);

        printf("%-15s %d\t%.2f\t%c\n", names[i], total, average, grade);
    }
}
