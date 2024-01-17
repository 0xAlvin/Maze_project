#include"../include/maze.h"
/**
 * distanceBetweenPoints - distance between two points
 * @x1: x1
 * @y1: y1
 * @x2: x2
 * @y2: y2
 * Return: distance
*/
float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
    return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}