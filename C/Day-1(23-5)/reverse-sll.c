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
void reverse()
{
    struct node *cur=head,*fwd,*newlist=NULL;
    while(cur!=NULL)
    {
        fwd=cur->next;
        cur->next=newlist;
        newlist=cur;
        cur=fwd;
    }
    head=newlist;
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
    reverse();
    display();
}