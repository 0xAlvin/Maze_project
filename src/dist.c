#include"../include/maze.h"
/**
 * distance - calculate distance
 * @ax - x coordinate
 * @ay - y coordinate
 * @bx - x coordinate
 * @by - y coordinate
 * @angle - angle
 * Return: distance
*/
float distance(float ax, float ay, float bx, float by, float angle)
{
    printf("ax: %f, ay: %f, bx: %f, by: %f, angle: %f\n", ax, ay, bx, by, angle);
    return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}