#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//c에서 1이 몇개인지
int solution(int c)
{
	if (c == 1)
		return 1;
	else
		return 1 + solution(c / 10);
}
//찾은 수가 1로만 구성된 수가 맞는지
int isItAll(int c)
{
	while (c != 0) {
		if (c % 10 != 1)
			return 0;
		else
			c /= 10;
	}
	return 1;
}
//b = _n이니까 c를 찾아야 함(함수 호출)
void findC(int a, int n)
{
	int i = 0;

	while (!isItAll(a * (i * 10 + n))) {
		i++;
	}
	printf("%d\n", solution(a * (i * 10 + n)));
}
//a랑 곱해서 일의 자리수가 1인 수 찾기
void findB(int a)
{
	int i;

	for (i = 1; i < 10; i++) {
		if ((a * i) % 10 == 1)
			findC(a, i);
	}

}
int main()
{
	int a;

	scanf("%d", &a);

	findB(a);
}