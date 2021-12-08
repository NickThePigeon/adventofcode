
#include <stdio.h>
#include <stdlib.h>

// #define NBR_I 5
// #define DAYS 18
// #define DAYS 80
#define NBR_I 300
#define DAYS 256

int	main(void)
{
	int nbr[NBR_I];
	long long top;
	long long oldtop;
	int *fishes;
	long long i,j;


	fishes = (int *)malloc(sizeof(int) * (9999999999));
	FILE	*ptr = fopen("file.txt","r");

    if (ptr == NULL)
    {
        printf("ptr:no such file.\n");
        return 0;
    }
	// printf("input --> ");
	for (i = 0; i < NBR_I; i++)
	{
		fscanf(ptr, "%d,", &nbr[i]);
	}
	
	for (i = 0; i < NBR_I; i++)
		fishes[i] = nbr[i];
	oldtop = NBR_I;
	top = oldtop;
	for (i = 0; i < DAYS; i++)
	{
		oldtop = top;
		for (j = 0; j < oldtop; j++)
		{
			if (fishes[j] == 0)
			{
				fishes[top] = 8;
				top++;
				fishes[j] = 6;
			}
			else
				fishes[j]--;
		}
		// for (j = 0; j < top; j++)
		// 	printf("%d", fishes[j]);   
		// printf("\n");
	}
	printf("nbr of fishes = %lld\n", top);
	free(fishes);
	return (0);
}
