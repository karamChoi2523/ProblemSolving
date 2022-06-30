#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void readMatrix(int** a, int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    return;
}
void matrixMul(int** a, int** b, int** x, int r, int l, int c)
{
    int i, j, k;
    int sum = 0;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum = 0;
            for (k = 0; k < l; k++)
                sum += (a[i][k] * b[k][j]);
            x[i][j] = sum;
        }
    }
    return;

}
void printMatrix(int** a, int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%3d ", a[i][j]);
        printf("\n");
    }
}
void transposedMatrix(int** a, int r, int c)
{
    int** X;
    int i, j;

    X = (int**)malloc(sizeof(int*) * c);
    for (i = 0; i < c; i++)
        X[i] = (int*)malloc(sizeof(int) * r);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            X[j][i] = a[i][j];

    printMatrix(X, c, r);

    for (i = 0; i < c; i++)
        free(X[i]);

    free(X);
    return;
}

int main()
{
    int** A, ** C, ** X;
    int r1, r2, c1, c2;
    int i;

    printf("Enter 행렬 A의 행과 열의 개수: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter 행렬 C의 행과 열의 개수(C의 행은 %d이어야): ", c1);
    scanf("%d %d", &r2, &c2);

    A = (int**)malloc(sizeof(int*) * r1);
    C = (int**)malloc(sizeof(int*) * r2);
    X = (int**)malloc(sizeof(int*) * r1);

    for (i = 0; i < r1; i++) {
        A[i] = (int*)malloc(sizeof(int) * c1);
        X[i] = (int*)malloc(sizeof(int) * c2);
    }
    for (i = 0; i < r2; i++) {
        C[i] = (int*)malloc(sizeof(int) * c2);
    }

    printf("%d x %d 행렬 A 입력:\n", r1, c1);
    readMatrix(A, r1, c1);
    printf("\n");
    printf("%d x %d 행렬 C 입력:\n", r2, c2);
    readMatrix(C, r2, c2);
    printf("\n");

    printf("행렬곱:\n");
    matrixMul(A, C, X, r1, c1, c2);
    printMatrix(X, r1, c2);
    printf("\n");

    printf("전치행렬:\n");
    transposedMatrix(A, r1, c1);

    for (i = 0; i < r1; i++) {
        free(A[i]);
        free(X[i]);
    }
    for (i = 0; i < r2; i++)
        free(C[i]);

    free(A);
    free(C);
    free(X);

    return 0;
}