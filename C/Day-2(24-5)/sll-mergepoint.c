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
int count(struct node* head)
{
    if(head==NULL) return 0;
    return 1+ count(head->next);
}
int mergepoint(struct node *headA,struct node *headB)
{
    struct node *temp1=headA,*temp2=headB;
    int c1=count(headA),c2=count(headB);
    while(c1>c2)
    {
        temp1=temp1->next;
        c1--;
    }
    while(c1<c2)
    {
        temp2=temp2->next;
    }
    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1==NULL) return -1;
    return temp1->data;
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
    printf("\n");
    struct node *temp1=(struct node*)malloc(sizeof(struct node));
    struct node *temp2=(struct node*)malloc(sizeof(struct node));
    temp1->data=1;
    temp1->next=NULL;
    temp2->data=3;
    temp2->next= head->next->next->next->next;
    temp1->next=temp2;
    head2=temp1;
    display(head2);
    printf("\n Merging point: %d",mergepoint(head,head2));

}