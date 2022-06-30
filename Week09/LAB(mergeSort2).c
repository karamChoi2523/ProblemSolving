#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A[p...q], A[q+1....r]까지를 merge
void merge(int *A, int p, int q, int r, int* B)
{
    int i, j, t;
    
    i=p;
    j = q+1;
    t = 0;  //B에 채워질 위치

    //둘 중 하나라도 벗어나면 탈출(&&)
    while(i<=q && j<=r){
        if(A[i] < A[j])
            B[t++] = A[i++];
        else
            B[t++] = A[j++];
    }

    //copy...(남은 걸 복사) >> 왼쪽오른쪽 중 어디가 남았는지 확인
    if(i>q) //오른쪽 copy
        for(;j<=r;j++)
            B[t++] = A[j];
    else   //왼쪽 copy
        for(;i<=q;i++,t++)
            B[t] = A[i];

    //B에 저장된 최종적으로 정렬된 배열을 A에 copy
    for(i=p,t=0;i<=r;i++, t++)
        A[i] = B[t];
}
void mergeSort(int *A, int p, int r, int* B)
{
    int q;  //가운데

    if(p<r){
        q = (p+r)/2;
        mergeSort(A, p, q, B);
        mergeSort(A, q+1, r, B);
        merge(A, p, q, r, B);
    }
}
int main()
{
    int *A;
    int *B;
    int n;  //array크기
    int i;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);
    B = (int*)malloc(sizeof(int)*n);

    srand(time(NULL));
    for(i=0;i<n;i++)
        A[i] = rand()%1000;

    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");
    mergeSort(A, 0, n-1, B);

    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    free(B);
    return 0;
}