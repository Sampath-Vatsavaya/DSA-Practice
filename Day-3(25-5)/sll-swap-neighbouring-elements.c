#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
void swap_elements(struct node *head)
{
    if(head==NULL) return;
    struct node *p,*q;
    p=head;
    q=head->next;
    while(q!=NULL)
    {
        int temp = p->data;
        p->data= q->data;
        q->data = temp;
        p=q->next;
        q= (p==NULL)? NULL : p->next;
    }
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
  printf("\n");
  swap_elements(head);
  display(head);
}