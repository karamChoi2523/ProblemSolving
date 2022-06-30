#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(int* items, int n, int* picked, int m, int toPick)
{
	int i, lastIndex, picked_index;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			printf("%d", picked[i]);
		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1;

	for (i = 0; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1);
	}
}
int main()
{
	int items[4] = { 0,1,2,3 };
	int n;
	int* picked;

	scanf("%d", &n);

	picked = (int*)malloc(sizeof(int) * n);

	pick(items, 4, picked, n, n);
	free(picked);
	
	return 0;
}