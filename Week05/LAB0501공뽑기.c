#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(char* items, int n, int picked[], int m, int toPick)
{
	int i;
	int smallest;
	int lastIndex;

	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%c ", items[picked[i]]);
		printf("\n");
		return;
	}
	
	lastIndex = m - toPick - 1;

	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1);
	}
}
int main()
{
	char items[] = "ABCDEFG";
	int items_size = 7;
	int picked[3];

	pick(items, items_size, picked, 3, 3);
}