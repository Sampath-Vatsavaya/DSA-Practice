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
int findloop(struct node *head)
{
    struct node *slow=head,*fast=head->next;
    if(head==NULL) return 0;
    while(slow!=fast)
    {
        if(fast==NULL || fast->next==NULL) return 0;
        slow=slow->next;
        fast=fast->next->next;
    }
    return 1;
}
int main()
{
    InsertAtEnd(10);
    InsertAtEnd(20);
    InsertAtEnd(30);
    InsertAtEnd(40);
    InsertAtEnd(50);
    InsertAtEnd(60);
    struct node *temp =head->next->next;//30
    struct node *last =temp->next->next->next;//60
    last->next=temp;
    printf("%d",findloop(head));
   
}