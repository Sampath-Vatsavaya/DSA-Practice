#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;
void push(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Stack overflow");
        return;
    }
    temp->data=data;
    temp->next=top;
    top=temp;
}
void pop()
{   struct node *temp=top;
    if(top==NULL) 
    {
        printf("Stack underflow");
        return;
    }
    top=top->next;
    temp->next=NULL;
    free(temp);
}
void display()
{
    struct node *temp=top;
    while(temp!=NULL) 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
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
    display();
}