#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int solution(int a, int b, int check)
{
	if (check + a % 10 + b % 10 >= 10)
		return 1 + solution(a / 10, b / 10, 1);
	else if (a == 0 && b == 0)
		return 0;
	else
		return solution(a / 10, b / 10, 0);
}
int main()
{
	int a, b;
	int carry;
	
	scanf("%d %d", &a, &b);
	carry = solution(a, b, 0);

	printf("%d\n", carry);
}