//2-Add 100 randomly generated numbers to the list, write the c code that sorts all the numbers entered from largest to smallest and prints them on the screen.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* next;
};

void add_random_numbers(struct node** head_ref) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int num = rand() % 100;
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
}

void sort_list(struct node** head_ref) {
    struct node* current = *head_ref;
    struct node* index = NULL;
    int temp;

    if (*head_ref == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data < index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }

                index = index->next;
            }

            current = current->next;
        }
    }
}

void print_list(struct node* head) {
    printf("Sorted numbers (from largest to smallest): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    add_random_numbers(&head);
    sort_list(&head);
    print_list(head);

 
    struct node* current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
