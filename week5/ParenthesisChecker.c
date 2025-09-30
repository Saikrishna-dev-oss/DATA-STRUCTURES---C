//EXPRESSION PARENTHESIS CHECKER
#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} stack;

void init(stack *s) {
    s->top = -1;
}


void push(stack *s,char c)
{
    if(s->top < MAX-1)
    {
        s->data[++(s->top)] = c;
    }
    else
    {
        printf("ERROR. Stack overflow");
    }
}

char pop(stack *s)
{
    if(s -> top == -1)
    {
        printf("STACK UNDERFLOW\n");
        return 0;
    }
    return s -> data[(s -> top)--];
}

int isMatchingPair(char open, char close)
{
    return (open == '('&&close==')')||(open == '{'&& close == '}')||(open == '['&& close == ']');
}

int  isParanthesisBalanced(char *exp)
{
    stack s;
    init(&s);
    for(int i=0 ;exp[i] != '\0';i++)
    {
        char c = exp[i];
        if(c == '(' || c == '{' || c == '[')
        {
            push(&s,c);
        }
        else if( c == ')' || c == '}' || c == ']')
        {
            if(s.top == -1 || !isMatchingPair(pop(&s),c))
            {
                return 0;
            }
        }
    }
    return s.top == -1;
}

int main()
{
    char exp[MAX];

    printf("EXPRESSION CHECKER:\nEnter the Expression : ");
    gets(exp);
    if(isParanthesisBalanced(exp))
    {
        printf("\nExpression is Valid and Balanced\n");
    }
    else
    {
        printf("\nExpression is NOT Valid or Balanced\n");
    }
    return 0;
}
