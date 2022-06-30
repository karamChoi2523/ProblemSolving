#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ST 1
#define LE 2
#define UP 3

int matrixPath(int** m, int** M, int** M2, int** BP, int i, int j)
{
	if (i == 0 && j == 0) {
		M2[i][j] = 1;
		BP[i][j] = ST;
		return m[i][j];
	}
	else if (i == 0) {
		if (M2[i][j - 1] == 0) {
			M2[i][j - 1] = 1;
			M[i][j - 1] = matrixPath(m, M, M2, BP, i, j - 1);
		}
		BP[i][j] = LE;

		return M[i][j - 1] + m[i][j];
	}
	else if (j == 0) {
		if (M2[i - 1][j] == 0) {
			M2[i - 1][j] = 1;
			BP[i][j] = UP;
			M[i - 1][j] = matrixPath(m, M, M2, BP, i - 1, j);
		}

		return M[i - 1][j] + m[i][j];
	}
	else {
		if (M2[i][j - 1] == 0) {
			M2[i][j - 1] = 1;
			M[i][j - 1] = matrixPath(m, M, M2, BP, i, j - 1);
		}
		if (M2[i - 1][j] == 0) {
			M2[i - 1][j] = 1;
			M[i - 1][j] = matrixPath(m, M, M2, BP, i - 1, j);
		}

		if (M[i][j - 1] < M[i - 1][j])
			BP[i][j] = LE;
		else
			BP[i][j] = UP;

		return ((M[i - 1][j] < M[i][j - 1]) ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
	}
}
void print_path(int i, int j, int** BP)
{
	if (BP[i][j] == UP)
		print_path(i - 1, j, BP);
	if (BP[i][j] == LE)
		print_path(i, j - 1, BP);
	printf("<%d, %d> ", i, j);
}
int main()
{
	int** m;
	int** M;
	int** M2;
	int** BP;
	int r, c;
	int i, j;

	r = c = 4;

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	M2 = (int**)malloc(sizeof(int*) * r);
	BP = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
		M2[i] = (int*)malloc(sizeof(int) * c);
		BP[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
			M2[i][j] = 0;
		}


	printf("%d\n", matrixPath(m, M, M2, BP, r - 1, c - 1));

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d ", BP[i][j]);
		printf("\n");
	}

	print_path(3, 3, BP);
	printf("\n");

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
		free(M2[i]);
		free(BP[i]);
	}
	free(m);
	free(M);
	free(M2);
	free(BP);
	return 0;
}