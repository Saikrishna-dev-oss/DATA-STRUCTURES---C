//BINARY TREE TRAVERSAL (RECURSIVE)
#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Preorder
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

// Postorder
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

// Level Order using Queue
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        struct Node* node = dequeue(q);
        printf("%c ", node->data);
        if (node->left) enqueue(q, node->left);
        if (node->right) enqueue(q, node->right);
    }
    free(q);
}

// Build tree level by level based on user input
struct Node* buildTreeLevelOrder(int height) {
    if (height < 0) return NULL;
    
    struct Queue* q = createQueue();
    char data;
    
    printf("Enter data for root (height 0): ");
    scanf(" %c", &data);
    struct Node* root = newNode(data);
    enqueue(q, root);
    
    int currentHeight = 0;
    
    while (!isEmpty(q) && currentHeight < height) {
        int levelSize = 1 << currentHeight;
        
        for (int i = 0; i < levelSize; i++) {
            struct Node* current = dequeue(q);
            
            if (currentHeight < height) {
                printf("Enter left child of %c (height %d): ", current->data, currentHeight + 1);
                scanf(" %c", &data);
                current->left = newNode(data);
                enqueue(q, current->left);
                
                printf("Enter right child of %c (height %d): ", current->data, currentHeight + 1);
                scanf(" %c", &data);
                current->right = newNode(data);
                enqueue(q, current->right);
            }
        }
        currentHeight++;
    }
    
    free(q);
    return root;
}

// Free the entire tree to prevent memory leaks
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main
int main() {
    int height;
    
    printf("Enter the height of the tree (index starts from 0): ");
    scanf("%d", &height);
    
    printf("\nBuilding tree level by level:\n");
    struct Node* root = buildTreeLevelOrder(height);
    
    printf("\nTraversals:\n");
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nLevel Order: ");
    levelOrder(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}