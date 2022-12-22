#include<stdio.h>
#include<stdlib.h>
#define size 4

int top = -1;
int arr[size]; //Array Declaration
void push(); //Prototype Declaration
void pop();
void display();
int main()
{
    int choice;
    while (1) //Infinite loop till termination
    {
        printf("\nSelect the operation\n");
        printf("-----------------------------\n");
        printf(" 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(); //To insert element in stack
            break;
        case 2:
            pop(); //To pop element from stack
            break;
        case 3:
            display(); //To display elements in stack
            break;
        case 4:
            exit(0); //To exit from the program
        default:
            printf("Invalid choice\n");
        }
    }
} //main closed

void push()
{
    int n;
    if (top == size - 1) //Checking if stack is full
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the element to be inserted\n");
        scanf("%d", &n);
        top++;
        arr[top] = n;
    }
}

void pop()
{
    if (top == -1) //Checking if stack is empty
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Removed element is %d\n", arr[top]);
        top--;
    }
}

void display()
{
    if (top == -1) //Checking if stack is empty
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Elements in the stack are:\n");
        for (int i = top; i >= 0; i--) //loop from top to 0
        {
            printf("%d\n", arr[i]); //Displaying elements in stack
        }
        printf("\n");
    }
}



