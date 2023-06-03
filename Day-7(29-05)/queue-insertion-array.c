#include<stdio.h>

#define MAX 100

int queue[MAX];
int front=0,rear=-1;
void enqueue(int data)
{
    if(rear== (MAX-1) )
    
    {
        printf("Queue is full");
         return;
    }

        queue[++rear] =data;
    
}
void dequeue()
{
    if(front>rear) 
    {
        printf("queue is empty");
    }
    else
    {
        front++;
        if(front>rear)
        {
            front=0;
            rear=-1;
        }
    }
}
void display()
{
    for(int i=front;i<rear;i++)
    {
        printf("%d ",queue[i]);
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