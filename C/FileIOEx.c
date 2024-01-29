#include <stdio.h>
int main()
{
    FILE *ptr = NULL;
    char str[64] = "This is an example text file";
    ptr = fopen("myfile.txt", "a");
    // fscanf(ptr, "%s", str);
    // printf("example file:\n%s", str);
    fprintf(ptr, "%s", str);
    fclose(ptr);
    return 0;
}