#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LEVEL 5
#define MAX_WIDTH 70
int screen[MAX_LEVEL][MAX_WIDTH];
int count = 0;

void draw_tree(int row, int left, int right)
{
	int mid;

	if (right - left < 2)
		return;
	mid = (right + left) / 2;

	screen[row][mid] = ++count;
	draw_tree(row + 1, left, mid);
	draw_tree(row + 1, mid + 1, right);
}
void init(int s[][MAX_WIDTH])
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = 0;
}
void display(int s[][MAX_WIDTH], int width)
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++)
			if (s[i][j] == 0)
				printf(" -");
			else
				printf(" %d", s[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int width;

	init(screen);

	printf("Enter a width(<= 70) of a screen:");
	scanf("%d", &width);

	draw_tree(0, 0, width);

	display(screen, width);
}
