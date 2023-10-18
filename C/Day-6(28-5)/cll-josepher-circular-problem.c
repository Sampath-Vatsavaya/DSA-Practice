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
int Jcircle(struct node *head,int key)
{
    struct node *temp=head,*x;
    int c;
    if(head==NULL) return -1;
    while(head->next!=head)
    {
        c=key;
        temp=head;
        while(c--)
        {
            x=temp;
            temp=temp->next;
        }
        x->next=temp->next;
        temp->next=NULL;
        head=x->next;
        free(temp);
    }
    return head->data;
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
    printf("%d",Jcircle(head,2));
   
}