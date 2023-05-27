#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL;
struct node *create(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void InsertAtEnd(int data)
{
     struct node *temp=create(data),*x=head;
    if(head==NULL)
    {  
      temp->next=temp;
        head=temp;
    }
    else
    {
       
       while(x->next!=head)
        {
            x=x->next;
        }
        x->next=temp;
        temp->next=head;
        
    }
}
void DeleteAtBeginning()
{
    struct node *temp=head,*x=head;
    if(head==NULL) return;
    while(x->next!=head)
        {
            x=x->next;
        }
    head=head->next;
    temp->next=NULL;
    x->next=head;
    free(temp);
}
void DeleteAtEnd()
{
    struct node *temp=head,*x=head;
    if(head==NULL) return;
    while(temp->next!=head)
        {
            x=temp;
            temp=temp->next;
        }
    temp->next=NULL;
    x->next=head;
    free(temp);
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