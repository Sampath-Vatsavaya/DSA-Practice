#include<stdio.h>

#define max 100
int stack[max];
int top=-1;

void push(int data)
{
    if(top==max-1) 
    {
        printf("Stack overflow");
    }
    else
    {
        stack[++top]=data;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
        return;
    }
    top--;
}
int isFull()
{
    return top==max-1;
}
int isempty()
{
    return top==-1;
}
int peek()
{
    if(top==-1) return -1;
    return stack[top];
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    printf("\n");
    pop();
    pop();
    printf("%d",peek());
    
}