#include <stdio.h>
#include <stdlib.h>


int		check_bingo(int array[100][5][5])
{
	int i, j, k;

	for (i = 0; i < 100; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((array[i][j][0] == -1) && (array[i][j][1] == -1) && (array[i][j][2] == -1) && (array[i][j][3] == -1) && (array[i][j][4] == -1))
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						printf("%d ", array[i][j][k]);
					}
					printf("\n");
				}
				return (1);
			}
		}
		for (int j = 0; j < 5; j++)
		{
			if ((array[i][0][j] == -1) && (array[i][1][j] == -1) && (array[i][2][j] == -1) && (array[i][3][j] == -1) && (array[i][4][j] == -1))
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						printf("%d ", array[i][j][k]);
					}
					printf("\n");
				}
				return (1);
			}
		}
	}
	return (0);
}

int	main(void)
{
	int i,j,k,f = 0;
	int array[100][5][5];
	int balls[100];

	FILE 	*ball_ptr = fopen("input.txt", "r");
	FILE	*ptr = fopen("text.txt","r");

    if (ptr == NULL)
    {
        printf("ptr:no such file.\n");
        return 0;
    }
    if (ball_ptr == NULL)
    {
        printf("ball_ptr:no such file.\n");
        return 0;
    }

	for (i = 0; i < 100; i++)
	{
		fscanf(ball_ptr, "%d,", &balls[i]);
	}

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k < 5; k++)
			{
				fscanf(ptr, "%d", &array[i][j][k]);
			}
		}
	}
	for (f = 0; f < 100; f++)
	{
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 5; j++)
			{
				for (k = 0; k < 5; k++)
				{
					if (balls[f] == array[i][j][k])
					{
						array[i][j][k] = -1;
						if (check_bingo(array) == 1)
						{
							printf("last ball = %d\n", balls[f]);
							exit(0);
						}
					}
				}
			}
		}
	}
	return (0);
}