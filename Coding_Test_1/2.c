/**
Name: Md Rabiul Islam Shaon
ID: 181472541
**/

/* (2) Write a C program that declare an integer array length of one hundred (100) (do not initialize the array).
    Scan N (take input N from user) values from user into an array until user input is 0 (Zero). Print entire array
    each element separated by comma. Check Overflow, Use Function & Use Pointer. */

#include<stdio.h>
void Print_Array();
int main()
{
    int *ptr;
    int N, p;
    int array[100];

    ptr = &array[0];

    printf("Enter Array Size: ");
    scanf("%d",&N);

    if(N>100)
    {
        printf("Overflow\n");
        return 0;
    }
    else
    {
        for(p = 0; p<N; p++)
            scanf("%d",(ptr+p));
    }

    Print_Array(ptr, N);

    return 0;
}

void Print_Array(int *arr, int size)
{
    int p;
    printf("Array: \n");
    for(p = 0; p<size; p++)
        printf("%d\n", *(arr+p));
}
