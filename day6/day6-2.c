#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	unsigned long long zero,one,two,three,four,five,six,seven,eight;

	fishes = (int *)malloc(sizeof(int) * (300));
	FILE	*ptr = fopen("file.txt","r");

    if (ptr == NULL)
    {
        printf("ptr:no such file.\n");
        return 0;
    }
	for (i = 0; i < NBR_I; i++)
	{
		fscanf(ptr, "%d,", &nbr[i]);
	}

	zero = 0;
	one = 0;
	two = 0;
	three = 0;
	four = 0;
	five = 0;
	six = 0;
	seven = 0;
	eight = 0;

	for (i = 0; i < NBR_I; i++)
	{
		if (nbr[i] == 0)
			zero++;
		else if (nbr[i] == 1)
			one++;
		else if (nbr[i] == 2)
			two++;
		else if (nbr[i] == 3)
			three++;
		else if (nbr[i] == 4)
			four++;
		else if (nbr[i] == 5)
			five++;
		else if (nbr[i] == 6)
			six++;
	}
	unsigned long long old_zero = 0;
	unsigned long long old_eight = 0;
	for (i = 0; i < DAYS; i++)
	{
		old_zero = zero;
		zero = one;
		one = two;
		two = three;
		three = four;
		four = five;
		five = six;
		six = seven;
		seven = eight;
		old_eight = eight;
		eight = old_zero;
		six += old_zero;
	}
	printf("nbr of fishes = %llu\n", (zero + one +two+three+four+five+six+seven+eight));
	free(fishes);
	return (0);
}
