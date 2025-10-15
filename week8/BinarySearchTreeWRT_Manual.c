
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *createNode (int data) {

    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if(!newNode) {
        printf("Unable to Allocate Memory !!\n");
        exit(0);
    }
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}

struct node *insert(struct node *root,int data) {
    

    if(root == NULL) {
        return createNode(data);
    }
   if(data < root->data) {
        root->leftChild = insert(root->leftChild,data);
        printf("inserted");
    }
    else if(data > root->data) {
        root->rightChild = insert(root->rightChild,data);
    }

    return root;
}

void inOrderTraversal(struct node *root) {

    if(root != NULL)
    {
        inOrderTraversal(root->leftChild);
        printf("%d ",root->data);
        inOrderTraversal(root->rightChild);
    }

}

void preOrderTraversal(struct node *root) {

    if(root != NULL)
    {
        printf("%d ",root->data);
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);

    }
}

void postOrderTraversal(struct node *root) {

    if(root != NULL)
    {
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        printf("%d ",root->data);

    }
}

int main() {
    struct node *root = NULL;
    int choice, data;

    while (1) {
        printf("\n\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}