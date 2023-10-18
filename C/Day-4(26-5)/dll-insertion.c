#include<stdio.h>
#include<stdlib.h>
struct node
{   struct node *prev;
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;
struct node *create(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void InsertAtBeginning(int data)
{
    struct node *temp= create(data);
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL) head=tail=temp;
    else{
        
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void InsertAtEnd(int data)
{
    struct node *temp=create(data);
    if(head==NULL) head=tail=temp;
    else{
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}
void display()
{
    if(head==NULL) return;
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    InsertAtBeginning(10);
    InsertAtBeginning(20);
    InsertAtBeginning(30);
    display();
    InsertAtEnd(40);
    InsertAtEnd(50);
    InsertAtEnd(60);
    printf("\n");
    display();
}