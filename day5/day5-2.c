#include <stdio.h>
#include <stdlib.h>

// #define MATRIX_Y 1000
// #define MATRIX_X 1000
// #define POINTS_Y 500

#define MATRIX_Y 1000
#define MATRIX_X 1000
#define POINTS_Y 500

int matrix[MATRIX_Y][MATRIX_X];

int		fill_matrix_diagno(int x1, int y1, int x2, int y2)
{
	int temp;

	if (y1 > y2)
	{
		temp = y1;
		y1 = y2;
		y2 = temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (x1 < x2)
	{
		for (int i = 0; i <= (y2 - y1); i++)
		{
			matrix[y1 + i][x1 + i] += 1;
		}
	}
	if (x1 > x2)
	{
		for (int i = 0; i <= (y2 - y1); i++)
		{
			matrix[y1 + i][x1 - i] += 1;
		}
	}
	return (0);
}

int		fill_matrix_vert(int x1, int y1, int x2, int y2)
{
	int temp;

	if (y1 > y2)
	{
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	for (int i = 0; i <= (y2 - y1); i++)
	{
		matrix[y1 + i][x1] += 1;
	}
	return (0);
}

int		fill_matrix_horz(int x1, int y1, int x2, int y2)
{
	int temp;

	if (x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	for (int i = 0; i <= (x2 - x1); i++)
	{
		matrix[y1][x1 + i] += 1;
	}
	return (0);	
}

int	main(void)
{
	int i,j;
	char c;
	int points[POINTS_Y][4];

	FILE	*ptr = fopen("file.txt","r");
    if (ptr == NULL)
    {
        printf("ptr:no such file.\n");
        return 0;
    }
	for (i = 0; i < POINTS_Y; i++)
		fscanf(ptr, "%d %*c %d %*c %*c %d %*c %d", &points[i][0], &points[i][1], &points[i][2], &points[i][3]);
	for (i = 0; i < MATRIX_Y; i++)
	{
		for (j = 0; j < MATRIX_X; j++)
			matrix[i][j] = 0;
	}
	for (i = 0; i < POINTS_Y; i++)
	{
		if (points[i][0] == points[i][2])
		{
			fill_matrix_vert(points[i][0], points[i][1], points[i][2], points[i][3]);
		}
		else if (points[i][1] == points[i][3])
		{
			fill_matrix_horz(points[i][0], points[i][1], points[i][2], points[i][3]);
		}
		else
		{
			fill_matrix_diagno(points[i][0], points[i][1], points[i][2], points[i][3]);
		}
	}
	int count = 0;
	for (i = 0; i < MATRIX_Y; i++)
	{
		for (j = 0; j < MATRIX_X; j++)
		{
			// printf("%d", matrix[i][j]);
			if (matrix[i][j] > 1)
				count++;
		}
		// printf("\n");
	}
	printf("answer = %d\n", count);
	return (0);
}