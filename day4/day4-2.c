#include <stdio.h>
#include <stdlib.h>


int		check_all_one(int *winners)
{
	for (int i = 0; i < 100; i++)
	{
		if (winners[i] == 0)
			return (0);
	}
	return (1);
}

int		check_bingo(int array[5][5])
{
	int i, j;


	for (int j = 0; j < 5; j++)
	{
		if ((array[j][0] == -1) && (array[j][1] == -1) && (array[j][2] == -1) && (array[j][3] == -1) && (array[j][4] == -1))
		{
			// for (int j = 0; j < 5; j++)
			// {
			// 	for (int k = 0; k < 5; k++)
			// 	{
			// 		printf("%d ", array[i][j][k]);
			// 	}
			// 	printf("\n");
			// }
			return (1);
		}
	}
	for (int j = 0; j < 5; j++)
	{
		if ((array[0][j] == -1) && (array[1][j] == -1) && (array[2][j] == -1) && (array[3][j] == -1) && (array[4][j] == -1))
		{
			// for (int j = 0; j < 5; j++)
			// {
			// 	for (int k = 0; k < 5; k++)
			// 	{
			// 		printf("%d ", array[i][j][k]);
			// 	}
			// 	printf("\n");
			// }
			return (1);
		}
	}
	return (0);
}


int	main(void)
{
	int i,j,k,f = 0;
	int array[100][5][5];
	int balls[100];
	int winners[100];

	FILE 	*ball_ptr = fopen("input.txt", "r");
	FILE	*ptr = fopen("text.txt","r");

	for (int i; i < 100; i++)
		winners[i] = 0;
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
						if (check_bingo(array[i]) == 1)
						{
							winners[i] = 1;
							if (check_all_one(winners) == 1)
							{
								for (int j = 0; j < 5; j++)
								{
									for (int k = 0; k < 5; k++)
									{
										printf("%d ", array[i][j][k]);
									}
									printf("\n");
								}
								printf("board = %d\n", i);
								printf("last ball = %d\n", balls[f]);

								exit(0);
							}
						}
					}
				}
			}
		}
	}
	return (0);
}