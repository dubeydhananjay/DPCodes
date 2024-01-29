#include <stdio.h>
void callByRefEg(int* a, int* b)
{
    int temp = *a;
    *a = temp + *b;
    *b = temp - *b;
}
int main()
{
    int a = 10,b = 5;
    printf("Original val of a: %d and b: %d \n",a,b);
    callByRefEg(&a,&b);
    printf("Changed val of a: %d and b: %d \n",a,b);
    return 0;
}