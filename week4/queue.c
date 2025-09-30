#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};
int isEmpty(struct queue *q) {
    return q->front == NULL;
}
void Enqueue(struct queue *q,int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(!newnode) {
        printf("Queue Overflow ! Memory not allocated");
        return;
    }
    newnode ->data = data;
    newnode->next = NULL;
    if(isEmpty(q)) {
        q ->front = q ->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
    printf("Enqueued %d to the Queue\n",data);
}
int dequeue(struct queue *q) {
    if(isEmpty(q)) {
        printf("Queue Underflow !Unable to Dequeue\n");
        return -1;
    }
    struct node *temp = (q) ->front;
    int dequeued = q->front->data;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
    printf("Dequeued %d from the Queue\n",dequeued);
}
int peek(struct queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->front->data;
}
void display(struct queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    struct node *temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct queue *queue = (struct queue*)malloc(sizeof(struct queue));
    queue->front = queue->rear = NULL;
    int ch,val;
    while (1)
    {
        printf("Enter Your Choice:");
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("Enter Value to Insert:");
                scanf("%d",&val);
                Enqueue(queue,val);break;
        case 2: dequeue(queue);break;
        case 3: printf("Front Element :%d\n",peek(queue));break;
        case 4: display(queue);break;
        case 5: exit(0);
        default:printf("Invalid Option !!\n");
        }
    }
    return 0;
}
