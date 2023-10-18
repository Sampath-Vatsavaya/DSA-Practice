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
int search(int key)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key) return 1;
        temp=temp->next;
    }
    return 0;
}
int search_recursive(struct node* head,int key)
{
    if(head==NULL) return 0;
    if(head->data==key) return 1;
    search_recursive(head->next,key);
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
    int key=5;
    int key_recursive=11;
    int status= search(key);
    if(status) printf("\nThe key  is  present in the list");
    else printf("\nThe Key is not in the list");

    int status_recursive= search_recursive(head,key_recursive);
    if(status_recursive) printf("\nThe key  is  present in the list");
    else printf("\nThe Key is not in the list");

}