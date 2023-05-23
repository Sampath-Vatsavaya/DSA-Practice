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
void DeleteAtBeginning()
{
    struct node *temp;
    if(head==NULL) return;
    temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
}
void DeleteAtEnd()
{
  struct node *temp=head,*x;
  if(head==NULL) return;
  else if (head->next==NULL)
  {
     head=NULL;
     free(temp);
  }
  else
  {
    while(temp->next!=NULL)
    {
        x=temp;
        temp=temp->next;
    }
    x->next=NULL;
    free(temp);
  }
  
}

void DeleteAtPosition(int pos)
{
    struct node *temp=head,*x;
    if(head==NULL) return;
    else if (pos==1)
    {
        head=head->next;
        temp->next=NULL;
        free(temp);
    }
    else
    {
        while(--pos)
        {
            x=temp;
            temp=temp->next;
            if(temp==NULL && pos>1)
                return;
        }
        x->next=temp->next;
        temp->next=NULL;
        free(temp);
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
    DeleteAtBeginning();
    DeleteAtBeginning();
    display();
    printf("\n");
    DeleteAtEnd();
    DeleteAtEnd();
    display();
    printf("\n");
    DeleteAtPosition(3);
    DeleteAtPosition(5);
    display();
}