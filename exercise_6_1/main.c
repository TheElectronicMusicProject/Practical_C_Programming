#include <stdio.h>
#include <math.h>

int
main (int argc, char ** argv)
{
    char    line[100] = { 0 };
    double  point1_x = 0.0;
    double  point1_y = 0.0;
    double  point2_x = 0.0;
    double  point2_y = 0.0;
    double  distance = 0.0;
    double  tempx = 0.0;
    double  tempy = 0.0;

    printf("Inserire coordinate primo punto: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf %lf", &point1_x, &point1_y);
    
    printf("Inserire coordinate secondo punto: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf %lf", &point2_x, &point2_y);

    tempx = (point2_x - point1_x) * (point2_x - point1_x);
    tempy = (point2_y - point1_y) * (point2_y - point1_y);

    distance = sqrt(tempx + tempy);

    printf("The distance is %f\n", distance);
    
    return (0);
}