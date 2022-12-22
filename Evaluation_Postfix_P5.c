
#include <stdio.h>
int stack[20];
int top = -1;

void push(int x) //push elements into stack
{
    stack[++top] = x;
}

int pop() //to remove/pop elements from stack
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1, n2, n3, num;
    printf("Enter the expression :: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;
            push(num);//calling push function
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*e) //to calculate the expression by operator
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }//while closed
    printf("\nThe result of expression %s  =  %d\n\n", exp, pop());
    return 0;
}
