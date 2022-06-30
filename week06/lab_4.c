#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *A, int n)
{
    int i,j,k,temp;

    for(i=1;i<n;i++){
        //insert A[i]
        for(j=0;j<i;j++){
            if(A[i] < A[j])
                break;  //앞에서부터 오다가 나보다 키 큰 애를 보면 멈춤
        }
        //j <- position for A[i]
        temp = A[i];
        for(k=i;k>j;k--)    //뒤쪽 먼저 땡기기
            A[k] = A[k-1];  //A[i] = A[i-1] ~ A[j+1] = A[j]까지 수행됨.
        A[j] = temp;
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

    insertion_sort(A,n);
    //정렬 후
    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
}