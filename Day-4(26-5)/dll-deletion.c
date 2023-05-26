#include<stdio.h>
#include<stdlib.h>
struct node
{   struct node *prev;
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;
struct node *create(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void DeleteAtBeginning()
{
    struct node *temp=head;
    if(head==NULL) return;
    else if (head==tail)
    {
        head=tail=NULL;
        free(temp);
    }
    else{
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        free(temp);
    }
    
}
void DeleteAtEnd()
{
    struct node *temp=tail;//*temp=head;
    if(head==NULL) return;
    else if (head==tail)
    {
        head=tail=NULL;
        free(temp);
    }
    else
    {  
        tail=tail->prev;
        temp->prev=NULL;
        tail->next=NULL;
        free(temp);
        
        
        
       /* while(temp->next!=NULL)
        {   tail=temp;
            temp=temp->next;
        }
        tail->next=NULL;
        temp->prev=NULL;
        free(temp);*/
    }
    
}
void InsertAtEnd(int data)
{
    struct node *temp=create(data);
    if(head==NULL) head=tail=temp;
    else{
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}
void display()
{
    if(head==NULL) return;
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
    display();
    printf("\n");
    DeleteAtBeginning();
    DeleteAtBeginning();
    display();
    printf("\n");
    DeleteAtEnd();
    DeleteAtEnd();
    display();
}