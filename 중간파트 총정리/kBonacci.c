#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int kBonacci(int k, int n)
{

	int i;
	int sum = 0;

	if (n>=1 && n <= k)
		return 1;
	else {
		for (i = 1; i <= k; i++)
			sum += kBonacci(k, n - i);
	}
	return sum;
}
int main()
{
	//n¹øÂ° °ª
	int k, n;
	int res;
	scanf("%d %d", &k, &n);

	res = kBonacci(k, n);

	printf("%d\n", res);
}