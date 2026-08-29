
#include <stdio.h>

#define TOTAL_STUDENTS 65

struct Student {
    char name[50];
    int rollNo;
    float marks;
};

int main() {
    struct Student students[TOTAL_STUDENTS];
    int i;
    int found = 0;

    for (i = 0; i < TOTAL_STUDENTS; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\n----- Students with marks more than 75 -----\n");
    printf("%-15s %-10s %-10s\n", "Name", "Roll No", "Marks");

    for (i = 0; i < TOTAL_STUDENTS; i++) {
        if (students[i].marks > 75) {
            printf("%-15s %-10d %-10.2f\n",
                   students[i].name, students[i].rollNo, students[i].marks);
            found = 1;
        }
    }

    if (!found)
        printf("No student scored more than 75 marks.\n");

    return 0;
}
