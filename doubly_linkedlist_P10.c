#include <stdio.h>
#include <stdlib.h>
struct node //Declaration of node
{
  struct node *prev;
  struct node *next;
  int data;
};
struct node *head;
void insertion_beginning(); //prototype declaration
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main()
{
  int choice = 0;
  while (choice != 9) //menu driven function 
  {
    printf("\nChoose one option from the following list ...");
    printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given  data\n7.Search\n8.Show\n9.Exit");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      insertion_beginning();
      break;
    case 2:
      insertion_last();
      break;
    case 3:
      insertion_specified();
      break;
    case 4:
      deletion_beginning();
      break;
    case 5:
      deletion_last();
      break;
    case 6:
      deletion_specified();
      break;
    case 7:
      search();
      break;
    case 8:
      display();
      break;
    case 9:
      exit(0);
      break;
    default:
      printf("Please enter valid choice..");
    }
  }
}

void insertion_beginning() //to insert node at the beginning
{
  struct node *ptr;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL)
  {
    printf("\nOVERFLOW");
  }
  else
  {
    printf("\nEnter Item value : ");
    scanf("%d", &item);

    if (head == NULL)
    {
      ptr->next = NULL;
      ptr->prev = NULL;
      ptr->data = item;
      head = ptr;
    }
    else
    {
      ptr->data = item;
      ptr->prev = NULL;
      ptr->next = head;
      head->prev = ptr;
      head = ptr;
    }
    printf("\nNode inserted");
  }
}

void insertion_last() //To insert node at the last
{
  struct node *ptr, *temp;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL)
  {
    printf("\nOVERFLOW");
  }
  else
  {
    printf("\nEnter value : ");
    scanf("%d", &item);
    ptr->data = item;
    if (head == NULL)
    {
      ptr->next = NULL;
      ptr->prev = NULL;
      head = ptr;
    }
    else
    {
      temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = ptr;
      ptr->prev = temp;
      ptr->next = NULL;
    }
  }
  printf("\nnode inserted");
}

void insertion_specified() // to insert node at given position
{
  struct node *ptr, *temp;
  int item, loc, i;
  ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL)
  {
    printf("\n OVERFLOW");
  }
  else
  {
    temp = head;
    printf("Enter the location : ");
    scanf("%d", &loc);
    for (i = 0; i < loc; i++)
    {
      temp = temp->next;
      if (temp == NULL)
      {
        printf("\n There are less than %d elements", loc);
        return;
      }
    }
    printf("Enter value : ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next = ptr;
    temp->next->prev = ptr;
    printf("\nnode inserted");
  }
}

void deletion_beginning() //To delete node from the beginning
{
  struct node *ptr;
  if (head == NULL)
  {
    printf("\n UNDERFLOW");
  }
  else if (head->next == NULL)
  {
    printf("\nnode deleted :%d", head->data);
    head = NULL;
    free(head);
  }
  else
  {
    printf("\nnode deleted : %d", head->data);
    ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
  }
}

void deletion_last() //To delete node from the last
{
  struct node *ptr;
  if (head == NULL)
  {
    printf("\n UNDERFLOW");
  }
  else if (head->next == NULL)
  {
    printf("\nnode deleted : %d", head->data);
    head = NULL;
    free(head);
  }
  else
  {
    ptr = head;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    printf("\nnode deleted : %d", ptr->data);
    ptr->prev->next = NULL;
    free(ptr);
  }
}

void deletion_specified() //To delete node from the specified location
{
  struct node *ptr, *temp;
  int val;
  printf("\n Enter the data after which the node is to be deleted : ");
  scanf("%d", &val);
  ptr = head;
  while (ptr->data != val)
    ptr = ptr->next;
  if (ptr->next == NULL)
  {
    printf("\nCan't delete");
  }
  else if (ptr->next->next == NULL)
  {
    printf("\nnode deleted :%d", ptr->next->data);
    ptr->next = NULL;
  }
  else
  {
    printf("\nnode deleted :%d", ptr->next->data);
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
  }
}

void display() //To display elements in the linked list 
{
  struct node *ptr;
  printf("\n printing values...\n");
  ptr = head;
  while (ptr != NULL)
  {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

void search() //search an element in linked list
{
  struct node *ptr;
  int item, i = 0, flag;
  ptr = head;
  if (ptr == NULL)
  {
    printf("\nEmpty List");
  }
  else
  {
    printf("\nEnter item which you want to search : ");
    scanf("%d", &item);
    while (ptr != NULL)
    {
      if (ptr->data == item)
      {
        printf("\nitem found at location %d ", i + 1);
        flag = 0;
        break;
      }
      else
      {
        flag = 1;
      }
      i++;
      ptr = ptr->next;
    }
    if (flag == 1)
    {
      printf("\nItem not found");
    }
  }
}