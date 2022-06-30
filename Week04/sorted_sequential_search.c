#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int list[9] = {1,3,5,6,7,9,11,20,30};

int sorted_seq_search(int key, int low, int high)
{
    int i;

    for(i=low;i<=high;i++){
        if(list[i] > key)
            return -1;
        if(list[i] == key)
            return i;
    }
}

int main()
{
    int key, size;
    scanf("%d", &key);

    printf("%d\n", sorted_seq_search(key, 0, 8));
}