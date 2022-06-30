#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char alpha[27] = "";
	char encode[27] = "";
	char plaintext[81] = "";
	char encoded_text[81] = "";
	char decoded_text[81] = "";
	int dist;
	int i;
	int str_len;

	for (i = 0; i < 26; i++)
		alpha[i] = 'A' + i;

	printf("Enter a distance for encoding:");
	scanf("%d", &dist);

	for (i = 0; i < 26; i++) {
		encode[i] = alpha[i] + dist;

		if (encode[i] > 'Z')
			encode[i] = encode[i] - 26;
	}

	printf("----------------------------------------------------------\n");
	printf("alphabet:\t");
	printf("%s\n", alpha);

	printf("encoded:\t");
	printf("%s\n", encode);

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
			encoded_text[i] = encode[idx];
		}
		else {
			encoded_text[i] = plaintext[i];
		}
	}

	printf("encoded sentence:\t");
	printf("%s", encoded_text);

	for (i = 0; i < str_len; i++) {
		if (encoded_text[i] >= 'A' + dist && encoded_text[i] <= 'Z') {
			int idx = encoded_text[i] - encode[0];
			decoded_text[i] = alpha[idx];
		}
		else if (encoded_text[i] >= 'A' && encoded_text[i] < 'A' + dist) {
			int idx = 'Z' - encode[0] + encoded_text[i] - 'A' + 1;
			decoded_text[i] = alpha[idx];
		}
		else
			decoded_text[i] = encoded_text[i];
	}
	printf("decoded sentence:\t");
	printf("%s\n", decoded_text);
}