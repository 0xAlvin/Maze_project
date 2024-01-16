#include "include/maze.h"

/**
 * attillery - Creates a array of filepaths to the images of the attillery.
 * @selectedAttillery: value that determines the path ,The selected attillery.
 * return: A pointer to the dynamically allocated array of vector2D.
*/
char* attillery(int selectedAttillery){
    //create a array of attillery
    char* attillery[4] = {"pics/playerhands.png","pics/firstg.png","pics/secondg.png","pics/thirdg.png"};
    int attilleryCount = 0;

    //select attillery
    switch (selectedAttillery)
    {
    case 1:
        attilleryCount = 1;
        return attillery[attilleryCount];
    case 2:
        attilleryCount = 2;
        return attillery[attilleryCount];
    case 3: 
        attilleryCount = 3;
        return attillery[attilleryCount];
    default:
        return attillery[attilleryCount];
    }
}