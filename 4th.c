//4-Write a function that stores the student number, name and age, traverses all the nodes in the list, writes all the student information on the screen and counts it.
#include <stdio.h>
#include <stdlib.h>


typedef struct student {
  int number;
  char name[100];
  int age;
  struct student *next;
} Student;


void add_student(Student **head, int number, char *name, int age) {
  Student *new_student = malloc(sizeof(Student));
  new_student->number = number;
  strcpy(new_student->name, name);
  new_student->age = age;
  new_student->next = NULL;

  if (*head == NULL) {
    *head = new_student;
  } else {
    Student *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = new_student;
  }
}


void traverse_and_print(Student *head) {
  int count = 0;

  Student *current = head;
  while (current != NULL) {
    printf("Student number: %d\n", current->number);
    printf("Student name: %s\n", current->name);
    printf("Student age: %d\n\n", current->age);

    count++;
    current = current->next;
  }

  printf("Total number of students: %d\n", count);
}


int main() {
  Student *head = NULL;


  add_student(&head, 2010213624, "mohammed", 22);
  add_student(&head, 2010213623, "ahmet", 22);
  add_student(&head, 2015021323, "Yagmur", 22);

  // Traverse the linked list and print the student information
  traverse_and_print(head);

  return 0;
}
