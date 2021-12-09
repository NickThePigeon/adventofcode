#include <stdio.h>
#include <stdlib.h>

#define NBR_I 5
#define DAYS 18
// #define DAYS 80
// #define NBR_I 300
// #define DAYS 256

int	main(void)
{
	int nbr[NBR_I];
	long long top;
	long long oldtop;
	int *fishes;
	long long i,j;
	long long zero,one,two,three,four,five,six,seven,eight;

	fishes = (int *)malloc(sizeof(int) * (300));
	FILE	*ptr = fopen("file_test.txt","r");

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
	for (i = 0; i < DAYS; i++)
	{
		one = two;
		two = three;
		three = four;
		four = five;
		five = six;
		seven = eight;
		eight = zero;
		six = zero;
		zero = one;
		printf("numbers = \n");
		printf("%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n", zero,one,two,three,four,five,six,seven,eight);
	}
	printf("nbr of fishes = %lld\n", zero + one + two + three + four + five + six + seven + eight);
	free(fishes);
	return (0);
}
