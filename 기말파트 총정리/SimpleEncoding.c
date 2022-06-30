#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int solution(int* A, int n)
{
	int max = 0;
	int res = 1;
	int i, j;

	for (i = 0; i < n; i++) {
		res = 1;
		for (j = 0; j < n; j++)
			if (i == j)
				res *= A[i] + 1;
			else
				res *= A[j];
		if (max < res)
			max = res;
	}
	return max;
}
int main()
{
	int n;
	int i;
	int* A;

	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	printf("%d\n", solution(A, n));
}