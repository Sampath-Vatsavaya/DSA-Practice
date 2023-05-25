#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head=NULL,*head2=NULL;



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

void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int middle_element(struct node *head)
{   if(head==NULL) return -1;
    struct node *temp=head,*mid=head;
    while(temp->next!=NULL && temp->next->next!=NULL)
    {
        mid=mid->next;
        temp=temp->next->next;

    }
    return mid->data;
}
int main()
{
    
    InsertAtEnd(1);
    InsertAtEnd(2);
    InsertAtEnd(3);
    InsertAtEnd(4);
    InsertAtEnd(5);
    InsertAtEnd(6);
    InsertAtEnd(7);

    display(head);
    printf("\nMiddle Element=%d",middle_element(head));
}