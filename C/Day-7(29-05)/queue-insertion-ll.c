#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;

void enqueue(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));

   temp->data=data;
   temp->next=NULL;
     if (front==NULL)
    {
        front=rear=temp;
        

    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    
   
    
}
void dequeue()
{ struct node *temp=front;
    if(front==NULL)
    {
        printf("Queue is empty");
        return;
    }
    else if (front==rear)
    {
        front=rear=NULL;
        free(temp);
    }
    else
    {
        front=front->next;
        temp->next=NULL;
        free(temp);
    }
    
}
void display()
{  struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("\n");
    dequeue();
    dequeue();
    display();
}