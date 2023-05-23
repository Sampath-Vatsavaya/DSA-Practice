#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head=NULL;


void InsertAtBeginning(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    /* Simpler logic:
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
    */
}

void InsertAtEnd(int data)
{
    struct node *temp= (struct node*)malloc(sizeof(struct node)),*x;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        x=head;
        while(x->next!=NULL)
        {
            x=x->next;
        }
        x->next=temp;
    }
    
}
void InsertAtPosition(int data,int pos)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node)),*x,*y;
    temp->data=data;
    temp->next=NULL;

    if(head==NULL || pos==1)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        x=head;
        while(--pos)
        {
            y=x;
            x=x->next;
            if(x==NULL) break;
        }
        y->next=temp;
        temp->next=x;
    }

    
}
void display()
{
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
    InsertAtBeginning(40);
    InsertAtEnd(50);
    InsertAtEnd(60);
    InsertAtPosition(80,2);
    InsertAtPosition(90,3);
    display();
}