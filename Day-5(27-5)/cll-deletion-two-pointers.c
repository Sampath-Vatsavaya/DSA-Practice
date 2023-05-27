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
void DeleteAtBeginning()
{   struct node *temp=head;

    if(head==NULL) return;
    else if(head==tail)
    {
        head=tail=NULL;
        free(temp);
    }
    else
    {
        head=head->next;
        tail->next=head;
        temp->next=NULL;
        free(temp);
    }
}
void DeleteAtEnd()
{
    struct node *temp=tail,*x=head;
    if(head==NULL) return;
     else if(head==tail)
    {
        head=tail=NULL;
        free(temp);
    }
    else
    {
        while(x->next!=tail) x=x->next;
        tail=x;
        tail->next=head;
        temp->next=NULL;
        free(temp);

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
    InsertAtEnd(10);
    InsertAtEnd(20);
    InsertAtEnd(30);
    
    InsertAtEnd(40);
    InsertAtEnd(50);
    InsertAtEnd(60);
    printf("\n");
    display(head);
    DeleteAtBeginning();
    DeleteAtBeginning();
    printf("\n");
    display(head);
    DeleteAtEnd();
    DeleteAtEnd();
    printf("\n");
    display(head);

}