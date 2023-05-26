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
int isPalindrome()
{   struct node *th=head,*tt=tail;
    if(head==NULL) return 1;
    while(th!=tt)
    {
        if(th->next==tt && th->data==tt->data) return 1;
        if(th->data != tt->data) return 0;
        th=th->next;
        tt=tt->prev;
    }
    return 1;
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
    InsertAtEnd(30);
    InsertAtEnd(20);
    InsertAtEnd(10);
    display();
    if(isPalindrome()) printf("\nIt is a Palindrome");
    else
    {
        printf("\nIt is not a Palindrome");
    }
}