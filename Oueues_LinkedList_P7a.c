#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
void enqueue(int x) //To add element in the queue
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node)); 
    if (ptr == NULL) //To check if ptr is created
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        ptr->data = x;
        if (front == NULL) //Queue is empty 
        {
            front = rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void delete() //To delete element from the queue
{
    int item;
    struct node *ptr;
    if (front == NULL) //Queue is empty
    {
        printf("UNDERFLOW\n");
        return;
    }
    else
    {
        item = front->data;
        ptr = front;
        front = front->next;
        free(ptr);
        printf("Item removed %d", item);
    }
}
void display() //To display elements present in queue
{
    struct node *ptr;

    if (front == NULL)
    {
        printf("Queue EMPTY \n");
        return;
    }
    else
    {
        ptr = front;
        printf("elments in queue:\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}
int main()
{
    int choice;
    do //Menu driven function
    {
        printf("\n 1.Enqueue\n 2.Dequeue\n 3.DISPLAY\n 4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int n;
            printf("Enter the element:");
            scanf("%d", &n);
            enqueue(n);
            break;
        }
        case 2:
        {
            delete ();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (1);
    return 0;
}
