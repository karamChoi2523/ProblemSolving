#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//int cnt = 0;

int pick(int* item, int n, int* picked, int m, int toPick, int money, int current_money)
{
	int i, lastIndex, smallest;
	int ret = 0;

	lastIndex = m - toPick - 1;

	if (current_money == money) {
		return 1;
		//cnt++;
		/*for (i = 0; i <= lastIndex; i++) {
			printf("%d ", item[picked[i]]);
		}*/
		//printf("\n");
	}

	if (current_money > money || toPick == 0)
		return 0;

	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;	//item[i]
		ret += pick(item, n, picked, m, toPick - 1, money, current_money + item[i]);
	}
	return ret;
}
int main()
{
	int item[] = { 10,50,100 };
	int money;
	int* picked;
	int n;

	scanf("%d", &money);
	n = money / item[0];
	picked = (int*)malloc(sizeof(int) * n);
	printf("%d\n", pick(item, 3, picked, n, n, money, 0));

	//printf("%d\n", cnt);
	return 0;
}