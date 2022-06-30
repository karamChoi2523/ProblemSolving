#define _CRT_SUCRE_NO_WARNINGS
#include <stdio.h>

int left_max_sum(int A[], int left, int right)
{
	/*int sum = 0;
	int max_sum = A[right];
	int i;

	for (i = right; i >= left; i--) {
		sum += A[i];

		if (max_sum < sum)
			max_sum = sum;
	}
	return max_sum;*/
	int sum = 0;
	int max = A[right];

	if (left >= right)
		return A[left];
	else {
		sum = A[right] + left_max_sum(A, left, right - 1);
		if (sum > max)
			return sum;
	}
	return max;
}
int main() {
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int max = left_max_sum(A, 4, 6); // A[6], A[5]+A[6], A[4]+A[5]+A[6], 중에서 최대값, 즉 3
	//int max = left_max_sum(A, 0, 4); // 최대값 3
	//int max = left_max_sum(A, 4, 7);
	printf("max value = %d\n", max);
}