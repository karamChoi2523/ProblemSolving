#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
	0,0,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,0, 0, 0,-1,-1,-1, 0,-1,-1,
	-1,0,-1, 0, 0, 0, 0, 0,-1,-1,
	-1,0,-1, 0,-1,-1,-1,-1,-1,-1,
	-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
	-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
	-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
	-1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
	-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,
};
int flood_fill(int x, int y, int count)
{
	int num;

	if (screen[x][y] == 0)
	{
		screen[x][y] = ++count;

		if (y < WIDTH - 1)
			count = flood_fill(x, y + 1, count);
		if (x < HEIGHT - 1)
			count = flood_fill(x + 1, y, count);
		if (y > 0)
			count = flood_fill(x, y - 1, count);
		if (x > 0)
			count = flood_fill(x - 1, y, count);
		return count;
	}
	return count;
}
void draw_screen() {
	int i, j;

	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++)
			printf("%3d", screen[i][j]);
		printf("\n");
	}
}
int main()
{
	draw_screen();
	printf("\n");

	flood_fill(0, 0, 0);
	draw_screen();
}