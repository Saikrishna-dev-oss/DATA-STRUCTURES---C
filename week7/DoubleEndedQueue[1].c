//DEQUE - DOUBLE ENDED QUEUE
#include <stdio.h>
#include <stdlib.h>

#define MAX 25

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
}Deque;

void initialize(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq)
{
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq)
{
    return (dq->front == -1);
}
void insertFront(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full. Cannot insert %d at front.\n", value);
        return;
    }
    if (isEmpty(dq) || dq->rear == -1) //any one
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = MAX - 1;
    }
    else
    {
        dq->front = dq->front - 1;
    }

    dq->arr[dq->front] = value;
    printf("Inserted %d at front.\n", value);
}

void insertRear(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full. Cannot insert %d at rear.\n", value);
        return;
    }
    if (isEmpty(dq) || dq->rear == -1) //any one
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }

    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear.\n", value);
}

void deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }

    int deletedValue = dq->arr[dq->front];
    if (dq->front == dq->rear) //only one element
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if (dq->front == MAX - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }

    printf("Deleted %d from front.\n", deletedValue);
}

void deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }

    int deletedValue = dq->arr[dq->rear];
    if (dq->front == dq->rear) //only one element
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = MAX - 1;
    }
    else
    {
        dq->rear--;
    }
    printf("Deleted %d from rear.\n", deletedValue);
}

void display(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int peekFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. No front element.\n");
        return -1;
    }
    printf("Front element: %d\n", dq->arr[dq->front]);
    return dq->arr[dq->front];
}

int peekRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. No rear element.\n");
        return -1;
    }
    printf("Rear element: %d\n", dq->arr[dq->rear]);
    return dq->arr[dq->rear];
}

int main()
{
    Deque dq;
    initialize(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    display(&dq);

    peekFront(&dq);
    peekRear(&dq);

    deleteFront(&dq);
    display(&dq);

    deleteRear(&dq);
    display(&dq);

    peekFront(&dq);
    peekRear(&dq);

    return 0;
}

