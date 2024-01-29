#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int result = 0;

    if (strcmp(argv[1], "add") == 0)
    {
        result = atoi(argv[2]) + atoi(argv[3]);
    }
    else if (strcmp(argv[1], "sub") == 0)
    {
        result = atoi(argv[2]) - atoi(argv[3]);
    }
    else if (strcmp(argv[1], "mul") == 0)
    {
        result = atoi(argv[2]) * atoi(argv[3]);
    }
    else if (strcmp(argv[1], "div") == 0)
    {
        result = atoi(argv[2]) / atoi(argv[3]);
    }
    printf("result: %d", result);
    return 0;
}
