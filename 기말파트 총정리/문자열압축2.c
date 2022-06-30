#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char* s)
{
	int i=0, j = 0;
	int len = 1, unit;
	char temp[1000] = "";
	int same = 1;
	char str1[500] = "", str2[500] = "";
	char numStr[1000];
	int sLen = strlen(s);

	strncpy(str1, s, 2);
	str1[2] = '\0';

	i = 2;
	while (i < sLen) {
		s += 2;
		strncpy(str2, s, 2);
		if (strncmp(str1, str2, 2) == 0)
			len++;
		else {
			if (len > 1) {
				sprintf(numStr, "%d", len);	//string에 쓰겠다 : sprintf
				strcat(temp, numStr);
			}
			strcat(temp, str1);
			strcpy(str1, str2);
			len = 1;
		}
		i += 2;
	}

	if (len > 1) {
		sprintf(numStr, "%d", len);
		strcat(temp, numStr);
	}
	strcat(temp, str1);
	printf("%s\n", temp);
}

int main()
{
	char s[1000];
	scanf("%s", s);
	printf("%d\n", solution(s));
}