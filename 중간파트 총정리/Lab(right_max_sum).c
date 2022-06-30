#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int right_max_sum(int A[], int left, int right)
{
	int temp;
	int sum = 0;
	int sum_max = A[left];
	int i;

	for (i = left; i <= right; i++) {
		//sum = A[left]...A[i]
		sum = sum + A[i]; //start가 고정이니까!!(loop 필요x)
		if (sum_max < sum)
			sum_max = sum;
	}
	return sum_max;
	/*if (left >= right)
		return A[right];
	else {
		sum = A[left] + right_max_sum(A, left+1, right);
		if (sum > temp)
			temp = sum;
	}
	return temp;*/
}
int main() {
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	//int max = right_max_sum(A, 3, 5);// A[3], A[3]+A[4], A[3]+A[4]+A[5] 중에서 최대값 즉, 5
	int max = right_max_sum(A, 3, 4);// A[3], A[3]+A[4] 중에서 최대값 즉, 4
	//int max = right_max_sum(A, 5, 7);// 최대값 3
	printf("max value = %d\n", max);
}