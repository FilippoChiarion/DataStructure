#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int top;
    int n;
    int *data;
}stack;

stack *NewStack(int n);
void push(stack *s,int value);
int pop(stack *s);
int top(stack *s);
int isStackEmpty(stack *s);
int isStackFull(stack *s);

int main() {
    int n,i,value;
    printf("How many elements would you like to add to the stack? ");
    scanf("%d",&n);
    stack *p=NewStack(n);
    printf("\nPlease enter the values for each element in the stack: \n\n");
    for(i=0;i<n;i++) {
        printf("Value for stack element %d: ",i+1);
        scanf("%d",&value);
        push(p,value);
    }
    printf("Top: %d\n",top(p));
    if(isStackEmpty(p))
        printf("Stack is empty!\n");
    if(!isStackFull(p))
        printf("Stack isn't full!\n");
    if(isStackFull(p))
        printf("Stack is full!\n");

    char r[10];
    do{printf("Do you want to remove an element from the stack? (yes/no): ");
    scanf("%s",r);
    if(strcmp(r,"yes")==0) {
        int popped_value=pop(p);
        if(popped_value!=-1) {
            printf("Removed element: %d\n",popped_value);
        }
    }
    printf("New top: %d\n",top(p));
    }while(strcmp(r,"yes")==0);
    free(p->data);
    free(p);
    return 0;
}

stack *NewStack(int n) {
    stack *p=(stack *)malloc(sizeof(stack));
    p->top=0;
    p->n=n;
    p->data=(int *)malloc(n*sizeof(int));
    return p;
}

void push(stack *s,int value) {
    if(isStackFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[s->top]=value;
    s->top++;
}

int pop(stack *s) {
    if(isStackEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    s->top--;
    return s->data[s->top];
}

int top(stack *s) {
    if(isStackEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->data[s->top-1];
}

int isStackEmpty(stack *s) {
    return s->top==0;
}

int isStackFull(stack *s) {
    return s->top==s->n;
}
