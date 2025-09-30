#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
int isEmpty(struct node *top) {
    return top == NULL;
}
void push(struct node **top,int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(!newnode) {
        printf("Stack Overflow ! Memory not allocated");
    }
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
    printf("Pushed %d into Stack\n",data);
}
int pop(struct node **top) {
    if(isEmpty(*top)) {
        printf("Stack Underflow ! Cannot Pop\n");
        return -1;
    }
    struct node *temp = *top;
    int popped = temp->data;
    *top = (*top) -> next;
    printf("%d is Popped\n",popped);
    free(temp);
    return popped;
}
int peek(struct node *top) {
    if(isEmpty(top)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return top->data;
}
void display(struct node *top) {
    if(isEmpty(top)) {
        printf("Stack  Is Empty\n");
        return;
    }
    printf("Stack Elements (Top to Bottom) :\n");
    while(top!=NULL) {
        printf("%d ->",top->data);
        top = top->next;
    }
    printf("NULL\n");
}
int main () {
    struct node *stack = NULL;
    int ch,val;
    while (1)
    {
        printf("Enter Your Choice:");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("Enter Value to Insert:");
                scanf("%d",&val);
                push(&stack,val);break;
        case 2: pop(&stack);break;
        case 3: printf("Top Element :%d\n",peek(stack));break;
        case 4: display(stack);break;
        case 5: exit(0);
        default:printf("Invalid Option !!\n");
        }
    }
    return 0;
}