#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readMatrix(int a[][3], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
}
void matrixAdd(int a[][3], int b[][3], int x[][3], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            x[i][j] = a[i][j] + b[i][j];

}
void printMatrix(int a[][3], int n)
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
int main()
{
    int A[3][3], B[3][3], x[3][3];
    readMatrix(A, 3);
    readMatrix(B, 3);
    printMatrix(A, 3);
    printMatrix(B, 3);

    matrixAdd(A, B, x, 3);
    printMatrix(x, 3);
    return 0;
}