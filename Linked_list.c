#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *new_node = NULL;
    int choice;

    do {
        new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL) {
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            temp = new_node;
        }

        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = head;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
