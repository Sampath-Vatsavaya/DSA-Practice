#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL;

void InsertAtEnd(int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node)),*x;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else{
        x=head;
        while(x->next!=NULL)
        {
            x=x->next;
        }
        x->next=temp;
    }
    
}
int count_iterative()
{
    struct node *temp=head;
    int c=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}
int count_recursive(struct node* head)
{
    if(head==NULL) return 0;
    return 1+ count_recursive(head->next);
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
    InsertAtEnd(10);
    InsertAtEnd(20);
    InsertAtEnd(30);
    InsertAtEnd(40);
    InsertAtEnd(50);
    InsertAtEnd(60);
    InsertAtEnd(70);
    InsertAtEnd(80);
    InsertAtEnd(90);
    InsertAtEnd(100);
    display();
    printf("\n");
    printf("%d\n",count_iterative());
    printf("%d",count_recursive(head));
    
}