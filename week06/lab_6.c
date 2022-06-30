#include <stdio.h>

int left_max_sum(int A[], int left, int right) {
    int i;
    int sum = 0;
    int sum_max = A[right];

    for(i=right;i>=left;i--){
        //sum = A[i]...A[right]
        sum = sum+A[i]; //end가 고정이니까!!(loop 필요x)
        if(sum_max < sum)
            sum_max = sum;
    }
    return sum_max;
}
int main() 
{
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    printf("max value = %d\n", left_max_sum(A,4,6));
    printf("max value = %d\n", left_max_sum(A,0,4));
    printf("max value = %d\n", left_max_sum(A,4,7));
}
