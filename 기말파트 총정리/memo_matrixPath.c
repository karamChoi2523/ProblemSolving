#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int matrixPath(int** m, int** M, int** M2, int i, int j)
//{
//	if (i == 0 && j == 0) {
//		M2[i][j] = 1;
//		return m[i][j];
//	}
//	else if (i == 0) {
//		if (M2[i][j - 1] == 0) {
//			M2[i][j - 1] = 1;
//			M[i][j - 1] = matrixPath(m, M, M2, i, j - 1);
//		}
//
//		return M[i][j - 1] + m[i][j];
//	}
//	else if (j == 0) {
//		if (M2[i - 1][j] == 0) {
//			M2[i - 1][j] = 1;
//			M[i - 1][j] = matrixPath(m, M, M2, i - 1, j);
//		}
//		return M[i - 1][j] + m[i][j];
//	}
//	else {
//		if (M[i][j - 1] == 0) {
//			M2[i][j - 1] = 1;
//			M[i][j - 1] = matrixPath(m, M, M2, i, j - 1);
//		}
//		if (M[i - 1][j] == 0) {
//			M2[i - 1][j] = 1;
//			M[i - 1][j] = matrixPath(m, M, M2, i - 1, j);
//		}
//
//		return ((M[i - 1][j] < M[i][j - 1]) ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
//	}
//}


//방법2
int matrixPath(int** m, int** M, int** M2, int i, int j)
{
	if (M2[i][j] != 0) return M[i][j];

	if (i == 0 && j == 0)
		M[i][j] = m[i][j];
	else if (i == 0)
		M[i][j] = matrixPath(m, M, M2, i, j - 1)+m[i][j];
	else if (j == 0)
		M[i][j] = matrixPath(m, M, M2, i - 1, j)+m[i][j];
	else {
		int a, b;
		
		a = matrixPath(m, M, M2, i, j - 1);
		b = matrixPath(m, M, M2, i - 1, j);

		M[i][j] = (a < b) ? a : b + m[i][j];
	}

	M2[i][j] = 1;
	return M[i][j];
}

int main()
{
	int** m;
	int** M;	//계산결과 저장
	int** M2;	//계산여부 저장

	int r, c;
	int i, j;

	r = c = 4;

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	M2 = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
		M2[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;	//초기화
			M2[i][j] = 0;	//계산 여부
		}


	printf("%d\n", matrixPath(m, M, M2, r - 1, c - 1));

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
	}
	free(m);
	free(M);
	return 0;
}