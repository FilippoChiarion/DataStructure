#include <stdio.h>
#include <stdlib.h>

#define N 30

typedef struct{
    int top;
    int data[N];
}stack;

stack *NewStack();
void push(stack *s, int value);
int pop(stack *s);
int top(stack *s);
int isStackEmpty(stack *s);
int isStackFull(stack *s);

int main(){
    stack *p;
    p=NewStack();
    push(p,15);
    push(p,20);
    push(p,30);
    pop(p);
    pop(p);
    printf("Top: %d\n",top(p));
    if(isStackEmpty(p)){
        printf("Stack is empty!\n");
    }
    if(!isStackFull(p)){
        printf("Stack isn't full!\n");
    }
    if(isStackFull(p)){
        printf("Stack is full!\n");
    }

}

stack *NewStack(){
    stack *p=(stack *)malloc(sizeof(stack));
    p->top=0;
    return p;
}

void push(stack *s, int value) {
    if(isStackFull(s)){
        printf("Stack overflow!");
        return;
    }
    s->data[s->top]=value;
    s->top++;
}

int pop(stack *s) {
    if(isStackEmpty(s)){
        printf("Stack underflow!\n");
        return -1;
    }
    s->top--;
    return s->data[s->top];
}

int top(stack *s) {
    if(isStackEmpty(s)){
        printf("Stack underflow!\n");
        return -1;
    }
    return s->data[s->top-1];
}

int isStackFull(stack *s){
    return s->top==N;
}

int isStackEmpty(stack *s){
    return s->top==0;

}
