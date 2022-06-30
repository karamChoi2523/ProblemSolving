#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(char* items[], int n, int picked[], int m, int toPick)
{
	int i, lastIndex, smallest, picked_index;

	if (toPick == 0) {
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			printf("%s ", items[picked_index]);
		}
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
	char* items[] = {"공유","김수현","송중기","지성","현빈"};
	int n = 5;
	int picked[3];

	pick(items, n, picked, 3,3);
}