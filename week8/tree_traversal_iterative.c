//BINARY TREE TRAVERSAL (ITERATIVE)
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

// Stack for iterative traversals
struct StackNode {
    struct Node* treeNode;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

// Create stack
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = NULL;
    return s;
}

// Push operation
void push(struct Stack* s, struct Node* node) {
    struct StackNode* new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->treeNode = node;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop operation
struct Node* pop(struct Stack* s) {
    if (s->top == NULL) return NULL;
    struct StackNode* temp = s->top;
    struct Node* node = temp->treeNode;
    s->top = s->top->next;
    free(temp);
    return node;
}

// Check if stack is empty
int isStackEmpty(struct Stack* s) {
    return s->top == NULL;
}

// Queue for level order
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

// Preorder: Root -> Left -> Right
void preorder(struct Node* root) {
    if (root == NULL) return;
    
    struct Stack* stack = createStack();
    push(stack, root);
    
    printf("Preorder: ");
    while (!isStackEmpty(stack)) {
        struct Node* node = pop(stack);
        printf("%c ", node->data);
        
        // Push right first, then left (so left is processed first)
        if (node->right != NULL) push(stack, node->right);
        if (node->left != NULL) push(stack, node->left);
    }
    free(stack);
}

// Inorder: Left -> Root -> Right
void inorder(struct Node* root) {
    struct Stack* stack = createStack();
    struct Node* current = root;
    
    printf("Inorder: ");
    while (current != NULL || !isStackEmpty(stack)) {
        // Reach the leftmost node
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        
        // Current is NULL at this point
        current = pop(stack);
        printf("%c ", current->data);
        
        // Visit the right subtree
        current = current->right;
    }
    free(stack);
}

// Postorder: Left -> Right -> Root (using two stacks)
void postorder(struct Node* root) {
    if (root == NULL) return;
    
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();
    
    push(stack1, root);
    
    printf("Postorder: ");
    while (!isStackEmpty(stack1)) {
        struct Node* node = pop(stack1);
        push(stack2, node);
        
        if (node->left != NULL) push(stack1, node->left);
        if (node->right != NULL) push(stack1, node->right);
    }
    
    // Print stack2 contents (which are in postorder)
    while (!isStackEmpty(stack2)) {
        struct Node* node = pop(stack2);
        printf("%c ", node->data);
    }
    
    free(stack1);
    free(stack2);
}

// Level Order
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    
    struct Queue* q = createQueue();
    enqueue(q, root);
    
    printf("Level Order: ");
    while (!isEmpty(q)) {
        struct Node* node = dequeue(q);
        printf("%c ", node->data);
        
        if (node->left != NULL) enqueue(q, node->left);
        if (node->right != NULL) enqueue(q, node->right);
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
        int levelSize = 1 << currentHeight; // 2^currentHeight
        
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
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    levelOrder(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}