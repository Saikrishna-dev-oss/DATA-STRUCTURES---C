// BINARY SEARCH TREE WITH INSERT, TRAVERSAL, SEARCH AND DELETE OPERATIONS
//JUST FOR REFERENCE
#include <stdio.h>
#include <stdlib.h>

// Structure definition for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Initialize node data and pointers
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    // Base case: if tree is empty, create new node as root
    if (root == NULL) {
        return createNode(data);
    }
    
    // Recursive insertion based on BST property
    if (data < root->data) {
        // Insert in left subtree if data is smaller
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // Insert in right subtree if data is larger
        root->right = insert(root->right, data);
    }
    
    // Return the current node (unchanged if data already exists)
    return root;
}

// Function to find the minimum value node in a subtree
struct Node* findMin(struct Node* root) {
    // Keep moving left until we reach the leftmost node
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: if tree is empty
    if (root == NULL) {
        printf("Element %d not found in BST!\n", key);
        return root;
    }
    
    // Search for the node to be deleted
    if (key < root->data) {
        // Search in left subtree
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        // Search in right subtree
        root->right = deleteNode(root->right, key);
    } else {
        // Node found! Now handle three cases:
        
        // Case 1: Node with no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            printf("Deleting node %d\n", root->data);
            free(root);
            return NULL;
        }
        
        // Case 2: Node with only one child
        // Only right child exists
        else if (root->left == NULL) {
            printf("Deleting node %d\n", root->data);
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        // Only left child exists
        else if (root->right == NULL) {
            printf("Deleting node %d\n", root->data);
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 3: Node with two children
        else {
            printf("Deleting node %d\n", root->data);
            // Find inorder successor (smallest in right subtree)
            struct Node* temp = findMin(root->right);
            // Copy the inorder successor's content to this node
            root->data = temp->data;
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Function to search for an element in BST
void searchElement(struct Node* root, int key) {
    struct Node* current = root;
    
    while (current != NULL) {
        if (key == current->data) {
            printf("Element %d found in BST!\n", key);
            return;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    printf("Element %d not found in BST!\n", key);
}

// Function for in-order traversal (Left, Root, Right)
void inOrderTraversal(struct Node* root) {
    // Base case: if node is NULL, return
    if (root == NULL) {
        return;
    }
    
    // Recursive in-order traversal
    inOrderTraversal(root->left);      // Traverse left subtree
    printf("%d ", root->data);         // Visit the root node
    inOrderTraversal(root->right);     // Traverse right subtree
}

// Function for pre-order traversal (Root, Left, Right)
void preOrderTraversal(struct Node* root) {
    // Base case: if node is NULL, return
    if (root == NULL) {
        return;
    }
    
    // Recursive pre-order traversal
    printf("%d ", root->data);         // Visit the root node first
    preOrderTraversal(root->left);     // Traverse left subtree
    preOrderTraversal(root->right);    // Traverse right subtree
}

// Function for post-order traversal (Left, Right, Root)
void postOrderTraversal(struct Node* root) {
    // Base case: if node is NULL, return
    if (root == NULL) {
        return;
    }
    
    // Recursive post-order traversal
    postOrderTraversal(root->left);    // Traverse left subtree first
    postOrderTraversal(root->right);   // Traverse right subtree
    printf("%d ", root->data);         // Visit the root node last
}

// Main function - Driver program
int main() {
    struct Node* root = NULL;  // Initialize root pointer to NULL (empty tree)
    int choice, value;
    
    // Menu-driven interface
    do {

    
        printf("\n=== BINARY SEARCH TREE OPERATIONS ===\n\n");
        printf("1. Insert element\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Search element\n");
        printf("6. Delete element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Insert single element
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
                
            case 2:
                // Display in-order traversal
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
                
            case 3:
                // Display pre-order traversal
                printf("Pre-order Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
                
            case 4:
                // Display post-order traversal
                printf("Post-order Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
                
            case 5:
                // Search for element
                printf("Enter element to search: ");
                scanf("%d", &value);
                searchElement(root, value);
                break;
                
            case 6:
                // Delete element
                printf("Enter element to delete: ");
                scanf("%d", &value);
                printf("Before deletion - In-order: ");
                inOrderTraversal(root);
                printf("\n");
                
                root = deleteNode(root, value);
                
                printf("After deletion - In-order: ");
                inOrderTraversal(root);
                printf("\n");
                break;
                
            case 7:
                // Exit program
                printf("Exiting program...\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 7);
    
    return 0;
}


