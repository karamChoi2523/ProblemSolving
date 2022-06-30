#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LEN  80

void add_substring(char* palindrome, char* s, int len, int i)
{
	int j;
	for (j = 0; j < i; j++)
		palindrome[len + j] = s[i - j - 1];
	palindrome[len + j] = 0x00;
}

int is_palindrome(char* s, int len)
{
	int i;

	for (i = 0; i < len / 2; i++)
		if (s[i] != s[len - i - 1])
			return 0;
	return 1;
}

void make_palindrome(char* s)
{
	char palindrome[MAX_LEN * 2];
	int len = strlen(s), i = 0;

	strcpy(palindrome, s);
	do {
		add_substring(palindrome, s, len, i);
	}while (!is_palindrome(palindrome, len + i++));

	printf("%s", palindrome);
}

int main()
{
	char s[MAX_LEN];
	scanf("%s", s);
	make_palindrome(s);
}