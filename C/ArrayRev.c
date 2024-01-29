#include <stdio.h>

void arrayRev(int *arr1)
{
    int count = 4;
    for (int i = 0; i < count/2; i++)
    {
        int temp = arr1[i];
        arr1[i] = arr1[count - i - 1];
        arr1[count - i - 1] = temp;
    }
}

void printArr(int arr2[])
{
    int count = 4;
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    printArr(arr);
    printf("after rev \n");
    arrayRev(arr);
    printArr(arr);
}