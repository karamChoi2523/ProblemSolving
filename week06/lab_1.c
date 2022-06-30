#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n,i;
    int *A;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);

    srand(time(NULL));
    //seed : srand(303);

    for(i=0;i<n;i++)
        A[i] = rand()%1000; //0~999

    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
}