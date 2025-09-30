// CIrcular Queue

#include<stdio.h>
#include<stdlib.h>

#define MAX 30
typedef struct {
    int queue[MAX];
    int front, rear;
    int size;
} circularQueue;

void initQueue(circularQueue *s) {
    s->front = s->rear = -1;
    s->size = MAX;
}


int isFull(circularQueue *s) {
    return ((s->rear + 1) % s->size == s -> front );   
}

int isEmpty(circularQueue *s) {
    return(s -> front == -1);
}

void enqueue(circularQueue *s,int value) {
    if(isFull(s)) {
        printf("Queue is Full\n");
        return;
    } 
    if(isEmpty(s)) 
        s->front = s->rear = 0;
    else 
        s->rear = (s->rear+1)% s->size;
    s->queue[s->rear] = value;
    printf("Inserted %d\n",value);
}

int dequeue(circularQueue *s) {
    if(isEmpty(s)) {
        printf("Queue is Empty\n");
        return -1;
    }
    
    int temp = s->queue[s->front];
    if(s->front == s->rear) {
        s->front = s->rear = -1;
    } else {
        s->front = (s->front+1) % s->size;
    }
    printf("\nElement Removed");
    return temp;
}

void displayQueue(circularQueue *s) {
    if(isEmpty(s)) {
        printf("Queue is Empty\n");
        return ;
    }
    int i = s->front;
    printf("Queue Elements are: ");
    while (1)
    {
        printf("%d ",s->queue[i]);
        if(i == s->rear) break;
        i = (i+1) % s->size;   
    }
    printf("\n");
}


int main() {
    circularQueue q;
    int ch,val;
    initQueue(&q);
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n:");
        scanf("%d",&ch);

        switch(ch) {
            case 1:printf("Enter value : ");
                    scanf("%d",&val);
                    enqueue(&q,val);break;
            case 2:dequeue(&q);break;
            case 3:displayQueue(&q);break;
            case 4:exit(0);
            default:printf("Invalid Choice!!");
        }
    }
    return 0;
}