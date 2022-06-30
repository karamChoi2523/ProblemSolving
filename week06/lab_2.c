#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *A, int n)
{
    int i,j,temp,max_idx;

    for(i=0;i<n-1;i++){
        max_idx = 0;
        for(j=0;j<n-i;j++)
            if(A[max_idx] < A[j])
                max_idx = j;

        temp = A[max_idx];
        A[max_idx] = A[n-i-1];  //가장 오른쪽으로 보냄
        A[n-i-1] = temp;
    }
}
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

    selection_sort(A,n);
    //정렬 후
    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
}