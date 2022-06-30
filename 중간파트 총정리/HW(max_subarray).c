#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int right_max_sum(int* A, int left, int right) 
{ 
	/*int sum = 0;
	int sum_max = A[left];
	int i;

	for (i = left; i <= right; i++) {
		sum = sum + A[i];
		if (sum_max < sum)
			sum_max = sum;
	}
	return sum_max;*/
	int sum = 0;
	int max = A[left];

	if (left >= right)
		return A[right];
	else {
		sum = A[left] + right_max_sum(A, left+1, right);
		if (sum > max)
			return sum;
	}
	return max;
}
int left_max_sum(int* A, int left, int right) 
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
int max_subarray(int* A, int left, int right)
{ 
	int v1, v2, v3;
	int mid;

	if (left >= right)
		return A[right];
	else {
		mid = (left + right) / 2;
		v1 = max_subarray(A, left, mid);
		v2 = max_subarray(A, mid+1, right);
		v3 = left_max_sum(A, left, mid) + right_max_sum(A, mid+1, right);

		if (v1 > v2 && v1 > v3)
			return v1;
		else if (v2 > v1 && v2 > v3)
			return v2;
		else
			return v3;
	}
}
int main()
{
	int lastIndex, max;
	int n;
	int* A;
	int i;

	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	lastIndex = n-1;
	max = max_subarray(A, 0, lastIndex);

	printf("%d\n", max);
}