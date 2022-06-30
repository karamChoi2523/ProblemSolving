#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *A, int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
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

    bubble_sort(A,n);
    //정렬 후
    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
}