#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
void insert();
void delete();
void display();
int front = -1, rear = -1;
int queue[maxsize];
void main()
{
    int choice;
    while (1) //Driver section
    {
        printf("\n\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice\n");
        }
    }
}
// function to insert an element in a queue
void insert()
{
    int item;
    printf("\nEnter the element : ");
    scanf("%d", &item);
    if (rear == maxsize - 1)// condition to check queue is full
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if (front == -1 && rear == -1)// condition to check queue is empty
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nValue inserted ");
}
// function to delete the element from the queue
void delete()
{
    int item;
    if (front == -1 || front > rear) // condition to check queue is empty
    {
        printf("\nUNDERFLOW");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        printf("\nvalue deleted :%d", item);
    }
}
// function to display the elements of a queue
void display()
{
    int i;
    if (rear == -1)
    {
        printf("\nEmpty queue");
    }
    else
    {
        printf("\nprinting values in queue");
        for (i = front; i <= rear; i++)
        {
            printf("\n%d", queue[i]);
        }
    }
}