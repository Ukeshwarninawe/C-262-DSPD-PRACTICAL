#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Function to delete a leaf node
struct Node* deleteLeaf(struct Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = deleteLeaf(root->left, value);
    else if (value > root->data)
        root->right = deleteLeaf(root->right, value);
    else {
        // Check if it's a leaf node
        if (root->left == NULL && root->right == NULL) {
            printf("Leaf node %d deleted successfully.\n", value);
            free(root);
            return NULL;
        } else {
            printf("Node %d is not a leaf node. Cannot delete.\n", value);
        }
    }
    return root;
}

// Function to display tree in inorder
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* found;

    while (1) {
        printf("\n\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Search an element\n");
        printf("3. Delete leaf element\n");
        printf("4. Display Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Element inserted successfully.\n");
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = search(root, value);
                if (found == NULL)
                    printf("NULL (Element not found)\n");
                else
                    printf("Found (Element present in BST)\n");
                break;

            case 3:
                printf("Enter leaf node value to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}