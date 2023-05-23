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

int compare_iterative(struct node *headA,struct node *headB)
{
    struct node *tempA=headA,*tempB=headB;
    while(tempA!=NULL && tempB!=NULL)
    {
        if(tempA->data!=tempB->data)
        {
            return 0;
        }
        tempA=tempA->next;
        tempB=tempB->next;
    }
    if(tempA==NULL && tempB==NULL)
        return 1;
    return 0;
}
int compare_recursive(struct node *headA,struct node *headB)
{
    if(headA==NULL && headB==NULL) return 1;
    else if (headA==NULL || headB==NULL)
    {
        return 0;
    }
    else if (headA->data!=headB->data)
    {
        
     return 0;
    }
    
    return compare_recursive(headA->next,headB->next);
}
int main()
{
    InsertAtBeginningA(10);
    InsertAtBeginningA(20);
    InsertAtBeginningA(30);

    InsertAtBeginningB(10);
    InsertAtBeginningB(20);
    InsertAtBeginningB(30);
    display(headA);
    printf("\n");
    display(headB);
    printf("\n");
    printf("%d",compare_iterative(headA,headB));
    printf("\n");
    printf("%d",compare_recursive(headA,headB));
}