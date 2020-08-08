/**
Name: Md Rabiul Islam Shaon
ID: 181472541
**/

/* (4) Update Kth (take input K from user) index with the value X (take input X from user).
    And print the whole array. Access the array using pointer. */

#include<stdio.h>
int main()
{
    int *p;
    int i, X, K;
    int array[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;

    p = &array[0];

    printf("Before Update: ");
    for(i=0; i<size; i++)
        printf("%d ", *(p+i));

    printf("\nEnter Position: ");
    scanf("%d",&K);

    printf("Enter Value: ");
    scanf("%d",&X);


    for(i=K-1; i<size; i++)
    {
        *(p+i)=X;
        break;
    }

    printf("After Update: ");
    for(i=0; i<size; i++)
        printf("%d ", *(p+i));

    return 0;
}
