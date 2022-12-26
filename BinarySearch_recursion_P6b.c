#include <stdio.h>
#include <stdlib.h>
int binary(int arr[], int x, int low, int high)
{
    if (low > high)
        return -1; // If element is not found
    else
    {
        int mid = (high + low) / 2;
        if (arr[mid] == x)
            return mid; // Element is found
        else if (arr[mid] > x)
            return binary(arr, x, low, mid - 1); // Function Calling itself
        else
            return binary(arr, x, mid + 1, high); 
    }
}
void main()
{
    int i, size;
    int arr[20], sr;
    printf("Enter the size : ");
    scanf("%d", &size);
    printf("\nEnter the elements : ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]); // Taking input from user
    printf("\nEnter the number to be searched : ");
    scanf("%d", &sr); // Number to be searched
    int result;
    result = binary(arr, sr, 0, size - 1); // Calling function
    if (result != -1)
        printf("\nSearched position =%d", result + 1);
    else
        printf("ELEMENT NOT FOUND");
}