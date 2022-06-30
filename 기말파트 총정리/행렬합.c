#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readMatrix(int** a, int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    return;
}
void matrixAdd(int** a, int** b, int** x, int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            x[i][j] = a[i][j] + b[i][j];

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
int main()
{
    int** A, ** B, ** X;
    int r, c;
    int i;

    scanf("%d %d", &r, &c);

    A = (int**)malloc(sizeof(int*) * r);
    B = (int**)malloc(sizeof(int*) * r);
    X = (int**)malloc(sizeof(int*) * r);

    for (i = 0; i < r; i++) {
        A[i] = (int*)malloc(sizeof(int) * c);
        B[i] = (int*)malloc(sizeof(int) * c);
        X[i] = (int*)malloc(sizeof(int) * c);
    }

    printf("(%d x %d) 행렬 A 입력:\n", r, c);
    readMatrix(A, r, c);
    printf("(%d x %d) 행렬 B 입력:\n", r, c);
    readMatrix(B, r, c);
    printf("행렬합:\n");
    matrixAdd(A, B, X, r, c);
    printMatrix(X, r, c);

    for (i = 0; i < r; i++) {
        free(A[i]);
        free(B[i]);
        free(X[i]);
    }

    free(A);
    free(B);
    free(X);

    return 0;
}