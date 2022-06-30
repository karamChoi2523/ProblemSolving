#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(char *items[], int n, int picked[], int m, int toPick)
{
    int i,lastIndex,smallest;
    int picked_index;

    if(toPick==0){
        for(i=0;i<m;i++){
            picked_index = picked[i];
            printf("%s ", items[picked_index]);
        }
        printf("\n");
        return;
    }

    lastIndex = m-toPick-1;

    for(i=0;i<n;i++){
        int j;
        int flag = 0;
        for(j=0;j<=lastIndex;j++)
            if(picked[j]==i) flag = 1;
        if(flag==1)
            continue;
        picked[lastIndex+1] = i;
        pick(items, n, picked, m, toPick-1);
    }
}
int main()
{
    char* items[] = {"공유","김수현","송중기","지성","현빈"};
	int n = 5;
	int picked[2];

	pick(items, n, picked, 2,2);
}