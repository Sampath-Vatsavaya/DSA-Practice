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
int main()
{
   InsertIntoSortedList(10);
   InsertIntoSortedList(30);
   InsertIntoSortedList(60);
   InsertIntoSortedList(40);
   InsertIntoSortedList(20);
   InsertIntoSortedList(50);
   InsertIntoSortedList(100);
   InsertIntoSortedList(90);
   InsertIntoSortedList(80);
   InsertIntoSortedList(70);

    display();

    
}