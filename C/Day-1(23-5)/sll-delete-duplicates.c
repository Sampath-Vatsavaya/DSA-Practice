// C program to delete duplicate elements in an Sorted List like 1 2 2 3 3 4 5
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

}*head=NULL;


void InsertIntoSortedList(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node)),*x=head;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else if (head->data>data)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        while(x->next!=NULL)
        {
            if(x->next->data<data)
            {
                x=x->next;
            }
            else{
                break;
            }
        }
        temp->next=x->next;
        x->next=temp;
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
void deleteduplicates()
{
    struct node *temp=head,*x;
    if(head==NULL) return;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            x=temp->next;
            temp->next=x->next;
            x->next= NULL;
            free(x);
        }
        else
        {
            temp=temp->next;
        }
    }
}
int main()
{
   InsertIntoSortedList(1);
   InsertIntoSortedList(3);
   InsertIntoSortedList(2);
   InsertIntoSortedList(2);
   InsertIntoSortedList(4);
   InsertIntoSortedList(5);
   InsertIntoSortedList(3);

    display();
    printf("\n");
    deleteduplicates();
    display();
    
}