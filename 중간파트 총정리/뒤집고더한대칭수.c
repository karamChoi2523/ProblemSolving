#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse(int n)
{
	int i;
	int result = 0;

	while (n != 0) {
		result = result * 10 + n % 10;
		n /= 10;
	}
	return result;
}
int main()
{
	int n;
	int cnt = 0;
	int flag = 0;

	scanf("%d", &n);

	while (n != reverse(n)) {
		if (n < 0) {
			flag = 1;
			break;
		}
		n = n + reverse(n);
		cnt++;
		if (cnt > 1000) {
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("%d %d\n", cnt, n);
	else
		printf("NaN\n");
}