#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head =NULL;
void display() {
    struct node *temp = head;
    if(head == NULL) {
        printf("List is empty !!\n");
        return;
    }
    do {
        printf("%d->",temp->data);
        temp = temp ->next;
    }while(temp!=head);
    printf("(Back to head)\n");
}
void insert_at_last(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = val;
    newnode -> next = NULL;
    if(head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }
    struct node *temp = head;
    while(temp->next != head) 
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
}
void insert_at_begin(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }
    struct node *temp = head;
    while(temp->next != head) 
        temp = temp->next;
    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}
void inser_at_pos(int val,int pos) {
    if(pos == 1) {
        insert_at_begin(val);
        return;
    }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    int i;
    struct node *temp = head;
    for(i = 1;i<pos-1 && temp->next != head ;i++) 
        temp = temp->next;
    if(i!=pos-1) {
        printf("Position Out of Range !!\n");
        free(newnode);
        return;
    }
    newnode ->next = temp->next;
    temp->next = newnode;
}
void delete_at_begin() {
    if(head == NULL) {
        printf("List is Empty !!\n");
        return;
    }
    struct node *temp = head;
    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct node *last = head;
    while(last->next != head) 
        last = last ->next;
    head = head->next;
    last ->next = head;
    free(temp);
}
void delete_at_lat() {
    if(head == NULL) {
        printf("List is Empty !!\n");
        return;
    }
    struct node *temp = head,*prev = NULL;
    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    while(temp ->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}
void delete_at_pos(int pos) {
    if(head == NULL) {
        printf("List is Empty !!\n");
        return;
    }
    if(pos == 1) {
        delete_at_begin();
        return;
    }
    struct node *temp = head,*prev = NULL;
    int i;
    for(i=1;i<pos && temp->next != head;i++) {
        prev = temp;
        temp = temp->next;
    }
    if(i!=pos) {
        printf("Position Out of Range !!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
int main() {
    
    insert_at_last(10);
    insert_at_last(20);
    insert_at_last(30);
    display();
    insert_at_begin(5);
    display();
    inser_at_pos(15,3);
    display();
    delete_at_begin();
    display();
    delete_at_pos(2);
    delete_at_lat();
    display();
    return 0;

}