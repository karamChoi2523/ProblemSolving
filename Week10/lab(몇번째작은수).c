#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *A, int p, int r)
{
    int i,j;
    i = p-1;
    int t;

    for(j=p;j<r;j++){
        if(A[j] < A[r]){
            i++;
            //swap A[j] A[i]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;   //pivot의 인데스값 return
}
//A[p.....r]
//q는 subarray에서 q-p+1번째
int selection(int *A, int p, int r, int i)
{
    int q;
    int rank = q-p+1;

    q = partition(A, p, r);

    if(i==rank) //찾은 경우
        return A[q];
    else if(A <rank)    //왼쪽에 대해 재귀호출
        return selection(A, p, q-1, i);
    else    //오른쪽에 대해 재귀호출
        return selection(A, q+1, r, i-rank);   //i-rank : 7번째를 원할 때 오른쪽 배열의 3번째인 그런 경우
}
int main()
{
    int *A;
    int n, i, rank;

    scanf("%d", &n);
    scanf("%d", &rank);
    A = (int*)malloc(sizeof(int)*n);

    srand(time(NULL));
    for(i=0;i<n;i++)
        A[i] = rand()%1000;
    
    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("%d\n", selection(A, 0, n-1, rank));

    free(A);
    return 0;
}