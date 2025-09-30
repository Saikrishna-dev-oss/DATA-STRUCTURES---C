#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node *createNode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insert_at_begin(int data) {
    struct node *newnode = createNode(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    printf("Inserted %d at the Begin\n", data);
}

void insert_at_last(int data) {
    struct node *newnode = createNode(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    printf("Inserted %d at the End\n", data);
}

void insert_at_pos(int data, int pos) {
    if (pos <= 0) {
        printf("Invalid Position!!\n");
        return;
    }
    if (pos == 1) {
        insert_at_begin(data);
        return;
    }
    struct node *temp = head;
    int i = 1;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position Out of Range\n");
        return;
    }
    struct node *newnode = createNode(data);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    printf("Inserted %d at Position %d\n", data, pos);
}

void insert_after_key(int data, int key) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Key %d Not Found in List\n", key);
        return;
    }
    struct node *newnode = createNode(data);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    printf("Inserted %d after key %d\n", data, key);
}

void delete_at_begin() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted %d From the Begin\n", temp->data);
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct node *temp = head;
    if (temp->next == NULL) {
        printf("Deleted %d from End\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    printf("Deleted %d from End\n", temp->data);
    free(temp);
}

void delete_at_pos(int pos) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    if (pos == 1) {
        delete_at_begin();
        return;
    }
    struct node *temp = head;
    int i = 1;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    printf("Deleted %d from Position %d\n", temp->data, pos);
    free(temp);
}

void display_forward() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct node *temp = head;
    printf("List(Forward): ");
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_backward() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("List(Backward): ");
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int ch, val, pos, key;
    while (1) {
        printf("\n---Doubly linked List Menu---\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Insert at Position\n");
        printf("4.Insert after Key\n");
        printf("5.Delete at Begin\n");
        printf("6.Delete at End\n");
        printf("7.Delete at Position\n");
        printf("8.Display Forward\n");
        printf("9.Display Backward\n");
        printf("10.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter Value : ");
                scanf("%d", &val);
                insert_at_begin(val);
                break;
            case 2:
                printf("Enter Value : ");
                scanf("%d", &val);
                insert_at_last(val);
                break;
            case 3:
                printf("Enter Value and Position : ");
                scanf("%d%d", &val, &pos);
                insert_at_pos(val, pos);
                break;
            case 4:
                printf("Enter Value and Key : ");
                scanf("%d%d", &val, &key);
                insert_after_key(val, key);
                break;
            case 5:
                delete_at_begin();
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                printf("Enter Position : ");
                scanf("%d", &pos);
                delete_at_pos(pos);
                break;
            case 8:
                display_forward();
                break;
            case 9:
                display_backward();
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}