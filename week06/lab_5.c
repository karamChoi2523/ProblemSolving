#include <stdio.h>

int right_max_sum(int A[], int left, int right) {
    int i;
    int sum = 0;
    int sum_max = A[left];

    for(i=left;i<=right;i++){
        //sum = A[left]...A[i]
        sum = sum+A[i]; //start가 고정이니까!!(loop 필요x)
        if(sum_max < sum)
            sum_max = sum;
    }
    return sum_max;
}
int main() 
{
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //int max = right_max_sum(A, 3, 5);// A[3], A[3]+A[4], A[3]+A[4]+A[5] 중에서 최대값 즉, 5
    //int max = right_max_sum(A, 3, 4);// A[3], A[3]+A[4] 중에서 최대값 즉, 4
    //int max = right_max_sum(A, 5, 7);// 최대값 3
    printf("max value = %d\n", right_max_sum(A,3,5));
    printf("max value = %d\n", right_max_sum(A,3,4));
    printf("max value = %d\n", right_max_sum(A,5,7));
}
