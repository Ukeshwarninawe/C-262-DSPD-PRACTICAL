#include <stdio.h>
#define MAX 50

char queue[MAX];
int front = -1, rear = -1;

void insert(char element) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert '%c'\n", element);
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = element;
        printf("'%c' inserted into queue.\n", element);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No element to delete.\n");
    } else {
        printf("'%c' deleted from queue.\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements (front to rear): ");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

void demonstrateOverflow() {
    rear = MAX - 1;
    printf("Demonstrating Overflow...\n");
    insert('Z');
}

void demonstrateUnderflow() {
    front = rear = -1;
    printf("Demonstrating Underflow...\n");
    delete();
}

int main() {
    int choice;
    char element;

    while (1) {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Demonstrate Overflow\n");
        printf("4. Demonstrate Underflow\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                demonstrateOverflow();
                break;
            case 4:
                demonstrateUnderflow();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}