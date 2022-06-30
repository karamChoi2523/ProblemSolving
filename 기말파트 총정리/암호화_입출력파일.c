#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void makeCode(char alpha[], char code[], int distance, char* key)
{
	int i, j = 0, k = distance;

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


void printCode(char alpha[], char code[])
{
	printf("----------------------------------------------------------\n");
	printf("alphabet:\t");
	printf("%s\n", alpha);

	printf("encoded:\t");
	printf("%s\n", code);
	printf("----------------------------------------------------------\n");
}

int main()
{
	char key[30];
	char encode[27] = "";
	char alpha[27] = "";

	char plaintext[81] = "";
	char encoded_text[81] = "";

	char input[81] = "";
	char output[81] = "";
	FILE* fp1;
	FILE* fp2;

	int dist;
	int i;
	int str_len;

	for (i = 0; i < 26; i++)
		alpha[i] = 'A' + i;

	printf("Enter a word to use for encoding(대문자로된 단어입력):");
	scanf("%s", key);

	printf("Enter a distance for encoding:");
	scanf("%d", &dist);

	remove_duplicated_char(key);
	makeCode(alpha, encode, dist, key);
	printCode(alpha, encode);

	printf("입력파일:");
	scanf("%s", input);
	printf("출력파일:");
	scanf("%s", output);

	if ((fp1 = fopen(input, "rt")) == NULL) {
		printf("파일오픈에러");
		exit(1);
	}
	if ((fp2 = fopen(output, "wt")) == NULL) {
		printf("파일오픈에러2");
		exit(1);
	}

	while (fgets(plaintext, sizeof(plaintext), fp1) != NULL) {
		str_len = sizeof(plaintext);

		for (i = 0; i < str_len; i++) {
			if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
				int idx = plaintext[i] - 'A';
				encoded_text[i] = encode[idx];
			}
			else {
				encoded_text[i] = plaintext[i];
			}
		}
		fputs(encoded_text, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}