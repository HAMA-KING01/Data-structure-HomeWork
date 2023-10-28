//5-Write the function that searches records by student name in the list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int number;
    char name[50];
    int age;
    struct student* next;
};

void search_students(struct student* head, char* name) {
    int count = 0;

    printf("Student information:\n");
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("%d- %s %d\n", head->number, head->name, head->age);
            count++;
        }
        head = head->next;
    }

    if (count == 0) {
        printf("No students found with the name '%s'.\n", name);
    } else {
        printf("Total students found: %d\n", count);
    }
}

int main() {
    struct student* head = NULL;

    // Code to store students in the list goes here...

    char name[50];
    printf("Enter the name of the student to search: ");
    scanf("%s", name);

    search_students(head, name);

    return 0;
}
