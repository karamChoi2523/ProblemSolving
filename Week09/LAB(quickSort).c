#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//pivot을 return
int partition(int *A, int p, int r)
{
    int i,j;
    int t;  //swap을 위한 변수

    j=p;    //실질적으로 loop를 도는 애
    i=p-1;  //pivot보다 작은 애를 찾기 전임(오른쪽 boundary)

    for(;j<r;j++){
        if(A[j] < A[r]){
            i++;
            //swap A[i] A[j]
            t = A[i];
            A[i]= A[j];
            A[j] = t;
        }
    }
    i++;
    //swap A[i] A[r](pivot을 가운데로)
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}
void quickSort(int *A, int p, int r)
{
    int q;
    //정렬해야 하는 게 0개나 1개이면 그냥 return
    if(p<r){
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
        //pivot은 정렬에 포함되지 않는다
    }
}
int main()
{
    int *A;
    int n;  //array크기
    int i;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);

    srand(time(NULL));
    for(i=0;i<n;i++)
        A[i] = rand()%1000;

    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");
    quickSort(A, 0, n-1);

    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    return 0;
}