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

struct node *merge_at_end_of_shortest_list(struct node *headA,struct node *headB)
{
    if(headA==NULL && headB==NULL) return NULL;
    if(headA!=NULL && headB==NULL) return headA;
    if(headA==NULL && headB!=NULL) return headB;
    struct node *tempA=headA,*tempB=headB;
    while(tempA->next!=NULL && tempB->next!=NULL)
    {
        tempA=tempA->next;
        tempB=tempB->next;
    }
    if(tempA->next==NULL)
    {
        tempA->next=headB;
        return headA;
    }
    if(tempB->next==NULL)
    {
        tempB->next=headA;
        return headB;
    }
    return NULL;
}


int main()
{
    InsertAtBeginningA(30);
    InsertAtBeginningA(20);
    InsertAtBeginningA(10);
    InsertAtBeginningB(70);
    InsertAtBeginningB(60);
    InsertAtBeginningB(50);
    InsertAtBeginningB(40);
    
    display(headA);
    printf("\n");
    display(headB);
    printf("\n");
    struct node *final_head=merge_at_end_of_shortest_list(headA,headB);
    printf("\n");
    display(final_head);
    
    
}