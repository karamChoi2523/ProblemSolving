#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char* s)
{
	int i, j, k;
	int len, unit, min = 1000;
	char temp[1000] = "";
	int same = 1;
	char ch;
	char str1[500] = "", str2[500] = "";
	char numStr[1000];
	int sLen = strlen(s);

	for (unit = 1; unit <= sLen / 2; unit++) {
		len = 1;
		k = 0;

		strncpy(str1, s, unit);
		str1[unit] = '\0';

		for(i=unit;i<sLen;i+=unit)
		{
			strncpy(str2, &s[i], unit);
			str2[unit] = '\0';

			if (strncmp(str1, str2, unit) == 0)
				len++;
			else {
				if (len > 1) {
					sprintf(numStr, "%d", len);
					strcat(temp, numStr);
				}
				strcat(temp, str1);
				strcpy(str1, str2);
				len = 1;
			}
		}
		if (len > 1) {
			sprintf(numStr, "%d", len);
			strcat(temp, numStr);
		}
		strcat(temp, str1);
		
		printf("unit은 %d이고 길이는 %d %s\n", unit, strlen(temp), temp);
		if (min > strlen(temp))
			min = strlen(temp);

		memset(temp, 0x00, 1000);
	}
	return min;
}

int main()
{
	char s[1000];
	scanf("%s", s);
	printf("%d\n", solution(s));
}