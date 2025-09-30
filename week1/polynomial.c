
// Addition of Polynnomials

#include<stdio.h>
#include<stdlib.h>

struct term {
    int coeff;
    int exp;
    struct term *next;
};

struct term *createTerm(int c,int e) {

    struct term *newTerm = (struct term *)malloc(sizeof(struct term));
    
    newTerm->coeff = c;
    newTerm->exp = e;
    newTerm->next = NULL;
    return newTerm;
}

void appendTerm(struct term **head,int c,int e) {

    struct term *newTerm = createTerm(c,e);
    if(*head == NULL) {
        *head = newTerm;
    }
    else {
        struct term *temp = *head;
        while(temp->next !=NULL)
            temp = temp->next;
        temp ->next = newTerm;
    }
}

struct term  *addPolynomials(struct term *p1,struct term *p2) {

    struct term *result = NULL;
    
    while(p1 != NULL && p2 != NULL) {
        if(p1 ->exp == p2->exp) {
            appendTerm(&result,p1->coeff + p2->coeff,p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }

        else if(p1->exp > p2->exp) {
            appendTerm(&result,p1->coeff,p1->exp);
            p1 = p1->next;
        }
        else {
            appendTerm(&result,p2->coeff,p2->exp);
            p2 = p2->next;
        }
    }
    while(p1!=NULL) {
        appendTerm(&result,p1->coeff,p1->exp);
        p1 = p1->next;
    }
    while(p2!=NULL) {
        appendTerm(&result,p2->coeff,p2->exp);
        p2 = p2->next;
    }
    return result;
}

void display(struct term *head) {
    struct term *temp = head;
    while (temp!=NULL) 
    {
        /* code */
        printf("%dx^%d",temp->coeff,temp->exp);
        if(temp->next!=NULL) {
            printf("+");
        }
        temp = temp->next;
    }
    printf("\n");
    
}

int main () {
    int i,num,k;
    struct term *poly1 = NULL;
    struct term *poly2 = NULL;

    for(int k = 1;k<=2;k++) {
        printf("\nEnter the Number of terms in POlynomial %d : ",k);
        scanf("%d",&num);
        for(i=1;i<=num;i++) {
            int c,e;
            printf("\nEnter the %d Term Co-Efficient of poly %d : ",i,k);
            scanf("%d",&c);

            printf("\nEnter the %d Term Exponent of poly %d : ",i,k);
            scanf("%d",&e);
            if(k == 1) {
                appendTerm(&poly1, c, e);
            } 
            else if(k==2){
                appendTerm(&poly2, c, e);
            }
        }

    }
    printf("\nPoly 1: ");
    display(poly1);
    printf("\nPoly 2: ");
    display(poly2);
    struct term *sum = addPolynomials(poly1,poly2);
    printf("Sum is: ");
    display(sum);
    return 0;
}
