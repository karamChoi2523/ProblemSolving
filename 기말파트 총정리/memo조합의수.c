#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comb(int** F, int n, int r)
{
	if (r == 0 || r == n) {
		F[n][r] = 1;
		return 1;
	}
	else {
		if (F[n - 1][r - 1] == 0)
			F[n - 1][r - 1] = comb(F, n - 1, r - 1);
		if (F[n - 1][r] == 0)
			F[n - 1][r] = comb(F, n - 1, r);

		F[n][r] = F[n - 1][r - 1] + F[n - 1][r];
		return F[n][r];
	}
}

int main()
{
	int C;
	int** F;
	int i, j;
	int n, r;

	scanf("%d %d", &n, &r);

	F = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i < (n + 1); i++)
		F[i] = (int*)malloc(sizeof(int) * (r + 1));

	for (i = 0; i < n; i++)
		for (j = 0; j < (r + 1); j++)
			F[i][j] = 0;

	C = comb(F, n, r);
	printf("%d\n", C);

	for (i = 0; i < n; i++)
		free(F[i]);
	free(F);
	return 0;
}