#include <stdio.h>
#include <stdlib.h>

int		fill_matrix_vert(int matrix[1000][1000], int x1, int y1, int x2, int y2)
{
	int temp;

	if (x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	for (int i = 0; i < (y2 - y1); i++)
	{
		matrix[y1 + i][x1]++;
	}
	return (matrix);
}

// int		fill_matrix_horz(int matrix[1000][1000], int x, int y, int len)
// {

// }

int	main(void)
{
	int i,j;
	char c;
	int points[500][4];
	int matrix[1000][1000];

	FILE	*ptr = fopen("file.txt","r");
    if (ptr == NULL)
    {
        printf("ptr:no such file.\n");
        return 0;
    }
	for (i = 0; i < 500; i++)
		fscanf(ptr, "%d %*c %d %*c %*c %d %*c %d", &points[i][0], &points[i][1], &points[i][2], &points[i][3]);
	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < 1000; j++)
			matrix[i][j] = 0;
	}
	for (i = 0; i < 500; i++)
	{
		// if (points[i][0] == points[i][2])
		// {
		// 	fill_ma
		// }
		if (points[i][1] == points[i][3])
		{
			matrix = fill_matrix_vert(matrix, points[i][0], points[i][1], points[i][2], points[i][3]);
		}
	}
	for (i = 0; i < 1000; i++)
	{
		for (j = 0; j < 1000; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	return (0);
}