#include <stdio.h>
void towers(int num, char from_peg, char to_peg, char aux_peg)
{
    if (num == 1)
    {
        printf("Move disk 1 from peg %c to peg %c \n", from_peg, to_peg);
        return;
    }
    towers(num - 1, from_peg, aux_peg, to_peg); //Function calling itself
    printf("Move disk %d from peg %c to peg %c \n", num, from_peg, to_peg);
    towers(num - 1, aux_peg, to_peg, from_peg);
}
void main()
{
    int num;
    printf("Enter the number of disk : ");
    scanf("%d", &num); //Taking user input
    printf("\nThe required number of moves involved\n");
    towers(num, 'A', 'C', 'B'); //Initial caliing towers function 
}