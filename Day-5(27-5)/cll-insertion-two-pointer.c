#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;
struct node *create(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void InsertAtBeginning(int data)
{
    struct node *temp=create(data);
    if(head==NULL)
    {   temp->next=temp;
        head=tail=temp;
        
    }
    else
    {
       
        temp->next=head;
         tail->next=temp;
        head=temp;
    }
}
void InsertAtEnd(int data)
{
     struct node *temp=create(data);
    if(head==NULL)
    {   temp->next=temp;
        head=tail=temp;
        
    }
    else
    {
       
        tail->next=temp;
        temp->next=head;
        tail=temp;
    }
}
void display(struct node* head)
{   if(head==NULL) return;
    struct node *temp=head->next;
    printf("%d ",head->data);
    while(temp!=head && temp!=NULL)
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
    display(head);
    InsertAtEnd(40);
    InsertAtEnd(50);
    InsertAtEnd(60);
    printf("\n");
    display(head);
}