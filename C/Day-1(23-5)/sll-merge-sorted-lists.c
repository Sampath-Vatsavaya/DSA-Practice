// C program to compare two lists , two lists are equal if length of the two list is equal and corresponding node data values are equal

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *headA=NULL,*headB=NULL;


void InsertAtBeginningA(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(headA==NULL)
    {
        headA=temp;
    }
    else
    {
        temp->next=headA;
        headA=temp;
    }
    /* Simpler logic:
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
    */
}
void InsertAtBeginningB(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(headB==NULL)
    {
        headB=temp;
    }
    else
    {
        temp->next=headB;
        headB=temp;
    }
    /* Simpler logic:
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
    */
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

struct node *merge(struct node *headA,struct node *headB)
{
    if(headA==NULL && headB==NULL) return NULL;
    else if (headA==NULL && headB!=NULL)
    {
        return headB;
    }
    else if (headA!=NULL && headB==NULL)
    {
        return headA;
    }
    if(headA->data<headB->data)
    {
        headA->next=merge(headA->next,headB);
        return headA;
    }
    else
    {
        headB->next=merge(headA,headB->next);
        return headB;
    }
    return NULL;
    
}

int main()
{
    InsertAtBeginningA(50);
    InsertAtBeginningA(30);
    InsertAtBeginningA(10);

    InsertAtBeginningB(60);
    InsertAtBeginningB(40);
    InsertAtBeginningB(20);
    
    display(headA);
    printf("\n");
    display(headB);
    printf("\n");
    struct node *merged_head=merge(headA,headB);
    display(merged_head);
    
}