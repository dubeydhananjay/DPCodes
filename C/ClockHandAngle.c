#include <stdio.h>
#include <math.h>
// hour hand hour angle -> 360/12 ->30 degree per hour
// hour hand min angle -> 30/60 -> 0.5 degree per min
// 360 degree when hand covers the whole circle, 12 means number of hours( 1 - 12), 60 means 60 minutes per hour
// Total hour hand angle => (30 * x) + (0.5 * y) => x means hour and y means minute => HHA
// minute hand minute angle -> 360/60 -> 6 degree per minute => (6 * y) => MHA
// Angle between hour and minute hands => |HHA - MHA| => A degree
// if A degree > 180 then the angle between hour and minute hand is 360 - A

float hourHandAngle(int x, int y)
{
    return ((30 * x) + (0.5f * y));
}

float minuteHandAngle(int y)
{
    return (6 * y);
}
int main()
{
    int x, y;
    printf("Enter hour:\n");
    scanf("%d", &x);
    printf("Enter minute:\n");
    scanf("%d", &y);
    float angle = fabs(hourHandAngle(x, y) - minuteHandAngle(y));
    if (angle > 180)
        angle = 360 - angle;
    printf("The angle between hour hand and minute hand: %.2f",angle);
    return 0;
}
