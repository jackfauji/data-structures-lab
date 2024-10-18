#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sn;

void check_loop(sn* head) {
    if (head == NULL) return;

    sn *fast, *slow;
    fast = slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("Loop detected in the linked list.\n");
            return;
        }
    }
    printf("No loop detected in the linked list.\n");
}

int main() {
    sn *temp = NULL, *head = NULL, *newnode = NULL;
    int ch = 1;

    while (ch != 0)
    {
        newnode = (sn*)malloc(sizeof(sn));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter the data you want to enter: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode; 
            temp = newnode; 
        } else 
            temp->next = newnode;
            temp = newnode; 

        printf("Enter some more data (0 to stop, 1 to continue): ");
        scanf("%d", &ch);
    }
    if(temp!= NULL)
    {
        temp->next = head;
    }

    check_loop(head);
    
    return 0;
}
