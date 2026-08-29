
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void addAtBegin(int value);
void append(int value);
void addAfter(int searchValue, int value);
void display(void);
int countNodes(void);
void deleteNode(int value);
void reversePrint(struct Node *node);
void reverseList(void);
void search(int value);
void sortList(void);
void freeList(void);

int main() {
    int choice, value, searchValue;

    while (1) {
        printf("\nEnter your Choice\n");
        printf("1. Add at Beginning\n");
        printf("2. Append (Add at End)\n");
        printf("3. Add After a Node\n");
        printf("4. Display\n");
        printf("5. Count Nodes\n");
        printf("6. Delete a Node\n");
        printf("7. Reverse Print (without reversing list)\n");
        printf("8. Reverse the List\n");
        printf("9. Search an Element\n");
        printf("10. Sort the List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to add at beginning: ");
                scanf("%d", &value);
                addAtBegin(value);
                break;

            case 2:
                printf("Enter value to append: ");
                scanf("%d", &value);
                append(value);
                break;

            case 3:
                printf("Enter the value after which to insert: ");
                scanf("%d", &searchValue);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                addAfter(searchValue, value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Number of nodes: %d\n", countNodes());
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 7:
                if (head == NULL)
                    printf("List is empty.\n");
                else {
                    printf("List in reverse order: ");
                    reversePrint(head);
                    printf("\n");
                }
                break;

            case 8:
                reverseList();
                printf("List reversed successfully.\n");
                break;

            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 10:
                sortList();
                printf("List sorted successfully.\n");
                break;

            case 11:
                freeList();
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
void addAtBegin(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d added at the beginning.\n", value);
}
void append(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d appended to the list.\n", value);
}
void addAfter(int searchValue, int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != searchValue)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", searchValue);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d added after %d.\n", value, searchValue);
}
void display(void) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int countNodes(void) {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("%d deleted from the list.\n", value);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list.\n", value);
}
void reversePrint(struct Node *node) {
    if (node == NULL)
        return;
    reversePrint(node->next);
    printf("%d ", node->data);
}
void reverseList(void) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void search(int value) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}

void sortList(void) {
    if (head == NULL || head->next == NULL)
        return;

    struct Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void freeList(void) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
