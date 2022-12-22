#include <stdio.h>
#include <stdlib.h>
void push(); // Prototype Declaration
void pop();
void display();

struct node // Initialization of Structure
{
    int val;
    struct node *next; // Top
};
struct node *head;

void push() // function to push value into stack
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Not able to push the element\n");
    }
    else
    {
        printf("Enter the value\n");
        scanf("%d", &val);
        if (head == NULL)
        {
            ptr->val = val;   // pushing value
            ptr->next = NULL; // set next to null
            head = ptr;       // equating head to null
        }
        else
        {
            ptr->val = val;   // pushing value
            ptr->next = head; // set node to address of previous value
            head = ptr;
        }
        printf("Item pushed\n");
    }
}

void pop()
{
    int item;
    struct node *ptr; // temporary array
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped %d\n", item);
    }
}

void display() // Function to display element
{
    struct node *ptr; // temporary
    ptr = head;
    if (ptr == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Printing stack element: \n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->val); // Display Element
            printf("\n");
            ptr = ptr->next;
        } // While closed
    }     // else closed
} // function closed

int main()
{
    int choice;
    while (1) // Infinite loop till termination
    {
        printf("Select the operation\n");
        printf(" 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
