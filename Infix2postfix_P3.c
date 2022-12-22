#include<stdio.h>
#include<stdlib.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x; //Storing element in stack
}
char pop()
{
    if (top == -1)
        return -1;
    else
    {
        return stack[top--]; //Returning element at the top
    }
}

int priority(char x) //function to check the priority of the operator
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
}
int main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression: \n"); //Taking input from user
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e)) //Checking if value is alphabet or numeric
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
} //main closed
