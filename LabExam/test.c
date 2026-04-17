#include <stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct 
{
    int x, y;
    int set;
}Point;

int dist(Point a, Point b)
{
    return abs(a.x-b.x) + abs(a.y-b.y);
}

int brute(Point* arr1, int size)
{
    for(int i =0 ; i< size; i++)
    {
        for(int j = i+1; j<size; j++)
        {
            if(arr1[i].set != arr2[i].set)
            {
                
            }
        }
    }
}
