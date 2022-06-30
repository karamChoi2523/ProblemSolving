#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search_binary(list, low, high)
{
    int middle;

    while(low<=high){
        middle = (low+high)/2;
        if(key == list[middle])
            return middle;
        else if(key > list[middle])
            low = middle+1;
        else
            high = middle-1;
    }
}