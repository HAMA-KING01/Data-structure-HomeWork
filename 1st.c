//1- Write a function that adds all odd numbers to the beginning of the list and all even numbers to the end of the list until -1 is entered from the keyboard.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void add_odd_even_numbers() {
    struct node* head = NULL;
    struct node* tail = NULL;
    int num;

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;

        if (num % 2 == 0) {
            if (tail == NULL) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        } else {
            if (head == NULL) {
                head = tail = new_node;
            } else {
                new_node->next = head;
                head = new_node;
            }
        }
    }

    printf("The list is: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    add_odd_even_numbers();
    return 0;
}
