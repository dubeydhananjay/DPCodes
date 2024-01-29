#include <stdio.h>
#include <math.h>

float eDistance(int x1, int y1, int x2, int y2) 
{
    float dist = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
    return dist;
}

float areaOfCircle(int x1, int y1, int x2, int y2, float (*ptr)(int x1, int y1, int x2, int y2)) 
{
    float rad = ptr(x1,y1,x2,y2);
    float area = 3.14 * rad * rad;
    return area;
}

int main()
{
    float (*ptr)(int x1,int y1, int x2, int y2);
    ptr = eDistance;
    int x1,x2,y1,y2;
    printf("Enter x1:\n");
    scanf("%d",&x1);
    printf("Enter y1:\n");
    scanf("%d",&y1);
    printf("Enter x2:\n");
    scanf("%d",&x2);
    printf("Enter y2:\n");
    scanf("%d",&y2);
    printf("Area of circle: %f\n",areaOfCircle(x1,y1,x2,y2,ptr));
    return 0;
}
