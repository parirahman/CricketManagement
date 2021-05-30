//Parinda Rahman-1931804042-section 2 cse 225
#include "runarray.h"
#include <iostream>
#include <string>
int runarray::findTotal()
{
    int total=0;
    for(int i=0;i<10;i++)
    {
        total=total+runArray[i];
    }
    return total;


}
float runarray::findAverage()
{
    float average;
    float total=0;
    for(int i=0;i<10;i++)
    {
        total=total+runArray[i];
    }
    average=total/10.0;
    return average;

}
int runarray::findMax()
{
    int maxi = runArray[0];
    for (int i = 1; i < 10; i++)
    {
        if (runArray[i] > maxi)
            maxi = runArray[i];
    }
    return maxi;
}
int runarray::findMin()
{
    int mini = runArray[0];
    for (int i = 1; i < 10; i++)
    {
         mini= min(mini, runArray[i]);
    }
    return mini;


}

