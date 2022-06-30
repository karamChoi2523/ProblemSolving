#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void remove_duplicated_char(char* word)
{
	char key[81] = "";
	int i, j, k = 0;

	for (i = 0; i < strlen(word); i++) {
		for (j = 0; j < k; j++)
			if (word[i] == key[j])
				break;
		if (j == k)
			key[k++] = word[i];
	}
	for (i = 0; i < strlen(key); i++)
		word[i] = key[i];
	word[i] = '\0';
}

void makeCode(char code[], int distance, char* key)
{
	char alpha[27] = "";
	int i, j = 0, k = distance;

	for (i = 0; i < 26; i++)
		alpha[i] = 'A' + i;

	for (i = 0; i < strlen(key); i++)
		code[k++] = key[j++];

	for (i = 0; i < 26; i++) {
		if (k == 26)
			break;
		for (j = 0; j < strlen(key); j++)
			if (key[j] == alpha[i])
				break;
		if (j == strlen(key))
			code[k++] = alpha[i];
	}

	k = 0;
	for (i = 0; i < 26; i++) {
		for (j = distance; j < 26; j++)
			if (code[j] == alpha[i])
				break;
		if (j == 26)
			code[k++] = alpha[i];
	}
}

void printCode(char code[])
{
	char plaintext[81] = "";
	char encoded_text[81] = "";
	char alpha[27] = "";
	int i;
	int str_len;


	for (i = 0; i < 26; i++)
		alpha[i] = 'A' + i;

	printf("----------------------------------------------------------\n");
	printf("alphabet:\t");
	printf("%s\n", alpha);

	printf("encoded:\t");
	printf("%s\n", code);
	printf("----------------------------------------------------------\n");

	printf("Enter a sentence to encode:");
	fgets(plaintext, 80, stdin);
	fgets(plaintext, 80, stdin);


	printf("original sentence:\t");
	printf("%s", plaintext);

	str_len = strlen(plaintext);

	for (i = 0; i < str_len; i++) {
		if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
			int idx = plaintext[i] - 'A';
			encoded_text[i] = code[idx];
		}
		else {
			encoded_text[i] = plaintext[i];
		}
	}

	printf("encoded sentence:\t");
	printf("%s", encoded_text);
}

int main()
{
	char code[27];
	int distance;
	char key[30];


	printf("Enter a word to use for encoding(대문자로된 단어입력):");
	scanf("%s", key);

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	remove_duplicated_char(key);
	makeCode(code, distance, key);
	code[26] = '\0';
	printCode(code);

	return 0;
}