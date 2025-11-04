#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", element);
    } else {
        stack[++top] = element;
        printf("%d pushed onto stack.\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void checkPalindrome() {
    char str[50];
    char rev[50];
    int i, len;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);

    len = strlen(str);
    top = -1; 

    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    for (i = 0; i < len; i++) {
        rev[i] = stack[top--];
    }
    rev[i] = '\0';

    if (strcmp(str, rev) == 0)
        printf("'%s' is a Palindrome.\n", str);
    else
        printf("'%s' is NOT a Palindrome.\n", str);
}

void demonstrateOverflow() {
    top = MAX - 1;
    printf("Demonstrating Overflow...\n");
    push(999); 
}

void demonstrateUnderflow() {
    top = -1;
    printf("Demonstrating Underflow...\n");
    pop(); 
}

int main() {
    int choice, element;

    while (1) {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow\n");
        printf("5. Demonstrate Underflow\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                demonstrateOverflow();
                break;
            case 5:
                demonstrateUnderflow();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}