#include <stdio.h>
#include <stdlib.h>

void addEmployeeId()
{
    char *empId;
    int length;
    printf("Enter length of emp id:\n");
    scanf("%d",&length);
    empId = (char*)malloc((length + 1 )*sizeof(char));
    printf("Enter emp id:\n");
    scanf("%s",empId);
    printf("%s",*empId);
    printf("\n");
}
int main()
{
    addEmployeeId();
    return 0;
}