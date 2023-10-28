//6- Write the function that deletes the next node from the node with the searched student name in the list.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
};

void delete_node(struct Node* head, char* student_name) {
    struct Node* temp = head;
    while (temp->next != NULL) {
        if (strcmp(temp->name, student_name) == 0) {
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    strcpy(head->name, "ahmet");
    head->next = (struct Node*)malloc(sizeof(struct Node));
    strcpy(head->next->name, "mohammed");
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    strcpy(head->next->next->name, "yamgur");
    head->next->next->next = NULL;

    printf("Linked list before deletion:\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("NULL\n");

    delete_node(head, "mohammed");

    printf("Linked list after deletion:\n");
    current = head;
    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
