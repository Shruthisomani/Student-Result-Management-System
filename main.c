#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

void calculate(struct Student *s) {
    s->total = 0;
    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->percentage = s->total / 5.0;

    if (s->percentage >= 90)
        s->grade = 'A';
    else if (s->percentage >= 75)
        s->grade = 'B';
    else if (s->percentage >= 60)
        s->grade = 'C';
    else if (s->percentage >= 50)
        s->grade = 'D';
    else
        s->grade = 'F';
}

int main() {
    struct Student students[100];
    int count = 0, choice, roll, found;

    while (1) {
        printf("\n==== Student Result Management System ====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter Roll Number: ");
            scanf("%d", &students[count].roll);

            printf("Enter Name: ");
            scanf(" %[^\n]", students[count].name);

            printf("Enter marks of 5 subjects:\n");
            for (int i = 0; i < 5; i++) {
                printf("Subject %d: ", i + 1);
                scanf("%d", &students[count].marks[i]);
            }

            calculate(&students[count]);
            count++;

            printf("Student added successfully!\n");
        }

        else if (choice == 2) {
            printf("\n--- Student Results ---\n");
            for (int i = 0; i < count; i++) {
                printf("\nRoll: %d\n", students[i].roll);
                printf("Name: %s\n", students[i].name);
                printf("Total: %d\n", students[i].total);
                printf("Percentage: %.2f\n", students[i].percentage);
                printf("Grade: %c\n", students[i].grade);
            }
        }

        else if (choice == 3) {
            printf("\nEnter Roll No to search: ");
            scanf("%d", &roll);

            found = 0;
            for (int i = 0; i < count; i++) {
                if (students[i].roll == roll) {
                    printf("\nRoll: %d\n", students[i].roll);
                    printf("Name: %s\n", students[i].name);
                    printf("Total: %d\n", students[i].total);
                    printf("Percentage: %.2f\n", students[i].percentage);
                    printf("Grade: %c\n", students[i].grade);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Student not found!\n");
        }

        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
